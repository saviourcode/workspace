/* POSIX C API */
#include <sys/types.h> // ssize_t type
#include <unistd.h>    // read and write API
#include <fcntl.h>     // open and close API

/* C Standard library */
#include <string.h> // string C library functions
#include <stdio.h>  // debugging

#define STDIN 0
#define STDOUT 1
#define STDERR 3

int main()
{
    /* Take input from the user */

    size_t nbytes;     // Store number of bytes of string
    ssize_t retnbytes; // Store the value returned from read and write

    char strwrite[30];
    strcpy(strwrite, "Source File: ");
    nbytes = strlen(strwrite);

    retnbytes = write(STDOUT, strwrite, nbytes);
    if (retnbytes <= 0)
    {
        strcpy(strwrite, "write failed on stdout");
        nbytes = strlen(strwrite);

        write(STDERR, strwrite, nbytes);
    }

    char inputFileName[100];
    nbytes = sizeof(inputFileName);

    retnbytes = read(STDIN, inputFileName, nbytes);
    if (retnbytes <= 0)
    {
        strcpy(strwrite, "read failed on stdin");
        nbytes = strlen(strwrite);

        write(STDERR, strwrite, nbytes);
    }

    // Get rid of newline
    nbytes = strlen(inputFileName);
    inputFileName[nbytes - 1] = '\0';

    strcpy(strwrite, "Destination File: ");
    nbytes = strlen(strwrite);

    retnbytes = write(STDOUT, strwrite, nbytes);
    if (retnbytes <= 0)
    {
        strcpy(strwrite, "write failed on stdout");
        nbytes = strlen(strwrite);

        write(STDERR, strwrite, nbytes);
    }

    char outputFileName[100];
    nbytes = sizeof(outputFileName);

    retnbytes = read(STDIN, outputFileName, nbytes);
    if (retnbytes <= 0)
    {
        strcpy(strwrite, "read failed on stdin");
        nbytes = strlen(strwrite);

        write(STDERR, strwrite, nbytes);
    }

    // Get rid of newline
    nbytes = strlen(outputFileName);
    outputFileName[nbytes - 1] = '\0';

    /* Open the input and output file */
    int fd_input, fd_output;

    fd_input = open(inputFileName, O_RDONLY, NULL);
    if (fd_input == -1)
    {
    }
}
