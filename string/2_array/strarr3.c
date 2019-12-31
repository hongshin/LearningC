#include <stdio.h>
#include <stdlib.h>

int 
string_length(char * s)
{
	int i ;
	for (i = 0 ; s[i] != 0x0 ; i++) ;
	return i ;
}

char *
string_duplicate(char * orig) 
{
	char * s ;
	int i ;
	s = (char *) malloc(sizeof(char) * (string_length(orig) + 1)) ;
	for (i = 0 ; orig[i] != 0x0 ; i++)
		s[i] = orig[i] ;
	s[i] = 0x0 ;

	return s ;
}

int 
main() 
{
	int i ;
	char ** days ;

	days = (char **) malloc(sizeof(char *) * 7) ;

	days[0] = string_duplicate("Sunday") ; 
	days[1] = string_duplicate("Monday") ;
	days[2] = string_duplicate("Tuesday") ;
	days[3] = string_duplicate("Wednesday") ;
	days[4] = string_duplicate("Thursday") ;
	days[5] = string_duplicate("Fraday") ; 
	days[6] = string_duplicate("Saturday") ;

	days[5][2] = 'i' ;

	for (i = 0 ; i < 7 ; i++) 
		printf("%s\n", days[i]) ;

	for (i = 0 ; i < 7 ; i++) 
		free(days[i]) ;
}
