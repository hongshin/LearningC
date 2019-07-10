#include <stdio.h>

/* print Fahrenheit-Celsius table */
int 
main () 
{
	int fahr, celsius ;
	int lower, upper, step ;

	lower = upper = step = 0 ;

	lower = 0 ; 
	upper = 300 ;
	step = 20 ;
	fahr = lower ;

	

loop_start:
	if (fahr <= upper) {
		celsius = 5 * (fahr - 32) / 9 ;
		printf("%d\t%d\n", fahr, celsius) ;
		fahr = fahr + step ;
	}
	else {
		goto loop_end ;
	}
	goto loop_start ;
loop_end:
	return 0 ;
}
