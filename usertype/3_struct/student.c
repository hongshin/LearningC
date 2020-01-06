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

char * DeptTitle [] = {
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
print_student (student * s)
{
	printf("[%s, %s, %d, %d , %d]\n",
		s->name, 
		DeptTitle[s->dept], 
		s->math, 
		s->physics, 
		s->english) ;
}


Dept 
get_department (char * s)
{
	int i ;
	for (i = 0 ; i < N_Dept; i++) {
		if (strcmp(s, DeptTitle[i]) == 0)
			return i ;
	}
	return -1 ;
}


student *
read_student (char * l) 
{
	student * s ;
	char * p ;

	s = (student *) malloc(sizeof(student)) ;

	if (!(p = strtok(l, " ,\n"))) {
		free(s) ;
		return 0x0 ;
	}
	s->name = strdup(p) ;

	s->dept = get_department(strtok(0x0, " ,\n")) ;
	s->math = atoi(strtok(0x0, " ,\n")) ;
	s->physics = atoi(strtok(0x0, " ,\n")) ;
	s->english = atoi(strtok(0x0, " ,\n")) ;
	
	return s ;
}

int
main ()
{
	char * l ; 
	size_t len ;
	FILE * fp ;
	student * s[100] ;
	int i ;
	
	
	fp = fopen("students.csv", "r") ;
	if (fp == 0x0)
		exit(1) ;

	i = 0 ;
	while (!feof(fp)) {
		l = 0x0 ;
		len = 0 ;
		if (getline(&l, &len, fp) == 0)
			break ; 

		s[i] = read_student(l) ;
		if (s[i] == 0x0)
			break ;
		print_student(s[i]) ;
		i++ ;
		free(l) ;
	}
	fclose(fp) ;
}
