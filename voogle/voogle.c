#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE * fp_niv ;

char * read_a_line ()
{
	static char buf[BUFSIZ] ;
	static int buf_n = 0 ;
	static int curr = 0 ;

	if (feof(fp_niv))
		return 0x0 ;

	char * s = 0x0 ;
	size_t s_len = 0 ;
	do {
		int end = curr ;
		while (!(end >= buf_n || !iscntrl(buf[end]))) {
			end++ ;
		}
		curr = end ;
		while (!(end >= buf_n || iscntrl(buf[end]))) {
			end++ ;
		}
		if (s == 0x0) {
			s = strndup(buf + curr, end - curr) ;
			s_len = end - curr ;
		}
		else {
			s = realloc(s, s_len + end - curr + 1) ;
			s = strncat(s, buf + curr, end - curr) ;
			s_len = s_len + end - curr ;
		}
		if (end < buf_n) {
			curr = end + 1 ;
			break ;
		}

		buf_n = fread(buf, 1, sizeof(buf), fp_niv) ;
		curr = 0 ;
	} while (buf_n > 0) ;
	return s ;
}



int main (int argc, char ** argv)
{
	fp_niv = fopen("NIV.txt", "r") ;

	char * s = 0x0 ;

	while (s = read_a_line()) {
		printf("%s$\n", s) ;
		free(s) ;
	}


	fclose(fp_niv) ;
}
