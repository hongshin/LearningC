#include <stdio.h>
#include <stdlib.h>

//TODO: write strstrn here

int
main()
{
	char * s1 = "He restores my soul. He leads me in paths of righteousness for his name's sake." ;
	
	if (strstrn(s1, "He", 1) != s1)
		return error ;

	if (strstrn(s1, "He", 2) != s1 + 21)
		return error ;

	if (strstrn(s1, "He", 3) != 0x0)
		return error ;
	
	if (strstrn(s1, "He", 0) != 0x0)
		return error ;


	printf("Pass\n") ;
	exit(0) ;

error:
	printf("Wrong answer\n") ;
	exit(1) ;
}
