#include <stdio.h>

int
main(int argc, char ** args)
{
	int i ;
	for (i = 0 ; i < argc ; i++)
		printf("%s\n", args[i]) ;
}
