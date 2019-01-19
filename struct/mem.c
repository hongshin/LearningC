#include <stdio.h>
#include <stdlib.h>

void 
print_internal(void *data, size_t s)
{
	int i ;
	unsigned char * p = (unsigned char *)data ;
	for (i = 0 ; i < s ; i++) {
		printf("%p : %d\n", (p + i), (int)p[i] /* *(p+i) */) ;
	}

	int * q = (int *) data ;
	for (i = 0 ; i < s ; i++) {
		printf("%p : %d\n", (q + i), (int)q[i] /* *(p+i) */) ;
	}

}

int
main()
{
	int data = -1 ;
	print_internal(&data, sizeof(data)) ;
}
