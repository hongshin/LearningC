#include <stdio.h>
#include <ctype.h>

int
main () 
{
	int c, i, nwhite, nothers ;
	int  ndigit[10] ;

	nwhite = nothers = 0 ;
	for (i = 0 ; i < 10 ; i++)
		ndigit[i] = 0 ;
	
	while ((c = getchar()) != EOF) {
		if (isdigit(c)) 
			ndigit[c - '0'] += 1 ;
		else if (isblank(c) /*c == ' ' || c == '\n' || c == '\t'*/)
			nwhite += 1 ;
		else
			nothers += 1 ;
	}

	printf("digits = ") ;
	for (i = 0 ; i < 10 ; i++)
		printf(" %d", ndigit[i]) ;
	printf(", white space = %d, others = %d\n", nwhite, nothers) ;
}
