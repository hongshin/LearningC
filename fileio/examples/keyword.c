#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
match (char * prefix, char * verse)
{
	while (*prefix != 0x0) {
		if (*prefix != *verse) 
			return 0 ;
		prefix++ ;
		verse++ ;
	}
	return 1 ;
}

int 
main ()
{
	char keyword[128] ;

	fscanf(stdin, "%127s", keyword) ;

	FILE * fp = fopen("NIV.txt", "r") ;

	char * v = (char *) malloc(sizeof(char) * 1024) ;
	size_t v_len = 1024 ;

	while (!feof(fp)) {
		int t ;
		getline(&v, &v_len, fp) ;

		if (strstr(v, keyword) != 0x0) {
			printf("%s", v) ;
		}
	}
	return 0 ;
}
