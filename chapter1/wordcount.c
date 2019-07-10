#include <stdio.h>

#define IN	1
#define OUT	0

int
main () 
{
	int c, state ;
	int nc, nw, nl ;

	nc = nw = nl = 0 ;

	state = OUT ;
	while ((c = getchar()) != EOF) {
		nc += 1 ;
		if (c == '\n')
			nl += 1 ;

		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT ;
		}
		else if (state == OUT) {
			state = IN ;
			nw += 1 ;
		}
	}

	printf("%d\t%d\t%d\n", nl, nw, nc) ;
}
