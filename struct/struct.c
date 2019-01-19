#include <stdio.h>
#include <stdlib.h>

struct compound {
	unsigned short i ;
	char c ;
} ;

int
main()
{
	struct compound a ;
	struct compound * b ;
	int i ;

	a.i = 1 ;
	a.c = 'a' ;

	b = (struct compound *) malloc(sizeof(struct compound)) ;
	b->i = 2 ;
	b->c = '0' ;

	printf("%ld\n", (long) sizeof(struct compound)) ;

	unsigned char * p = (unsigned char *) &a ;
	for (i = 0 ; i < sizeof(struct compound) ; i++) {
		printf("%p : %d\n", (p + i), p[i]) ;
	}

	p = (unsigned char *) b ;
	for (i = 0 ; i < sizeof(struct compound) ; i++) {
		printf("%p : %d\n", (p + i), p[i]) ;
	}
}
