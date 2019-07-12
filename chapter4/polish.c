#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "stack.h"

int 
eval (char *s)
{
	int result ;
	int num = 0 ;

	while (*s != 0x0) {
		if (isdigit(*s)) {
			num = (int)(*s - '0') ;
			while (isdigit(*(s+1))) {
				s += 1 ;
				num = num * 10 + (int)(*s - '0') ;
			}
			push(num) ;
			num = 0 ;
		}
		else if (*s == '+') {
			int a, b ;
			if (pop(&b) == 0) 
				goto err ;
			if (pop(&a) == 0) 
				goto err ;
			push(a + b) ;
		}
		else if (*s == '-') {
			int a, b ;
			if (pop(&b) == 0) 
				goto err ;
			if (pop(&a) == 0)
				goto err ;
			push(a - b) ;			
		}
		else if (*s == '*') {
			int a, b ;
			if (pop(&b) == 0)
				goto err ;
			if (pop(&a) == 0)
				goto err ;
			push(a * b) ;			
		}
		s += 1 ;
	}
	pop(&result) ;
	return result ;

err:
	fprintf(stderr, "Invalid input\n") ;
	exit(1) ;
}

int
main ()
{
	int i ;
	char * s = "12 2 - 4 5 + *" ;

	n_elem = 1 ;

	i = eval(s) ;

	printf("%d\n", i) ;
}
