#ifndef _TCP_H_
#define _TCP_H_

#include <stdio.h>   //STD I/O handling
#include <stdlib.h>  //Many Useful functions
#include <string.h>  //bzero: fill zeros to a location
#include <unistd.h>  //close: Close the file descriptor
#include <pthread.h> //Create the threads to handle client and server

#include <sys/types.h>  //Various ID types for the threading process
#include <sys/socket.h> //Socket Functions: socket, connect, bind, listen, send, recv and accept
#include <netinet/in.h> //sockaddr_in: Structure to hold the address of the destination
#include <arpa/inet.h>  //inet_pton: Convert Presentation IP address to Network Address

#define SERVER_PORT 9002
#define BUFSIZE 4096

void server_accept_thread();
void client_send_thread(int, int, char[][11]);

#endif