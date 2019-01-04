#include <stdio.h>

int 
main() 
{
	int i ;
	char * days[7] ;
	days[0] = "Sunday" ; 
	days[1] = "Monday" ;
	days[2] = "Tuesday" ;
	days[3] = "Wednesday" ;
	days[4] = "Thursday" ;
	days[5] = "Friday" ; 
	days[6] = "Saturday" ;

	for (i = 0 ; i < 7 ; i++) 
		printf("%s\n", days[i]) ;
}
