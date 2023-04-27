#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main (int argc, char ** argv)
{
	char cwd[256] ;
	getcwd(cwd, 256) ;

	DIR * dir = opendir(argv[1]) ;
	struct dirent * i ;
	for (i = readdir(dir) ; i != NULL ; i = readdir(dir)) {
		//printf("%s/%s/%s\n", cwd, argv[1], i->d_name) ;


		char path[256] = "" ;
		sprintf(path, "%s/%s", argv[1], i->d_name) ;

		FILE * fp = fopen(path, "r") ;
		struct stat st ;
		fstat(fp->_fileno, &st) ;
		printf("%s : %d\n", path, (int) st.st_size) ;
		fclose(fp) ;
		
	}

	return 0 ;
}
