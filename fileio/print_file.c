#include <stdio.h>
#include <stdlib.h>


int
main () 
{
	char fname[128] ;

	scanf("%s", fname) ;

	FILE * fp = fopen(fname, "r") ;

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
