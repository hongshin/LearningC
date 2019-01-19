#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int n_lines = 0 ;
int n_words = 0 ;
int n_chars = 0 ;

int main()
{
	char filename[256] ;

	scanf("%255s", filename) ;
	FILE * fp = fopen(filename, "r") ;

	if (fp == 0x0)
		exit(1) ;

	char * l = 0x0 ;
	size_t n = 0 ;

	while (getline(&l, &n, fp) != -1) {
		if (n > 0) {
			n_lines += 1 ;

			int i ;
			for (i = 0 ; l[i] != 0x0 ; i++) {
				if (!isspace(l[i])) {
					n_chars += 1 ;
					if (isspace(l[i+1]))
						n_words += 1 ;
				}
			}
		}
		l = 0x0 ;
		n = 0 ;
	}

	fclose(fp) ;

	printf("lines: %d\n", n_lines) ;
	printf("words: %d\n", n_words) ;
	printf("chars: %d\n", n_chars) ;
}
