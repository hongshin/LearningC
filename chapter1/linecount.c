#include <stdio.h>

int
main () 
{
	int c, nc = 0 ;

	while ((c = getchar()) != EOF) 
		if (c == '\n')
			nc += 1 ;
	
	printf("%d\n", nc) ;
}
