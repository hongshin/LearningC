#include <stdio.h>

void 
print_string (char * s)
{
	while (*s != 0x0) {
		putchar(*s) ;
		s += 1 ;
	}
}


int 
main () 
{
	char a[6] = {'H', 'e', 'l', 'l', 'o', 0x0} ;
	char * b = "Good Bye" ;
	char c[20] = "Halla, Heba, Helloa" ;

	print_string(a) ;
	print_string(b) ;
	print_string(c) ;
}
