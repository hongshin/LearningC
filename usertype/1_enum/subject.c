#include <stdio.h>
#include <string.h>

enum Subject {
	Math,
	Phys,
	Engl,
	Prog
	} ;

char * SubjectName [] = {
	"Mathematics",
	"Physics",
	"English",
	"Programming" 
	} ;

int
main () 
{
	printf("%s\n", SubjectName[Math]) ;
	printf("%s\n", SubjectName[Phys]) ;
	printf("%s\n", SubjectName[Engl]) ;
	printf("%s\n", SubjectName[Prog]) ;
}
