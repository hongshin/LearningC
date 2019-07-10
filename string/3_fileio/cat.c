#include <stdio.h>
#include <stdlib.h>


int opt_linenumber = 0 ;
int linenumber = 1 ; 

int string_eq(char * s1, char * s2)
{
	while (*s1 != 0x0) {
		if (*s1 != *s2) 
			return 0 ;
		s1++ ;
		s2++ ;
	}
	return (*s2 == 0x0) ;
}

void
print_file(FILE * fp) 
{
	while (!feof(fp)) {
		char * line = 0x0 ;
		size_t len = 0 ;
		int nread ;
		nread = getline(&line, &len, fp) ;
		if (nread > 0) {
			if (opt_linenumber) {
				printf("%d ", linenumber) ;
				linenumber += 1 ;
			}
			printf("%s", line) ;
		}
		free(line) ;
	}
}

int
main(int argc, char ** args) 
{
	int i = 1 ;

	if (argc < 2) {
		fprintf(stderr, "Invalid argument\n") ;
		exit(1) ;
	}

	if (string_eq(args[1], "-n")) {
		opt_linenumber = 1 ;
		i = 2 ;
	}

	for ( ; i < argc ; i++) {
		FILE * fp ;
		fp = fopen(args[i], "r") ;
		if (fp == 0x0) {
			fprintf(stderr, "Fail to open %s\n", args[i]) ;
			exit(1) ; 
		}
		print_file(fp) ;
	}
}
