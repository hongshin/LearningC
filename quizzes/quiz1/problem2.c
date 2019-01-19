#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//TO-DO: strarr_dup

int
main()
{
	int i ;
	char * s1[7] = {
		"Sunday",
		"Monday", 
		"Tuesday", 
		"Wednesday", 
		"Thursday", 
		"Friday", 
		"Saturday" 
	} ;

	char ** s2 ;
	s2 = strarr_dup(s1, 7) ;

	if (s1 == s2)
		goto error ;

	for (i = 0 ; i < 7 ; i++) {
		if (s1[i] == s2[i])
			goto error ;
		printf("%s\n", s2[i]) ;
	}
	exit(0) ;

error:
	printf("Wrong answer.\n") ;
	exit(1) ;
}
