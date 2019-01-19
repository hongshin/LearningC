#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char * string ;

const int n_words = 370098 ;

string * words ;


int lookup(string word)
{
	int i ;
	if (word == 0x0)
		return 0 ;
	for (i = 0 ; i < n_words ; i++) {
		if (strcmp(words[i], word) == 0)
			return 1 ; // true ;
	}
	return 0 ; // false.
}


int 
main()
{
	char input[256] ;

	words = (string *) malloc(sizeof(string) * n_words) ;

	FILE * fp ;
	int i ;
	fp = fopen("words.txt", "r") ;
	for (i = 0  ; i < n_words ; i++) {
		fscanf(fp, "%ms", &(words[i])) ;
	}
	while (1) {
		printf("word: ") ;
		scanf("%255s", input) ; 
		if (lookup(input))
			printf("%s\n", input) ;
	}
}
