#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int n_words = 370098 ;

char ** words ;


int lookup(char * word)
{
	int begin = 0 ;
	int end = n_words -1 ;

	while (begin <= end) {
		//printf("[%d, %d]\n", begin, end) ;
		int mid = (begin + end) / 2 ;
		int c = strcasecmp(word, words[mid]) ;
		if (c == 0) {
			return 1 ;
		}
		else if (c < 0) {
			begin = mid + 1 ;
		}
		else /* c > 0 */ {
			end = mid - 1 ;
		}
	}
	return 0 ;
}


int 
main()
{
	char input[256] ;

	words = (char **) malloc(sizeof(char *) * n_words) ;

	FILE * fp ;
	int i ;
	fp = fopen("words_inverse.txt", "r") ;
	for (i = 0  ; i < 370098 ; i++) {
		fscanf(fp, "%ms", &(words[i])) ;
	}
	while (1) {
		printf("word: ") ;
		scanf("%256s", input) ; 
		if (lookup(input))
			printf("%s\n", input) ;
	}
}
