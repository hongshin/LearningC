#include <stdio.h>
#include <string.h>

typedef struct {
	char * name ;
	int    num ;
	double gpa ;
} Student ;

void
print_student(Student s) 
{
	printf("%s, %d %f\n", s.name, s.num, s.gpa) ;
}

int 
main()
{
	Student s ;
	s.name = strdup("Alexa") ;
	s.num = 2392827 ;
	s.gpa = 3.0 ;

	print_student(s) ;
}
