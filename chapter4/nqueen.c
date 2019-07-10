#include <stdio.h>
#include <stdlib.h>

#define col(l) ((l) % 8)
#define row(l) ((l) / 8)

int b[8][8] ;

int m[8][8] ;
int n_findings = 0 ;
unsigned long long first = 0 ;

unsigned long long signature()
{
	int y, x ;
	unsigned long long s = 0 ;

	for (y = 0 ; y < 8 ; y++) {
		for (x = 0 ; x < 8 ; x++) {
			s = s << 1 ;
			s += b[y][x] ;
		}
	}
	return s ;
}

void 
mark (int l)
{
	int d[4][2] = {{1,1}, {-1,1}, {1,-1}, {-1,-1}} ;
	int x, y, i, j, k ;

	y = row(l) ;
	x = col(l) ;

	b[y][x] = 1 ;

	for (i = 0 ; i < 8 ; i++)
		m[i][x] += 1 ;
	
	for (i = 0 ; i < 8 ; i++) 
		m[y][i] += 1 ;

	for (k = 0 ; k < 4 ; k++) {
		int ix, iy ;
		ix = x ;
		iy = y ;

		while (0 <= ix && ix < 8 && 0 <= iy && iy < 8) {
			m[iy][ix] += 1 ;
			ix += d[k][0] ;
			iy += d[k][1] ;
		}
	}
}

void 
unmark (int l)
{
	int d[4][2] = {{1,1}, {-1,1}, {1,-1}, {-1,-1}} ;
	int x, y, i, j, k ;

	y = row(l) ;
	x = col(l) ;

	b[y][x] = 0 ;

	for (i = 0 ; i < 8 ; i++) 
		m[i][x] -= 1 ;
	
	for (i = 0 ; i < 8 ; i++) 
		m[y][i] -= 1 ;

	for (k = 0 ; k < 4 ; k++) {
		int ix, iy ;
		ix = x ;
		iy = y ;

		while (0 <= ix && ix < 8 && 0 <= iy && iy < 8) {
			m[iy][ix] -= 1 ;
			ix += d[k][0] ;
			iy += d[k][1] ;
		}
	}
}

void 
print ()
{
	int x, y ;
	for (y = 0 ; y < 8 ; y++) {
		for (x = 0 ; x < 8 ; x++) 
			printf("%d ", b[y][x]) ;
		printf("\n") ;

		/*printf("    ") ;
		for (x = 0 ; x < 8 ; x++)
			printf("%d ", m[y][x]) ;
		*/
	}
	printf("\n") ;
}

void
place (int n)
{
	int i = 0 ;

	if (n == 0) {
		if (first  == 0) {
			print() ;
			first = signature() ;
		}
		else {
			if (first != signature()) {
				print() ;
				exit(0) ;
			}
			else {
				return ;
			}
		}
	}
	
	for (i = 0 ; i < 64 ; i++) {
		if (m[row(i)][col(i)] == 0) {
			mark(i) ;
			place(n - 1) ;
			unmark(i) ;
		}
	}
}


int
main () 
{
	place(8) ;
}
