#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * 
string_duplicate(char * orig) 
{
	char * t = 0x0 ;
	int i ;

	t = (char *) malloc(sizeof(char) * (strlen(orig) + 1) ) ;

	i = 0 ; 
	do {
		t[i] = orig[i] ;
		i++ ;
	} while(t[i - 1] != 0x0) ;

	return t ;
}


int 
main () 
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
	//days[6] = string_duplicate("Saturday") ;
	days[6] = strdup("Saturday") ;
	
	days[5][2] = 'i' ;

	for (i = 0 ; i < 7 ; i++) 
		printf("%s\n", days[i]) ;

	for (i = 0 ; i < 7 ; i++) 
		free(days[i]) ;
}
