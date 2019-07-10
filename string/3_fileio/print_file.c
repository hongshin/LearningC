#include <stdio.h>
#include <stdlib.h>


int
main(int argc, char ** args) 
{
	int i = 1 ;

	if (argc != 2) {
		fprintf(stderr, "Invalid argument\n") ;
		exit(1) ;
	}

	FILE * fp ;
	fp = fopen(args[i], "r") ;
	if (fp == 0x0) {
		fprintf(stderr, "Fail to open %s\n", args[i]) ;
		exit(1) ; 
	}

	while (!feof(fp)) {
		char * line = 0x0 ;
		size_t line_len = 0 ;
		int nread = 0 ;
		nread = getline(&line, &line_len, fp) ;
		if (nread > 0) 
			printf("%s", line) ;
		free(line) ;
	}

}
