#include <stdio.h>

void 
print_string (char * s)
{
	if (s == 0x0)
		return ;

	while (*s != 0x0) {
		putchar((int) *s) ;
		s += 1 ;
	}
	putchar((int) '\n') ;
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
