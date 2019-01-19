#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
swap(char ** a, char ** b)
{
	char * t = *a ;
	*a = *b ;
	*b = t ;
}

int
main()
{
	char * words[8] ;
	int i, j ;

	for (i = 0 ; i < 8 ; i++)
		scanf("%ms", &(words[i])) ;

	for (j = 0 ; j < 8 ; j++) {
		int i_min_so_far = j ;
		for (i = i_min_so_far + 1 ; i < 8 ; i++) {
			if (strcmp(words[i_min_so_far], words[i]) > 0)
				i_min_so_far = i ;
		}
		swap(&(words[j]), &(words[i_min_so_far])) ;
	}

	for (i = 0 ; i < 8 ; i++) {
		printf("%s ", words[i]) ;
	}
	printf("\n") ;
}
