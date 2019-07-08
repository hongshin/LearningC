#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int
a2i(char s[])
{
	int i, n ;
	n = 0 ;
	for (i = 0 ; isdigit(s[i]) ; i++)
		n = 10 * n + (s[i] - '0') ;
	return n ;
}


int
main()
{
	char * s = "234" ;
	int i ;

	i = a2i(s) ;
	printf("%d\n", i) ;
}
