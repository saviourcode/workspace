/* POSIX C API */
#include <fcntl.h>     // open, close files
#include <unistd.h>    // read, write, fork APIs
#include <sys/types.h> // ssize_t
#include <sys/wait.h> // Wait for child process to terminate
#include <dirent.h>    // opendir and readdir

/* C Standard library */
#include <string.h> // string C library functions
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// Enumeration to hold STDIN, STDOUT, STDERR
enum {STDIN = 0, STDOUT = 1, STDERR = 2};
// Enumeration to hold READ_END, WRITE_END
enum {READ_END = 0, WRITE_END = 1};

// Macros to store total PATH and total number of processes
#define PATH_NAME 30
#define NUM_CHILDS 2

// Macros to store file parameters
#define FILENAME 20
#define LENGTH 10
#define BUFFER_SIZE 1024*1024 //1MB

/* Function Description:
 * Write the given char[] to the specified file descriptor.
 * If any error occurs then stop the program.
 */
void writeFd(int fd, const char *strWrite)
{
    size_t nbytes;     // Store number of bytes of string
    ssize_t retnbytes; // Store the value returned from read and write

    nbytes = strlen(strWrite);
    retnbytes = write(fd, strWrite, nbytes);


    // Check for error
    if (retnbytes < 0)
    {
        char *str = "write() Failed!\n";
        nbytes = strlen(str);
        (void)write(STDERR, str, nbytes);

        _exit(EXIT_FAILURE);
    }
}

/* Function Description:
 * Write the given char[] to the specified file descriptor, and also pass the number of bytes to write
 * If any error occurs then stop the program.
 */
void writeFdBytes(int fd, const char *strWrite, size_t nbytes)
{
    ssize_t retnbytes; // Store the value returned from read and write

    retnbytes = write(fd, strWrite, nbytes);

    // Check for error
    if(retnbytes < 0)
    {
        char *str = "write() Failed!\n";
        nbytes = strlen(str);
        (void)write(STDERR, str, nbytes);

        _exit(EXIT_FAILURE); 
    }
}

/* Function Description:
 * Read characters into the given char[] from the specified file descriptor, read only the specified number of bytes
 * If any error occurs then stop the program.
 */
ssize_t readFd(int fd, char *buff, size_t nbytes)
{
    ssize_t retnbytes;

    retnbytes = read(fd, buff, nbytes);

    // Check for error
    if (retnbytes < 0)
    {
        char *str = "read() Failed!\n";
        nbytes = strlen(str);
        (void)write(STDERR, str, nbytes);

        _exit(EXIT_FAILURE);
    }

    return retnbytes;
}

/* Function Description:
 * Open and fetch the contents of file and write it to the given file descriptor
 * If any error occurs then stop the program.
 */
void fileWriter(const char *fileName, int fd)
{
    char buff[BUFFER_SIZE] = {0}; // Critical to zero out or else buffer contains random values

    int fileDesc;

    // Check for error
    if ((fileDesc = open(fileName, O_RDONLY, NULL)) == -1)
    {
        char strWrite[40];
        snprintf(strWrite, 40, "cannot open file: \"%s\"\n",fileName);
        writeFd(STDERR, strWrite);
        _exit(EXIT_FAILURE);
    }

    // Read the contents of file, max till BUFFER_SIZE
    readFd(fileDesc, buff, BUFFER_SIZE);

    // Find the size of the file
    size_t nbytes = strlen(buff);

    char size[LENGTH];
    // Convert size to long int
    snprintf(size, 10, "%lu\n", nbytes);

    // Write the size of the file to the file descriptor
    writeFdBytes(fd, size, LENGTH);

    // If file size is not equal to zero then write the contents of file to file descriptor
    if(nbytes!=0)
        writeFdBytes(fd, buff, BUFFER_SIZE);
}

/* Function Description:
 * Open and read the directory listings of the given directory. Also write the names of files to the file descriptor
 * If any error occurs then stop the program.
 */
void dirWriter(const char *dirName, int fd)
{
    DIR *dirp;
    struct dirent *dp;

    // Check for error
    if ((dirp = opendir(dirName)) == NULL)
    {
        writeFd(STDERR, "opendir() Failed\n");
        _exit(EXIT_FAILURE);
    }

    do
    {
        char fileLocation[PATH_NAME] = {0};
        strcpy(fileLocation, dirName);

        errno = 0;

        // Read the file name from the directory
        if ((dp = readdir(dirp)) != NULL)
        {
            // Ignore file names of "." and ".."
            if (strcmp(".", dp->d_name) != 0 && strcmp("..", dp->d_name) != 0)
            {
                char fileName[FILENAME] = {0};
                strcat(fileName, dp->d_name);

                // Write the filename to the file descriptor
                writeFdBytes(fd, fileName, sizeof(fileName));

                strcat(fileLocation, dp->d_name);
                fileWriter(fileLocation, fd);
            }
        }
    } while (dp != NULL);

    // Check for error
    if (errno != 0)
    {
        writeFd(STDERR, "readdir() Failed\n");
        _exit(EXIT_FAILURE);
    }
}

