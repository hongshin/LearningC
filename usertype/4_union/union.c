#include <stdio.h>

union attribute {
	int i ;
	short s ;
	char c[4] ;
} ;


void
print_mem (unsigned char * p, size_t s)
{
	size_t i ;
	for (i = 0 ; i < s ; i++)
		printf("%02x ", (unsigned char)p[i]) ;
	printf("\n") ;
}


int
main ()
{
	int i ;
	union attribute a ;

	a.i = 257 ;
	print_mem((unsigned char *) &a, sizeof(a)) ;

	a.c[0] = 2 ;
	print_mem((unsigned char *) &a, sizeof(a)) ;
}
