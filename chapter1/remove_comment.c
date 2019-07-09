#include <stdio.h>

#define TEXT	0
#define STRI	1
#define MCOM	2
#define SCOM	3

int
main() 
{
	int c1 = EOF ;
	int c2 = EOF ;
	int state = TEXT ;
	int c ;
	
	for (c2 = getchar() ; c2 != EOF ; c2 = getchar()) {
		switch (state) {
			case TEXT:
				if (c1 == '/' && c2 == '*')
					state = MCOM ;
				else if (c1 == '/' && c2 == '/')
					state = SCOM ;
				else if (c1 != '\\' && c2 == '\"')
					state = STRI ;
				else {
					if (c1 != EOF && c2 != '/') 
						putchar(c2) ;
					else if (c1 == '/') {
						putchar(c1) ;
						putchar(c2) ;
					}
				}
				break ;

			case STRI:
				putchar(c2) ;
				if (c1 != '\\' && c2 == '\"')
					state = TEXT ;
				break ;

			case MCOM:
				if (c1 == '*' && c2 == '/')
					state = TEXT ;
				break ;

			case SCOM:
				if (c2 == '\n')
					state = TEXT ;
				break ;
		}
		c1 = c2 ;
	}
	if (c2 == EOF)
		putchar(c1) ;
}
