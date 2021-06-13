/* POSIX C API */
#include <fcntl.h> // open, close files
#include <unistd.h> // read, write, fork APIs
#include <sys/types.h> // ssize_t

/* C Standard library */
#include <string.h> // string C library functions
#include <stdio.h> // debugging

#define STDIN 0
#define STDOUT 1
#define STDERR 3

int main()
{
    fork();

    printf("So You See!\n");
}