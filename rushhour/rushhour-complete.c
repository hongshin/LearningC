#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	start,
	left,
	right,
	up,
	down,
	quit,
	N_op 
} commands ;

typedef enum {
	vertical,
	horizontal 
} direction ;

typedef struct {
	int id ;
	int y1, y2 ;
	int x1, x2 ;
	int span ;
	direction dir ;
} car_t ;

char * op_str[N_op] = {
	"start",
	"left",
	"right",
	"up",
	"down",
	"quit"
} ;

int n_cars = 0 ;
car_t * cars = 0x0 ;
int cells[6][6] ;

commands
get_op_code (char * s)
{
	int i ;
	for (i = 0 ; i < N_op ; i++) {
		if (strcmp(op_str[i], s) == 0)
			return i ;
	}
	return -1 ;
}

int
load_game (char * filename)
{
	char * buf ;
	size_t n_buf ;
	int i, len ;

	buf = malloc(1024) ;
	n_buf = 1024 ;

	FILE * fp = fopen(filename, "r") ;

	fscanf(fp, "%d", &n_cars) ;
	cars = (car_t *) malloc(
		sizeof(car_t) * (n_cars + 1)) ;
	getline(&buf, &n_buf, fp) ;
	
	for (i = 1 ; i <= n_cars ; i++) {
		char * id, * dir, *length ;

		len = getline(&buf, &n_buf, fp) ;

		cars[i].id = i ;

		id = strtok(buf, ":\n") ;
		cars[i].x1 = id[0] - 'A' ;
		cars[i].y2 = id[1] - '1' ;

		dir = strtok(0x0, ":\n") ;
		if (strcmp(dir, "vertical") == 0) 
			cars[i].dir = vertical ;
		else 
			cars[i].dir = horizontal ;		

		length = strtok(0x0, ":\n") ;
		cars[i].span = atoi(length) ;
		if (cars[i].dir == vertical) {
			cars[i].x2 = cars[i].x1 ;
			cars[i].y1 = cars[i].y2 - cars[i].span + 1 ;
		}
		else {
			cars[i].x2 = cars[i].x1 + cars[i].span - 1 ;
			cars[i].y1 = cars[i].y2 ;
		}
	}

	return 0 ;
}

void
display ()
{
	int y, x ;
	for (y = 5 ; y >= 0 ; y--) {
		for (x = 0 ; x < 6 ; x++) 
			if (cells[y][x] == 0) 
				printf(" +") ;
			else 
				printf(" %d", cells[y][x]) ;
		printf("\n") ;
	}
}

int 
update_cells ()
{
	memset(cells, 0, sizeof(int) * 36) ;

	for (int id = 1 ; id <= n_cars ; id++) {
		for (int y = cars[id].y1 ; y <= cars[id].y2 ; y++) {
			for (int x = cars[id].x1 ; x <= cars[id].x2 ; x++) {
				if (cells[y][x] != 0)
					return 1 ;
				cells[y][x] = cars[id].id ;
			}
		}
	}
	return 0 ;
}

int
move (int id, int op) 
{
	if (cars[id].dir == vertical && (op == right || op == left))
		return 1 ;
	if (cars[id].dir == horizontal && (op == up || op == down))
		return 1 ;

	if (cars[id].dir == vertical) {
		if (op == up) {
			if (cars[id].y2 == 5 || cells[cars[id].y2+1][cars[id].x1] != 0)
				return 2 ;
			cars[id].y1 += 1 ;
			cars[id].y2 += 1 ;
		}
		else /* op == down */ {
			if (cars[id].y1 == 0 || cells[cars[id].y1-1][cars[id].x1] != 0)
				return 2 ;
			cars[id].y1 -= 1 ;
			cars[id].y2 -= 1 ;
		}
	}
	else /* cars[id].dir == horizontal */ {
		if (op == right) {
			if (cars[id].x2 == 5 || cells[cars[id].y1][cars[id].x2+1] != 0)
				return 2 ;
			cars[id].x1 += 1 ;
			cars[id].x2 += 1 ;
		}
		else /* op == left */ {
			if (cars[id].x1 == 0 || cells[cars[id].y1][cars[id].x1-1] != 0)
				return 2 ;
			cars[id].x1 -= 1 ;
			cars[id].x2 -= 1 ;
		}
	}

	return 0 ;
}

int
main ()
{
	char buf[128] ;
	int op ;
	int id ;

	while (1) {
		scanf("%127s", buf) ;

		switch (op = get_op_code(buf)) {
			case quit:
				exit(0) ;

			case start:
				scanf("%s", buf) ;

				load_game(buf) ;
				update_cells() ;
				display() ;
				break ;

			case left:
			case right:
			case up:
			case down:
				scanf("%d", &id) ;
				
				if (cars == 0x0)
					break ;

				move(id, op) ;
				update_cells() ;
				display() ;
				if (cells[3][5] == 1) {
					printf("Done.\n") ;
					exit(0) ;
				}
				break ;

			default:
				break ;
				
		}
	}
}
