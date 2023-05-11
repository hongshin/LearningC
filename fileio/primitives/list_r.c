#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void list_dir (char * dirpath)
{
	DIR * dir = opendir(dirpath) ;

	if (dir == 0x0)
		return ;

	for (struct dirent * i = readdir(dir) ; i != NULL ; i = readdir(dir)) {
		if (i->d_type != DT_DIR && i->d_type != DT_REG)
			continue ;

		char * filepath = (char *) malloc(strlen(dirpath) + 1 + strlen(i->d_name) + 1) ;
		strcpy(filepath, dirpath) ;
		strcpy(filepath + strlen(dirpath), "/") ;
		strcpy(filepath + strlen(dirpath) + 1, i->d_name) ;

		if (i->d_type == DT_DIR) {
			printf("d ") ;
			printf("%s\n", filepath) ;

			if (strcmp(i->d_name, ".") != 0 && strcmp(i->d_name, "..") != 0) 
				list_dir(filepath) ;
		}
		else if (i->d_type == DT_REG) {
			struct stat st ;
			stat(filepath, &st) ;
			printf("r ") ;
			printf("%s ", filepath) ;
			printf("%d\n", (int) st.st_size) ;
		}
		free(filepath) ;
	}

	closedir(dir) ;
}



int main (int argc, char ** argv)
{
	if (argc != 2)
		return 1 ;

	list_dir(argv[1]) ;
	return 0 ;
}
