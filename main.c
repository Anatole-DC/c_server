#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_LENGTH 256

/**
  * Exit the program and print the error message.
  * @param const char* error_message : The message to print
  * @return void
*/
void error(const char* error_message){
	perror(error_message);
	exit(1);
}

int main(int argc, char** argv) {
	printf("Hello World !\n");

	int sockfd, newsockfd, portno;
	socklen_t clilen;

	char BUFFER[BUFFER_LENGTH];

	struct sockaddr_in serv_addr, cli_addr;

	int n;

	// Check if the port number was provided
	if (argc < 2) {
		error("ERROR: No Port number was provided.\n");
	}

	// Create a socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		error("ERROR: An error occured while creating the socket.\n");
	}

	// Clear address structure
	bzero((char*) &serv_addr, sizeof(serv_addr));

	portno = atoi(argv[1]);

	serv_addr.sin_addr.s_addr = INADDR_ANY;

	serv_addr.sin_port = htons(portno);

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		error("ERROR: an error occured while binding the address to the port.\n");
	}

	listen(sockfd, 5);

	clilen = sizeof(cli_addr);

	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0) {
		error("ERROR: An error occured while accepting the request.\n");
	}

	printf("SERVER: got connection from %s port %d.\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

	send(newsockfd, "Hello World !\n", 13, 0);

	bzero(BUFFER, BUFFER_LENGTH);

	n = read(newsockfd, BUFFER, 255);

	if (n<0) error("ERROR: An error occured while reading the socket.\n");

	printf("Here is the message :\n\t %s\n", BUFFER);

	close(newsockfd);
	close(sockfd);

	return 0;
}
