#include <stdio.h>
#include <string.h>

int
string_length (char * s) 
{
	int n = 0 ;

	while (*s != 0x0) {
		n = n + 1 ;
		s = s + 1 ;
	}

	return n ;
}

int 
main () 
{
	char a[6] = {'H', 'e', 'l', 'l', 'o', 0x0} ;
	char * b = "Good Bye" ; 
	char c[20] = "Halla, Heba, Helloa" ;
	char d[2] = {0x0 } ;
	char * e = 0x0 ;

	printf("%s %d\n", a, (int) strlen(a)) ;
	printf("%s %d\n", b, (int) strlen(b)) ;
	printf("%s %d\n", c, (int) strlen(c)) ;
	printf("%s %d\n", d, (int) strlen(d)) ;
	//printf("%s %d\n", e, (int) strlen(e)) ;
}
