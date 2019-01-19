#include <stdio.h>

#define F_GENDER	1
#define F_FOREIGN	2
#define F_DORM		4
#define F_SCOLAR	8

#define IS_FORIEGN(x) 	x & F_FOREIGN ? 1 : 0 

typedef struct {
	char * 	name ;
	int 	math ;
	int		physics ;
	int		english ;

	unsigned char properties ;
} student ;


void
print_student(student * s)
{
	printf("%s (gender:%d, foreigner: %d, dormitory: %d, scholarship: %d)\n",
		s->name,
		IS_FOREIGN(s->properties),
		//s->properties & F_GENDER ? 1 : 0,
		s->properties & F_FOREIGN ? 1 : 0,
		s->properties & F_DORM ? 1 : 0,
		s->properties & F_SCOLAR ? 1 : 0
	) ;
}


int
main()
{
	student s1 = {"Alexa", 90, 80, 70, 0} ;

	s1.properties |= F_GENDER /*1*/ ;
	s1.properties &= ~F_FOREIGN /*2*/;
	s1.properties |= F_DORM /*4*/;
	s1.properties |= F_SCOLAR /*8*/;

	print_student(&s1) ;

	s1.properties |= F_FOREIGN ;
	s1.properties &= ~F_DORM ;

	print_student(&s1) ;
}
