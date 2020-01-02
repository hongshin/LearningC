#include <stdio.h>

void
authenticated() 
{
	printf("Something secret!\n") ;
}

int  // 0: false, non-zero: true
string_eq(char * s1, char * s2)
{
	while (*s1 != 0x0) {
		if (*s1 != *s2) 
			return 0 ;
		s1++ ;
		s2++ ;
	}
	return (*s2 == 0x0) ;
}

int 
main() 
{
	char buf[16] ;
	char password[16] = "difficult" ;

	int trial ;
	for (trial = 0 ; trial < 3 ; trial++) {
		printf("password: ") ;
		scanf("%15s", buf) ;
		if (string_eq(buf, password)) {
			authenticated() ;
			break ;
		}
	}
}
