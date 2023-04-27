#include <stdio.h>

int main (int argc, char ** args)
{
	FILE * fin, * fout ;

	fin = fopen(args[1], "rb") ;
	fout = fopen(args[2], "wb") ;

	char buf[128] ;

	while (!feof(fin)) {
		size_t nr, nw ;

		nr = fread(buf, 1, 128, fin) ;
		//fwrite(buf, 1, nr, fout) ;
		for (nw = 0 ; nw < nr ; ) {
			nw += fwrite(buf + nw, 1, nr - nw, fout) ;
		}
	}

	return 0 ;
}
