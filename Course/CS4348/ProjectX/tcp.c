#include "tcp.h"

int main(int argc, char *argv[])
{
    // Check the usage parameters count
    if (argc < 3)
    {
        fprintf(stderr, "usage: %s <no. of ID(s)> <ID> <...List of IP address(s)>\n", argv[0]);
    }

    // Parse char[] to int
    long int arg[2];
    for (int i = 0; i < 2; i++)
    {
        arg[i] = strtol(argv[i + 1], NULL, 10);
    }

    int num_of_clients = arg[0];
    int ID = arg[1];

    // Check if sufficient list of IP addresses is passed or not
    if (num_of_clients - 1 != argc - 3)
    {
        printf("Expected %ld got %d <...List of IP address(s) passed\n", arg[0] - 1, argc - 3);
    }

    char client_IP[num_of_clients][11];
    bzero(&client_IP, sizeof(client_IP));

    for(int i = 0; i < num_of_clients; i++)
    {
        if(i == ID - 1)
        {
            strncpy(client_IP[i], "x", 2);
            continue;
        }
        strncpy(client_IP[i], argv[i+3], sizeof(client_IP[i]));
    }

    // Listen to the received messages: Start the server and let the server listen to the defined port number
    server_accept_thread();
    client_send_thread(num_of_clients, ID, client_IP);

    return 0;
}

void server_accept_thread()
{
    char recvline[256];

    // create the server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define the server address
    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);

    //bind the socket to our specified IP and port
    bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));

    listen(server_socket, 5);

    while(1){
        int client_socket;
        client_socket = accept(server_socket, NULL, NULL);

        // receive the message
        // bzero(&server_message, sizeof(server_message));
        // recv(client_socket, server_message, sizeof(server_message), 0);

        bzero(&recvline, sizeof(recvline));
        int n;

        while( (n = read(client_socket, recvline, 256 - 1) ) > 0)
        {
            printf("%s", recvline);

            if(recvline[n-1] == '\n')
            {
                break;
            }
            bzero(&recvline, sizeof(recvline));
        }
    }
    
    // close the socket
    close(server_socket);
}

void client_send_thread(int num_of_clients, int ID, char client_IP[][11])
{
    char message[256];
    int m;
    while(1)
    {
        printf("Please enter the message: ");
        bzero(&message, sizeof(message));
        scanf("%s", message);

        printf("Please enter the machine to send: ");
        scanf("%d",&m);

        // create the server socket
        int network_socket;
        network_socket = socket(AF_INET, SOCK_STREAM, 0);

        // define the server address
        struct sockaddr_in server_address;
        bzero(&server_address, sizeof(server_address));
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(SERVER_PORT);
        
        if(inet_pton(AF_INET, client_IP[m-1], &server_address.sin_addr) <= 0)
            printf("Error on inet");
        
        int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
        // check for error with the connection
        if(connection_status == -1)
            printf("There was an error making a connection to the remote socket \n");

        write(network_socket, message, strlen(message));

        close(network_socket);
    }
}