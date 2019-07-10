#include <stdio.h>

int 
main(int argc, char ** args)
{
	int i = 0 ;
	for (i = 0 ; i < argc ; i++)
		printf("%s\n", args[i]) ;
}
