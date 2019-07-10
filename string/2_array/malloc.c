#include <stdio.h>
#include <stdlib.h>

int
main()
{
	int i = 0 ;
	int n_numbers = 0 ;
	int * numbers = 0x0 ;

	scanf("%d", &n_numbers) ;

	numbers = (int *)  malloc(sizeof(int) * n_numbers) ;

	for (i = 0 ; i < n_numbers ; i++)
		scanf("%d", numbers + i) ;
}
