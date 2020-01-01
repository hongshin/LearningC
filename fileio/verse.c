#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int 
main(int argc, char ** args)
{
	char prefix[16] ;
	int  prefix_len ; 
	
	if (argc != 4) {
		fprintf(stderr, "Wrong number of argument\n") ;
		exit(1) ;
	}

	snprintf(prefix, 16, "%s %s:%s", args[1], args[2], args[3]) ;
	prefix_len = strlen(prefix) ;

	FILE * fp = fopen("NIV.txt", "r") ;
	char * v = (char *) malloc(sizeof(char) * 1024) ;
	size_t v_len = 1024 ;
	while (!feof(fp)) {
		getline(&v, &v_len, fp) ;
		if (strncmp(prefix, v, prefix_len) == 0) {
			printf("%s", v) ;
			exit(0) ;
		}
	}
}
