#include <stdio.h>

enum Color { Red,  Blue, Yellow, Green, Black } ;

int
main ()
{
	const double pi = 3.141592 ;

	enum Color c ;
	
	c = Yellow ;

	printf("%d\n", c) ;
}
