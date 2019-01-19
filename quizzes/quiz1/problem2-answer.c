#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TO-DO: strarr_dup
char ** strarr_dup(char ** s1, int len)
{
	int i ;
	char ** s2 ;
	s2 = (char **) malloc(sizeof(char *) * len) ;
	for (i = 0 ; i < len ; i++) {
		s2[i] = strdup(s1[i]) ;
	}
}


int
main()
{
	int i ;
	char * s1[7] = {
		"Monday", 
		"Tuesday", 
		"Wednesday", 
		"Thursday", 
		"Friday", 
		"Saturday", 
		"Sunday" } ;

	char ** s2 ;
	s2 = strarr_dup(s1, 7) ;

	for (i = 0 ; i < 7 ; i++) 
		printf("%s\n", s1[i]) ;
}
