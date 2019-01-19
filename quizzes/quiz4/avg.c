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
	int ** avg ;
	int i, j ;


	avg = (int **) malloc(sizeof(int *) * N_Dept) ;
	for (i = 0 ; i < N_Dept ; i++) {
		avg[i] = (int *) malloc(sizeof(int) * 4) ; 
		for (j = 0 ; j < 4 ; j++)
			avg[i][j] = 0 ;
	}
	
	fp = fopen("students.csv", "r") ;
	if (fp == 0x0)
		exit(1) ;

	l = 0x0 ;
	len = 0 ;

	while (getline(&l, &len, fp) != -1) {
		s = read_student(l) ;

		avg[s.dept][0]++ ;
		avg[s.dept][1] += s.math ;
		avg[s.dept][2] += s.physics ;
		avg[s.dept][3] += s.english ;
	}

	for (i = 0 ; i < N_Dept ; i++) {
		if (avg[i][0] > 0) {
			printf("%s,%d,%d,%d\n", 
				DeptTitle[i],
				avg[i][1] / avg[i][0],
				avg[i][2] / avg[i][0],
				avg[i][3] / avg[i][0] ) ;				
		}
	}

	fclose(fp) ;
}
