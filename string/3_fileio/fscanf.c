#include <stdio.h>

int 
main() 
{
	int i ;
	char buf[16] ;

	for (i = 0 ; i < 5 ; i++) {
		fscanf(stdin, "%15s", buf) ;
		fprintf(stdout, "%s\n", buf) ;
	}
}
