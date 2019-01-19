#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * 
strstrn(char * haystack, char * needle, int n)
{
	int i ;

	if (n < 1)
		return 0x0 ;

	for (i = 1 ; i <= n ; i++) {
		haystack = strstr(haystack, needle) ;
		if (haystack == 0x0) 
			return 0x0 ;

		haystack += 1 ;
	}
	return haystack - 1 ;
}


int
main()
{
	char * s1 = "He restores my soul. He leads me in paths of righteousness for his name's sake." ;
	
	if (strstrn(s1, "He", 1) != s1)
		goto error ;

	if (strstrn(s1, "He", 2) != s1 + 21)
		goto error ;

	if (strstrn(s1, "He", 3) != 0x0)
		goto error ;
	
	if (strstrn(s1, "He", 0) != 0x0)
		goto error ;

	printf("Pass\n") ;
	exit(0) ;

error:
	printf("Wrong answer\n") ;
	exit(1) ;
}
