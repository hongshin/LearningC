#include <stdio.h>

int main ()
{
	char buf[128] ;
	scanf("%127s", buf) ;
	printf("Hellow, %s\n", buf) ;
	return 0 ;
}
