#include <stdlib.h>
#include <stdio.h>

static int * stack = 0x0 ;
static int capacity = 0 ;
static int n_elem = 0 ;

int stack_err = 0 ;

void push (int a)
{
	if (capacity < n_elem + 1) {
		capacity *= 2 ;
		stack = (int *) realloc(stack, capacity * sizeof(int)) ;
		if (stack == 0x0) {
			stack_err = 2 ; // Memory error 
			return ;
		}
	}
	stack[n_elem] = a ;	
	n_elem += 1 ;
	stack_err = 0 ;
}

int pop ()
{
	if (n_elem == 0) {
		stack_err = 1 ; // Underflow ;
		return 0 ;
	}
	
	int t ;
	t = stack[n_elem - 1] ;
	stack_err = 0 ;
	return t
}
