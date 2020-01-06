#include <stdio.h>

struct point {
	int x ;
	int y ;
	char c ;
} ;

struct twopoints {
	struct point p1 ;
	struct point p2 ;
} ;

int 
main ()
{
	struct point p1 ;
	struct point p2 ;

	struct twopoints P ;

	p1.x = 1 ;
	p1.y = 1 ;
	p1.c = 'r' ; 

	p2.x = 2 ;
	p2.y = 2 ;
	p2.c = 'b' ;

	P.p1 = p1 ;
	P.p2 = p2 ;

	//struct point p1 = {1, 1} ;
	//struct point p2 = {2, 2} ;
	//p1 = p2 ;

	printf("sizeof(p1): %d\n", (int) sizeof(p1)) ;
	printf("p1.x:%d, p1.y:%d\n", p1.x, p1.y) ;
	printf("p2.x:%d, p2.y:%d\n", p2.x, p2.y) ;
}
