#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x ;
	int y ;
} point ;

typedef struct {
	point * p1 ;
	point * p2 ;
} rect ;

void
print_point(point p)
{
	printf("(%d, %d)\n", p.x, p.y) ;
}

point
scale (point p, int s)
{
	point r ; 
	
	r.x = p.x * s ;
	r.y = p.y * s ;

	return r ;
}

void
transpose (point * p)
{
	int t ;

	t = p->x ; // t = *p.x ;

	p->x = p->y;
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

	rect * r = (rect *) malloc(sizeof(rect)) ;
	r->p1 = &p1 ;
	r->p2 = &p2 ; 

	printf("top-left point: (%d,%d)\n",
		(r->p1)->x, (r->p1)->y) ;

}
