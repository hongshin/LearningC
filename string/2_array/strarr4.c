#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *
string_duplicate (char * orig) 
{
	// TODO: implement here
	return 0x0 ;
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
