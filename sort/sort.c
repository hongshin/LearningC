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

	//for (i = 0 ; i < 10 ; i++)
	//	scanf("%d", (num + i)/*&(num[i])*/) ;

	int i_max_so_far = 0 ;
	for (i = 1 ; i < 10 ; i++) {
		if (num[i] > num[i_max_so_far])
			i_max_so_far = i ;
	}
	swap(&(num[0]), &(num[i_max_so_far])) ;
	printf("%d\n", num[0]) ;

	i_max_so_far = 1 ;
	for (i = 2 ; i < 10 ; i++) {
		if (num[i] > num[i_max_so_far])
			i_max_so_far = i ;
	}
	swap(&(num[1]), &(num[i_max_so_far])) ;
	printf("%d\n", num[1]) ;
}
