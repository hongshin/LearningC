#include <stdio.h>

int
main () 
{
	int nc = 0 ;

	while (getchar() != EOF) 
		nc += 1 ;
	
	printf("%d\n", nc) ;
}
