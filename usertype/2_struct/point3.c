#include <stdio.h>

typedef struct {
	int x ;
	int y ;
} point ;

void
print_point(point p)
{
	printf("(%d, %d)\n", p.x, p.y) ;
}

point
scale(point p, int s)
{
	p.x *= s ;
	p.y *= s ;

	return p ;
}

void
transpose(point * p)
{
	int t ;
	t = p->x ;
	p->x = p-> y;
	p->y = t ;
}

int 
main()
{
	point p1 = {1, 2} ;
	point p2 ;

	p2 = scale(p1, 2) ;

	print_point(p1) ;
	print_point(p2) ;

	transpose(&p2) ;
	print_point(p2) ;
}
