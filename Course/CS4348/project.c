/* POSIX C API */
#include <fcntl.h>     // open, close files
#include <unistd.h>    // read, write, fork APIs
#include <sys/types.h> // ssize_t
#include <sys/wait.h> // Wait for child process to terminate
#include <dirent.h>    // opendir and readdir

/* C Standard library */
#include <string.h> // string C library functions
#include <stdlib.h>
#include <errno.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 3

#define BUFFER_SIZE 100
#define PATH_NAME 20
#define NUM_CHILDS 2

void writeFd(int fd, const char *strWrite)
{
    size_t nbytes;     // Store number of bytes of string
    ssize_t retnbytes; // Store the value returned from read and write

    nbytes = strlen(strWrite);
    retnbytes = write(fd, strWrite, nbytes);

    if (retnbytes <= 0)
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

    if (retnbytes <= 0)
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
        writeFd(STDOUT, "Cannot open file ");
        writeFd(STDOUT, fileName);
        writeFd(STDOUT, "\n");
        _exit(EXIT_FAILURE);
    }

    readFd(fileDesc, buff, BUFFER_SIZE);
    writeFd(fd, buff);
    writeFd(fd, "EOF\n");
}

void dirWriter(const char *dirName, int fd)
{
    DIR *dirp;
    struct dirent *dp;

    if ((dirp = opendir(dirName)) == NULL)
    {
        writeFd(STDOUT, "opendir() Failed\n");
        _exit(EXIT_FAILURE);
    }

    do
    {
        char fileName[PATH_NAME] = {0};
        strcpy(fileName, dirName);

        errno = 0;
        if ((dp = readdir(dirp)) != NULL)
        {
            if (strcmp(".", dp->d_name) != 0 && strcmp("..", dp->d_name) != 0)
            {
                writeFd(fd, dp->d_name);
                writeFd(fd, "\n");
                strcat(fileName, dp->d_name);
                fileWriter(fileName, fd);
            }
        }
    } while (dp != NULL);

    if (errno != 0)
    {
        writeFd(STDOUT, "readdir() Failed\n");
        _exit(EXIT_FAILURE);
    }
}

int main()
{
    char *dirNames[NUM_CHILDS] = {"./dir1/", "./dir2/"};

    // Make pipes
    int fildesc[NUM_CHILDS][2];
    int status;

    for(size_t i = 0; i < NUM_CHILDS; i++)
    {
        if((status = pipe(fildesc[i])) == -1)
        {
            writeFd(STDOUT, "pipe() Failed!\n");
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
            writeFd(STDOUT, "fork() Failed!\n");
            exit(EXIT_FAILURE);
        }
        // child process
        else if(pidChild[i] == 0){
            // do something with pipes
            writeFd(STDOUT, "I am a child!\n");
            dirWriter(dirNames[i], STDOUT);
            exit(EXIT_SUCCESS);
        }
    }

    // Wait for Child Processes to complete
    for(size_t i = 0; i < NUM_CHILDS; i++)
    {
        if(wait(NULL) == -1)
        {
            writeFd(STDOUT, "wait() Failed!\n");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}