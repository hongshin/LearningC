#include <stdio.h>

#define IN	1
#define OUT	0

int
main () 
{
	int c, i, nwhite, nothers ;
	int ndigit[10] ;

	nwhite = nothers = 0 ;
	for (i = 0 ; i < 10 ; i++)
		ndigit[i] = 0 ;
	
	while ((c = getchar()) != EOF) {
		if ('0' <= c && c <= '9') 
			++ndigit[c - '0'] ;
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite ;
		else
			++nothers ;
	}

	printf("digits = ") ;
	for (i = 0 ; i < 10 ; i++)
		printf(" %d", ndigit[i]) ;
	printf(", white space = %d, others = %d\n", nwhite, nothers) ;
}
