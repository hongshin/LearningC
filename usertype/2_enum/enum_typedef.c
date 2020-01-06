#include <stdio.h>

typedef 
	enum { e1, e2, e3, e4, e5 } 
	Kind ;

int
main()
{
	Kind v1 = e1 ;
	Kind v2 = e2 ;
	Kind v3 = e3 ;
	Kind v4 = e4 ;
	Kind v5 = e5 ;

	printf("%d\n", v1) ;
	printf("%d\n", v2) ;
	printf("%d\n", v3) ;
	printf("%d\n", v4) ;
	printf("%d\n", v5) ;
}
