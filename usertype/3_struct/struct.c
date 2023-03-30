#include <stdio.h>
#include <stdlib.h>

struct compound {
	unsigned short i ;
	char c ;
} ;

void
print_mem (unsigned char * p, size_t s)
{
	size_t i ;
	for (i = 0 ; i < s ; i++)
		printf("%02x ", p[i]) ;
	printf("\n") ;
}

int
main ()
{
	struct compound a ;
	struct compound * b ;
	int i ;

	a.i = 256 ;
	a.c = 'a' ;

	b = (struct compound *) malloc(sizeof(struct compound)) ;
	b->i = 2 ;
	b->c = '0' ;

	printf("%d\n", (int) sizeof(struct compound)) ;
	printf("%d\n", (int) sizeof(unsigned short)) ;
	printf("%d\n", (int) sizeof(char)) ;

	print_mem((unsigned char *)&a, sizeof(a)) ;
	print_mem((unsigned char *)b, sizeof(*b)) ;
}