/* Function Description:
 * Read the contents from the sibling's pipe and then create new files with the respective contents
 * If any error occurs then stop the program.
 */
void dirReader(const char *dirName, int fd)
{
    char fileName[FILENAME] = {0};
    char size[LENGTH] = {0};
    char buffer[BUFFER_SIZE] = {0};
    size_t retSize;

    // Check if there is any files present in the file descriptor
    while(readFd(fd, fileName, FILENAME))
    {
        char fileDirPath[PATH_NAME] = {0};
        strcat(fileDirPath,dirName);
        strcat(fileDirPath,fileName);

        // Read the size of files
        readFd(fd, size, LENGTH);

        // Convert back the size of file to long int
        retSize = strtol(size,NULL,10);
        if(retSize== 0)
            continue;

        // Read the contents of file to the buffer, max till BUFFER_SIZE
        readFd(fd, buffer, BUFFER_SIZE);

        // Check if the file name with same name is present in the directory, if yes then don't alter it
        if(access(fileDirPath, F_OK) == 0)
                writeFd(STDOUT,"File already exists! Won't overwrite\n");
        else
        {
            // Create a new file and write the contents to it
            int fdwr = open(fileDirPath, O_WRONLY | O_TRUNC | O_CREAT | O_EXCL, 0644);
            write(fdwr,buffer,retSize);
            close(fdwr);
        }
    }
}

/* Function Description:
 * Creates two ordinary pipe and then forks two child processes with their respective directory to handle.
 * The two child processes, first closes the unused end of the pipe, and then start writing the whole directory 
 * to the respective write end of the pipe. Once writing is done, then close the write end of the self pipe and start
 * reading from the sibling's pipe.
 * Parent closes all the pipes and waits for the child process to complete.
 * If any error occurs then stop the program.
 */
int main()
{
    char dirNames[NUM_CHILDS][PATH_NAME];

    for(size_t i = 0; i < NUM_CHILDS; i++)
    {
        printf("Please enter the directory of child %ld : ", i);
        scanf("%s", dirNames[i]);
    }

    // Make pipes
    int fildesc[NUM_CHILDS][2];
    int status;

    for(size_t i = 0; i < NUM_CHILDS; i++)
    {
        // Check for error
        if((status = pipe(fildesc[i])) == -1)
        {
            writeFd(STDERR, "pipe() Failed!\n");
            exit(EXIT_FAILURE);
        }
    }
    
    // Fork childs and do something
    pid_t pidChild[NUM_CHILDS];

    for(size_t i = 0; i < NUM_CHILDS; i++)
    {
        // fork a child process
        pidChild[i] = fork();

        // Check for error
        if(pidChild[i] < 0) { 
            writeFd(STDERR, "fork() Failed!\n");
            exit(EXIT_FAILURE);
        }
        // child process
        else if(pidChild[i] == 0){
            // Close the Read End self pipe
            close(fildesc[i][READ_END]);
            // Close the Write End of sibling's pipe
            close(fildesc[1-i][WRITE_END]);

            // Start writing the contents of directory to the pipe
            dirWriter(dirNames[i], fildesc[i][WRITE_END]);
            // Close the Write End of self pipe
            close(fildesc[i][WRITE_END]);

            // Start reading the contents of sibling's pipe
            dirReader(dirNames[i], fildesc[1-i][READ_END]);
            // Close the Read End of sibling's pipe
            close(fildesc[i-1][READ_END]);

            // destroy the child process
            exit(EXIT_SUCCESS);
        }
    }

    // Close the ends of pipe for parent
    for(size_t i = 0; i < NUM_CHILDS; i++)
    {
        close(fildesc[i][READ_END]);
        close(fildesc[i][WRITE_END]);
    }

    // Wait for Child Processes to complete
    for(size_t i = 0; i < NUM_CHILDS; i++)
    {
        // Check for error
        if(wait(NULL) == -1)
        {
            writeFd(STDERR, "wait() Failed!\n");
            exit(EXIT_FAILURE);
        }
    }

    // Return 0 on Success
    return 0;
}