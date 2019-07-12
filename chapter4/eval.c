#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
print (char * s, int len, int v)
{
	for (int i = 0 ; i < len ; i++)
		printf("%c", s[i]) ;
	printf(" = %d\n", v) ;
}

int
eval (char * s, int len)
{
	int r = 0 ; 


	if (*s == '(') {
		int i = 1 ;
		int n_paran = 0 ;

		do {
			if (s[i] == '(') {
				n_paran += 1 ;
			}
			else if (s[i] == ')') {
				n_paran -= 1 ;
			}
			if (n_paran == 0) {
				if (s[i] == '+') {
					int a, b ;
					a = eval(s + 1, i - 2) ;
					b = eval(s + i + 2, len - i - 3) ;
					return a+b ;
				}
				else if (s[i] == '-') {

					int a, b ;
					a = eval(s + 1, i - 2) ;
					b = eval(s + i + 2, len - i - 3) ;
					return a - b ;
				}
				else if (s[i] == '*') {
					int a, b ;
					a = eval(s + 1, i - 2) ;
					b = eval(s + i + 2, len - i - 3) ;
					return a * b ;
				}
			}
			i += 1 ;
		} while (i < len) ;
	}
	
	int i = 0 ; 
	r = 0 ;
	do {
		r = r * 10 + s[i] - '0' ;
		i += 1 ;
	} while (i < len && isdigit(s[i])) ;
	return r ;
}


int
main ()
{
	char * s = "((1 + (2 * 3)) - (2 * 3))"  ;
	printf("%d\n", eval(s, strlen(s))) ;
}
