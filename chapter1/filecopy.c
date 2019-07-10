#include <stdio.h>

int 
main () 
{
	int c ; 

	for (c = getchar() ; 
		 c != EOF ; 
		 c = getchar()) {
		putchar(c) ;
	}
}
