#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void push (int) ;
int pop (int *) ;

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
			pop(&b) ;
			pop(&a) ;
			push(a + b) ;
		}
		else if (*s == '-') {
			int a, b ;
			pop(&b) ;
			pop(&a) ;
			push(a - b) ;			
		}
		else if (*s == '*') {
			int a, b ;
			pop(&b) ;
			pop(&a) ;
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

	i = eval(s) ;
	printf("%d\n", i) ;
}
