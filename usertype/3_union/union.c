#include <stdio.h>

union attribute {
	int i ;
	short s ;
	char c[4] ;
} ;

int
main()
{
	int i ;
	union attribute a ;
	a.i = 257 ;
	a.c[0] = 2 ;

	unsigned char * p ;
	p = (unsigned char *) &a ;
	for (i = 0 ; i < sizeof(union attribute); i++) 
		printf("%p: %d\n", (p + i), (int) p[i]) ;	
}
