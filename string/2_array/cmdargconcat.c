#include <stdio.h>

void
string_concat (char * dest, char * src) 
{
	// TODO: implement here
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
