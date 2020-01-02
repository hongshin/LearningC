#include <stdio.h>

enum Kind { e1 = 1, e2 , e3, e4 , e5 } ;

int
main()
{
	enum Kind v1 = e1 ;
	enum Kind v2 = e2 ;
	enum Kind v3 = e3 ;
	enum Kind v4 = e4 ;
	enum Kind v5 = e5 ;
	

	printf("%d\n", v1) ;
	printf("%d\n", v2) ;
	printf("%d\n", v3) ;
	printf("%d\n", v4) ;
	printf("%d\n", v5) ;
}
