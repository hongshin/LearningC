#include <stdio.h>
#include <stdlib.h>

int count_words(char *s)
{
	//TO-DO
}

int main()
{
	if (count_words("Mister Blue Sky Please Tell Us Why") != 7) 
		goto error ;

	if (count_words(" You had to hide away  for so  long") != 8)
		goto error ;
	
	if (count_words("where did    we go wrong?  ") != 5) 
		goto error ;
	
	if (count_words(" ") != 0) 
		goto error ;

	printf("Pass!\n") ;
	exit(1) ;

error:
	printf("Wrong answer\n") ;
	exit(1) ;	
}