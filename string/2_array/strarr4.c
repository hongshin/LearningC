#include <stdio.h>
#include <stdlib.h>

int 
string_len(char * s)
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
	s = (char *) malloc(sizeof(char) * (string_len(orig) + 1)) ;
	for (i = 0 ; orig[i] != 0x0 ; i++)
		s[i] = orig[i] ;
	s[i] = 0x0 ;

	return s ;
}

int 
main() 
{
	char * days[8] ;
	days[0] = string_duplicate("Sunday") ; 
	days[1] = string_duplicate("Monday") ;
	days[2] = string_duplicate("Tuesday") ;
	days[3] = string_duplicate("Wednesday") ;
	days[4] = string_duplicate("Thursday") ;
	days[5] = string_duplicate("Friday") ; 
	days[6] = string_duplicate("Saturday") ;
	days[7] = 0x0 ;

	char ** p = days ; 

	while (*p != 0x0) {
		printf("%s\n", *p) ;
		p += 1 ;
	}
}
