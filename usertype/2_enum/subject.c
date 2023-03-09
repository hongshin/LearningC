#include <stdio.h>
#include <string.h>

typedef 
enum {
	Math, //0
	Phys, //1
	Engl, //2
	Prog  //3
	} Subject ;

char * SubjectName [] = {
	"Mathematics",
	"Physics",
	"English",
	"Programming" 
	} ;

int
main () 
{
	Subject s = Math ;

	printf("%s\n", SubjectName[Math]) ;
	printf("%s\n", SubjectName[Phys]) ;
	printf("%s\n", SubjectName[Engl]) ;
	printf("%s\n", SubjectName[Prog]) ;
}
