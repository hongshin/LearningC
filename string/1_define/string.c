#include <stdio.h>

int
string_length(char * s) 
{
	int i = 0 ;
	//printf("%p\n", s) ;	
	while (*s != 0x0) {
		s += 1 ;
		i += 1 ;
	}
	return i ;
}

int 
main () 
{
	char a[6] = {'H', 'e', 'l', 'l', 'o', 0x0} ;
	char c[20] = "Halla, Heba, Helloa" ;
	char * b = "Good Bye" ;

	char d[2] = {0x0, 0x0} ;

	//string_length(0x0) ;
	string_length(d) ;

	printf("%s %d\n", a, string_length(a)) ;
	printf("%s %d\n", b, string_length(b)) ;
	printf("%s %d\n", c, string_length(c)) ;
}
