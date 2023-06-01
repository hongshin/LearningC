#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 

#include <sys/socket.h> 
#include <sys/types.h>
#include <netinet/in.h> 
#include <netinet/tcp.h>
#include <linux/socket.h>


int listen_at_port (int portnum) 
{
	int sock_fd = socket(AF_INET /*IPv4*/, SOCK_STREAM /*TCP*/, 0 /*IP*/) ;
	if (sock_fd == 0)  { 
		perror("socket failed : "); 
		exit(EXIT_FAILURE); 
	}
	int opt = 2 ;
	if (setsockopt(sock_fd, SOL_TCP, TCP_NODELAY, &opt, sizeof(opt)) != 0) {
		fprintf(stderr, "fail at setsockopt\n") ;
		exit(EXIT_FAILURE) ;
	}

	struct sockaddr_in address ; 
	bzero(&address, sizeof(address)) ; 	
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY /* localhost */ ; 
	address.sin_port = htons(portnum); 

	if (bind(sock_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		perror("bind failed: "); 
		exit(EXIT_FAILURE); 
	} 

	if (listen(sock_fd, 16 /* the size of waiting queue*/) < 0) { 
		perror("listen failed : "); 
		exit(EXIT_FAILURE); 
	} 

	int addrlen = sizeof(address); 
	int conn_fd = accept(sock_fd, (struct sockaddr *) &address, (socklen_t*)&addrlen) ;
	if (conn_fd < 0) {
		perror("accept failed: "); 
		exit(EXIT_FAILURE); 
	}
	return conn_fd ;
}

void chat (int conn_fd) 
{
	char buf[256] ;

	do {
		int s ;
		
		while ( (s = recv(conn_fd, buf, 255, 0)) == 0 ) ;
		if (s == -1)
			break ;

		buf[s] = '\0' ;
		printf(">%s\n", buf) ;

		
		fgets(buf, 256, stdin) ;
		buf[strlen(buf) - 1] = '\0' ;
		if (strcmp(buf, "quit()") == 0)
			break ;

		send(conn_fd, buf, strlen(buf), 0) ;

	} while (strcmp(buf, "quit()") != 0) ;
}

int main (int argc, char const **argv) 
{	
	if (argc != 2) {
		fprintf(stderr, "Wrong number of arguments") ;
		exit(EXIT_FAILURE) ;
	}

	int conn_fd = listen_at_port(atoi(argv[1])) ;

	chat(conn_fd) ;

	shutdown(conn_fd, SHUT_RDWR) ;
} 


