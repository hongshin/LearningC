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


student * student_arr ;
int capacity = 4 ;
int size = 0 ;


void
print_student(student * s)
{
	printf("[%s, %d, %d, %d, %d]\n", 
		s->name, s->dept, s->math, s->physics, s->english) ;
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
	int i ;

	student_arr = (student *) calloc(sizeof(student), capacity) ;
	
	fp = fopen("students.csv", "r") ;
	if (fp == 0x0)
		exit(1) ;

	while (!feof(fp)) {
		l = 0x0 ;
		len = 0 ;
	
		if (getline(&l, &len, fp) > 0) {
			if (size == capacity) {
				student_arr = realloc(student_arr, sizeof(student) * capacity * 2) ;
				capacity *= 2 ;
			}

			student_arr[size] = read_student(l) ;
			size += 1 ;
		}
		free(l) ;
	}

	for (i = 0 ; i < size ; i++)
		print_student(student_arr + i) ;

	fclose(fp) ;
}
