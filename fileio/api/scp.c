#include <stdio.h>

int main (int argc, char ** args)
{
	FILE * fin, * fout ;

	fin = fopen(args[1], "r") ;
	fout = fopen(args[2], "w") ;

	char buf[128] ;

	while (!feof(fin)) {
		char * s ;
		s = fgets(buf, 128, fin) ;
		//if (s != NULL) {
		fputs(buf, fout) ;
		//}
	}

	return 0 ;
}
