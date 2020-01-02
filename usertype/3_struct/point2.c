#include <stdio.h>

typedef struct _point {
	int x ;
	int y ;
} point ;

void
print_point(point p)
{
	printf("(%d, %d)\n", p.x, p.y) ;
}

int 
main()
{
	point p1 ;
	struct _point p2 ;

	p1.x = 1 ;
	p1.y = 1 ;
	p2.x = 2 ;
	p2.y = 2 ;
	//struct point p1 = {1, 1} ;
	//struct point p2 = {2, 2} ;

	print_point(p1) ;
	print_point(p2) ;
}
