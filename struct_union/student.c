#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	Business,
	Law,
	Mechanics,
	Biology,
	Computer,
	N_Dept 
} Dept ;

char * DeptTitle[] = {
	"Business",
	"Law",
	"Mechanics",
	"Biology",
	"Computer"
} ;

typedef struct {
	char * name ;

	Dept dept ;
	
	int math ;
	int physics ;
	int english ;
} student ;

void
print_student(student * s)
{
	printf("[%s, %d, %d, %d , %d]\n", s->name, s->dept, s->math, s->physics, s->english) ;
}


Dept 
get_department(char * s)
{
	int i ;
	for (i = 0 ; i < N_Dept; i++) {
		if (strcmp(s, DeptTitle[i]) == 0)
			return i ;
	}
	return N_Dept ;
}


student 
read_student(char * l) 
{
	student s ;
	char * p ;

	p = strtok(l, " ,\n") ;

	s.name = strdup(p) ;
	s.dept = get_department(strtok(0x0, " ,\n")) ;
	s.math = atoi(strtok(0x0, " ,\n")) ;
	s.physics = atoi(strtok(0x0, " ,\n")) ;
	s.english = atoi(strtok(0x0, " ,\n")) ;
	
	return s ;
}

int
main()
{
	char * l ; 
	size_t len ;
	FILE * fp ;
	student s ;
	
	
	fp = fopen("students.csv", "r") ;
	if (fp == 0x0)
		exit(1) ;

	l = 0x0 ;
	len = 0 ;
	getline(&l, &len, fp) ;

	s = read_student(l) ;

	print_student(&s) ;

	fclose(fp) ;
}
