#include <stdio.h>

int
main ()
{
	int three = 3 ;
	int minusthree = -3 ;
	double dthree = 3.0 ;

	int i ;
	char * p ;

	p = (char *) &three ;
	printf("%d\n", (int) sizeof(three)) ;
	for (i = 0 ; i < sizeof(three) ; i++) {
		printf("%2x ", *(p + i)) ;
	}
	printf("\n") ;

	p = (char *) &minusthree ;
	printf("%d\n", (int) sizeof(three)) ;
	for (i = 0 ; i < sizeof(three) ; i++) {
		printf("%2x ", *(p + i)) ;
	}
	printf("\n") ;

	p = (char *) &dthree ;
	printf("%d\n", (int) sizeof(dthree)) ;
	for (i = 0 ; i < sizeof(dthree) ; i++) {
		printf("%2x ", *(p + i)) ;
	}
	printf("\n") ;


}
