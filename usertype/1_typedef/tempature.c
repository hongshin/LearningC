#include <stdio.h>

typedef int Celsius ;
typedef int Fahrenheit ;
typedef unsigned int Kelvin ;

Kelvin  
CelsiusToKelvin(Celsius c) 
{
	return 273 + c ;
}

Kelvin
FahrenheitToKelvin(Fahrenheit f)
{
	return (f - 32) * 5 / 9 + 273 ;
}


int 
main ()
{
	Celsius a = 100 ;
	Fahrenheit b = 100 ;

	printf("%d\n", CelsiusToKelvin(b)) ;
	printf("%d\n", FahrenheitToKelvin(b)) ;
}
