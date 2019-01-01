#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int n_columns = 0 ;
int n_rows = 0 ;
int * sum = 0x0 ;

void 
readCSV(FILE *fp)
{
	char * s = 0x0 ;
	size_t s_len = 0 ;
	int nreads ;
	char * firstline ;
	char * p ; 
	int i ;

	nreads = getline(&s, &s_len, fp) ;
	firstline = strdup(s) ;

	p = strtok(firstline, " ,\t\n") ;
	while (p != 0x0) {
		n_columns += 1 ;
		p = strtok(0x0, " ,\t\n") ;
	}

	sum = (int *) malloc(sizeof(int) * n_columns) ;

	do {		
		n_rows += 1 ;
		p = strtok(s, " ,\t\n") ;
		for (i = 0 ; p != 0x0 || i < n_columns ; i++) {
			sum[i] += atoi(p) ;
			p = strtok(0x0, " ,\t\n") ;
		}
		if (!(p == 0x0 && i == n_columns)) {
			fprintf(stderr, "Wrong number of elements at Line %d\n", n_rows) ;
			exit(1) ;
		}
		
		nreads = getline(&s, &s_len, fp) ;
	} while (nreads > 0) ;
}


int
main(int argc, char ** args)
{
	int i ;
	if (argc != 2) {
		fprintf(stderr, "Wrong number of argument.\n") ;
		exit(1) ;
	}

	FILE * fp = fopen(args[1], "r") ;
	if (fp == 0x0) {
		fprintf(stderr, "Fail to open %s\n", args[1]) ;
		exit(1) ;
	}

	readCSV(fp) ;

	for (i = 0 ; i < n_columns ; i++) {	
		printf("%d", sum[i] / n_rows) ;
		if (i != n_columns -1)
			printf(", ") ;
	}
	printf("\n") ;
}
