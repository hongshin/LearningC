#include <stdio.h>

struct point {
	int x ;
	int y ;
} ;

int 
main()
{
	struct point p1 ;
	struct point p2 ;
	p1.x = 1 ;
	p1.y = 1 ;
	p2.x = 2 ;
	p2.y = 2 ;
	//struct point p1 = {1, 1} ;
	//struct point p2 = {2, 2} ;

	printf("p1.x:%d, p1.y:%d\n", p1.x, p1.y) ;
	printf("p2.x:%d, p2.y:%d\n", p2.x, p2.y) ;
}
