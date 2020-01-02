#include <stdio.h>

void
print_mem (unsigned char * p, size_t s)
{
	size_t i ;
	for (i = 0 ; i < s ; i++)
		printf("%02x ", (unsigned char)p[i]) ;
	printf("\n") ;
}


int
main ()
{
	int three = 3 ;
	int minusthree = -3 ;
	double dthree = 3.0 ;

	print_mem((unsigned char *)&three, sizeof(int)) ;
	print_mem((unsigned char *)&minusthree, sizeof(int)) ;
	print_mem((unsigned char *)&dthree, sizeof(double)) ;
}
