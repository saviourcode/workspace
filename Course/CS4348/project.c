/* POSIX C API */
#include <fcntl.h> // open, close files
#include <unistd.h> // read, write, fork APIs
#include <sys/types.h> // ssize_t
#include <dirent.h> // opendir and readdir

/* C Standard library */
#include <string.h> // string C library functions
#include <stdlib.h>
#include <errno.h>

#define STDIN 0
#define STDOUT 1
#define STDERR 3

#define BUFFER_SIZE 100

void writeFd(int fd, const char* strWrite)
{
    size_t nbytes; // Store number of bytes of string
    ssize_t retnbytes; // Store the value returned from read and write

    nbytes = strlen(strWrite);
    retnbytes = write(fd, strWrite, nbytes);

    if(retnbytes <= 0)
    {
        char *str = "Write failed!";
        nbytes = strlen(str);
        (void)write(STDERR, str, nbytes);

        _exit(EXIT_FAILURE);
    }
}

void fileWriter(const char* fileName, int fd)
{
    int fileDesc;
    fi
}

void dirWriter(const char* dirName, int fd)
{
    DIR *dirp;
    struct dirent *dp;

    if((dirp = opendir(dirName)) == NULL) {
        writeFd(STDOUT, "Opendir Failed\n");
        _exit(EXIT_FAILURE);
    }

    do {
        errno = 0;
        if((dp = readdir(dirp)) != NULL){
            if(strcmp(".", dp->d_name) != 0 && strcmp("..", dp->d_name) != 0)
            {
                writeFd(fd, dp->d_name);
                writeFd(fd, "\n");
            }
        }
    }while(dp != NULL);

    if(errno != 0)
    {
        writeFd(STDOUT, "Readdir Failed\n");
        _exit(EXIT_FAILURE);
    }
}

int main()
{
    dirWriter("./dir1", STDOUT);

    return 0;
}