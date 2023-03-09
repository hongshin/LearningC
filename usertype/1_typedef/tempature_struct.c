#include <stdio.h>

struct _Celsius { int v ; } ;
struct _Fahrenheit { int v ; } ;
struct _Kelvin { unsigned int v ; } ;

typedef struct _Celsius Celsius ;
typedef struct _Fahrenheit Fahrenheit ;
typedef struct _Kelvin Kelvin ;

Kelvin  
CelsiusToKelvin(Celsius c) 
{
	Kelvin r ;
	r.v = 273 + c.v ;
	return r ;
}

Kelvin
FahrenheitToKelvin(Fahrenheit f)
{
	Kelvin r ;
	r.v = (f.v - 32) * 5 / 9 + 273 ;
	return r ;
}


int 
main ()
{
	Celsius a = { 100 } ;
	Fahrenheit b = { 100 } ;

	printf("%d\n", CelsiusToKelvin(b).v) ;
	printf("%d\n", FahrenheitToKelvin(b).v) ;
}
