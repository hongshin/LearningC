#include <stdio.h>
#include <stdlib.h>

void
print (int * a, int n)
{
	int i ;
	for (i = 0 ; i < n ; i++)
		printf("%d ", a[i]) ;
	printf("\n") ;
}

void 
_combination (int * orig, int n_orig, int * gen, int n_gen)
{
	if (n_orig == 0) {
		print(gen, n_gen) ;
		return ;
	}

	gen[n_gen] = *orig ;
	_combination(orig + 1, n_orig - 1, gen, n_gen + 1) ;

	_combination(orig + 1, n_orig - 1, gen, n_gen) ;
}


void 
combination (int * list, int n_list)
{
	int * gen = (int *) malloc(sizeof(int) * n_list) ;

	_combination(list, n_list, gen, 0) ;
}


int 
main () 
{
	int a[5] = {1, 2, 3, 4, 5} ;
	combination(a, 5) ;
}
