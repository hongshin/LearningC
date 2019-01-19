#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void 
readCSV(FILE *fp, int col)
{
	char * s = 0x0 ;
	size_t s_len = 0 ;
	int nreads ;
	char * p ; 
	int i ;

	while (getline(&s, &s_len, fp) != -1) {
		p = strtok(s, " ,\t\n") ;
		for (i = 1 ; p != 0x0 && i < col ; i++) 
			p = strtok(0x0, " ,\t\n") ;
		
		if (p != 0x0 && i == col)
			printf("%s\n", p) ;
		else
			return ;
		
		nreads = getline(&s, &s_len, fp) ;
	}
}


int
main(int argc, char ** args)
{
	int i ;
	int col ;

	FILE * fp = fopen("data.csv", "r") ;
	if (fp == 0x0) {
		fprintf(stderr, "Fail to open data.csv\n") ;
		exit(1) ;
	}

	scanf("%d", &col) ;

	readCSV(fp, col) ;
}
