#include <stdio.h>


char hi[3] = "Hi" ;

int 
main () 
{
	char a[6] = {'H', 'e', 'l', 'l', 'o', 0x0} ;
	char * b = "Good Bye" ;
	char c[20] = "Halla, Heba, Helloa" ;

	printf("a: %s\n", a) ;
	printf("b: %s\n", b) ;
	printf("c: %s\n", c) ;
}
