#include <stdio.h>

int 
main() 
{
	int i ;
	char days[7][10] = {
		"Sunday", "Monday", "Tuesday", "Wednesday",
		"Thursday", "Fraday", "Saturday" } ;

	for (i = 0 ; i < 7 ; i++) 
		printf("%s\n", days[i]) ;
}
