#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Subject {
	Math,
	Phys,
	Engl,
	Prog,
	N_Subjects 
} ;

char * SubjectTitle [] = {
	"Mathematics",
	"Physics",
	"English",
	"Programming",
	0x0
} ;


int * sum ;
int n_students = 0 ;

int
main()
{
	FILE * fp ; 
	char * l ; 
	int i ;

	sum = (int *) calloc(sizeof(int), N_Subjects) ;
	
	fp = fopen("students.csv", "r") ; 
	
	if (!fp)
		exit(1) ;

	while (!feof(fp)) {
		char * l = 0x0 ;
		char * p ;
		size_t len = 0 ;

		if (getline(&l, &len, fp) != -1) {
			strtok(l, " ,\n") ;
			for (i = 0 ; i < N_Subjects ; i++) {
				char * tok = strtok(0x0, " ,\n") ;
				sum[i] += atoi(tok) ;
			}
			n_students += 1 ;
		}
		free(l) ;
	}

	for (i = 0 ; i < N_Subjects ; i++)
		printf("Avg. %s:%d\n", SubjectTitle[i], sum[i] / n_students) ;
}




