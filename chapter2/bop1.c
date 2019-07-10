#include <stdio.h>


unsigned int getbits (unsigned int x, int p, int n) ;

int
main ()
{
	unsigned int n = 0xabcd ;
	printf("%d\n", n) ;
	printf("%x\n", n & 0xff00) ;
	printf("%x\n", n & ~0xf) ;

	printf("%x\n", n >> 4) ;
	//printf("%x\n", getbits(n, 4, 8)) ;
}

unsigned int getbits(unsigned int x, int p, int n) 
{
	return (x >> p ) & ~(~0 << n) ;
}

void setbit(unsigned int x, int b, int v)
{
	/* TODO */
}
