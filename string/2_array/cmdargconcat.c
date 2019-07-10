#include <stdio.h>

void
string_concat(char * dest, char * src) 
{
	int i, j ;
	for (i = 0 ; dest[i] != 0x0 ; i++) ;

	for (j = 0 ; src[j] != 0x0 ; j++) 
		dest[i + j] = src[j] ;

	dest[i + j] = 0x0 ;
}


int
main(int argc, char ** args)
{
	int i ;
	char s[1024] = "" ;

	for (i = 0 ; i < argc ; i++) {
		string_concat(s, args[i]) ;
		//string_concat(s, " ") ;
	}

	printf("%s\n", s) ;
}
