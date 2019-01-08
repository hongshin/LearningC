#include <stdio.h>
void
swap(int * a, int * b)
{
	int t = *a ;
	*a = *b ;
	*b = t ;
}

int
main()
{
	int num[10] = {23, 1, 5, 40, 8, 32, 11, 43, 7, 40} ; 
	int i, j ;

	for (j = 0 ; j < 10 ; j++) {
		int i_min_so_far = j ;
		for (i = i_min_so_far + 1 ; i < 10 ; i++) {
			if (num[i] < num[i_min_so_far])
				i_min_so_far = i ;
		}
		swap(&(num[j]), &(num[i_min_so_far])) ;
	}

	for (i = 0 ; i < 10 ; i++) {
		printf("%d ", num[i]) ;
	}
	printf("\n") ;
}
