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

enum {STDIN = 0, STDOUT = 1, STDERR = 2};
enum {READ_END = 0, WRITE_END = 1};

#define PATH_NAME 20
#define NUM_CHILDS 2

#define FILENAME 20
#define LENGTH 10
#define BUFFER_SIZE 100

void writeFd(int fd, const char *strWrite)
{
    size_t nbytes;     // Store number of bytes of string
    ssize_t retnbytes; // Store the value returned from read and write

    nbytes = strlen(strWrite);
    retnbytes = write(fd, strWrite, nbytes);

    if (retnbytes < 0)
    {
        char *str = "write() Failed!\n";
        nbytes = strlen(str);
        (void)write(STDERR, str, nbytes);

        _exit(EXIT_FAILURE);
    }
}

void writeFdPipe(int fd, const char *strWrite, size_t nbytes)
{
    ssize_t retnbytes; // Store the value returned from read and write

    retnbytes = write(fd, strWrite, nbytes);

    if(retnbytes < 0)
    {
        char *str = "write() Failed!\n";
        nbytes = strlen(str);
        (void)write(STDERR, str, nbytes);

        _exit(EXIT_FAILURE); 
    }
}

void readFd(int fd, char *buff, size_t nbytes)
{
    ssize_t retnbytes;

    retnbytes = read(fd, buff, nbytes);

    if (retnbytes < 0)
    {
        char *str = "read() Failed!\n";
        nbytes = strlen(str);
        (void)write(STDERR, str, nbytes);

        _exit(EXIT_FAILURE);
    }
}

void fileWriter(const char *fileName, int fd)
{
    char buff[BUFFER_SIZE] = {0}; // Critical to zero out or else buffer contains random values

    int fileDesc;
    if ((fileDesc = open(fileName, O_RDONLY, NULL)) == -1)
    {
        char strWrite[40];
        snprintf(strWrite, 40, "cannot open file: \"%s\"\n",fileName);
        writeFd(STDERR, strWrite);
        _exit(EXIT_FAILURE);
    }

    readFd(fileDesc, buff, BUFFER_SIZE);

    size_t nbytes = strlen(buff);
    char size[LENGTH];
    snprintf(size, 10, "%u\n", nbytes);

    writeFdPipe(fd, size, LENGTH);
    writeFdPipe(fd, buff, BUFFER_SIZE);
}

void dirWriter(const char *dirName, int fd)
{
    DIR *dirp;
    struct dirent *dp;

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
        if ((dp = readdir(dirp)) != NULL)
        {
            if (strcmp(".", dp->d_name) != 0 && strcmp("..", dp->d_name) != 0)
            {
                char fileName[20] = {0};
                strcat(fileName, dp->d_name);
                strcat(fileName, "\n");
                writeFdPipe(fd, fileName, sizeof(fileName));
                strcat(fileLocation, dp->d_name);
                fileWriter(fileLocation, fd);
            }
        }
    } while (dp != NULL);

    if (errno != 0)
    {
        writeFd(STDERR, "readdir() Failed\n");
        _exit(EXIT_FAILURE);
    }
}

void dirReader(const char *dirName, int fd)
{
    char fileName[20]
}

int main()
{
    /* Dummy files */
    int fd[NUM_CHILDS];
    fd[0] = open("./proc1.txt", O_RDWR, NULL);
    fd[1] = open("./proc2.txt", O_RDWR, NULL);

    char *dirNames[NUM_CHILDS] = {"./dir1/", "./dir2/"};

    // Make pipes
    int fildesc[NUM_CHILDS][2];
    int status;

    for(size_t i = 0; i < NUM_CHILDS; i++)
    {
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

        // error occured
        if(pidChild[i] < 0) { 
            writeFd(STDERR, "fork() Failed!\n");
            exit(EXIT_FAILURE);
        }
        // child process
        else if(pidChild[i] == 0){
            // do something with pipes
            writeFd(STDERR, "I am a child!\n");
            close(fildesc[i][READ_END]);
            close(fildesc[1-i][WRITE_END]);

            dirWriter(dirNames[i], fd[i]);

            dirWriter(dirNames[i], fildesc[i][WRITE_END]);
            close(fildesc[i][WRITE_END]);

            dirReader(dirNames[i], fildesc[1-i][READ_END]);
            close(fildesc[i-1][READ_END]);

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
        if(wait(NULL) == -1)
        {
            writeFd(STDERR, "wait() Failed!\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}