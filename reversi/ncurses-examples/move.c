#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <ncurses.h>

void rectangle(int y1, int x1, int y2, int x2)
{
	mvhline(y1, x1, 0, x2-x1);
	mvhline(y2, x1, 0, x2-x1);
	mvvline(y1, x1, 0, y2-y1);
	mvvline(y1, x2, 0, y2-y1);
	mvaddch(y1, x1, ACS_ULCORNER);
	mvaddch(y2, x1, ACS_LLCORNER);
	mvaddch(y1, x2, ACS_URCORNER);
	mvaddch(y2, x2, ACS_LRCORNER);
}


int main ()
{
	initscr() ;
	clear() ;

	noecho() ;
	cbreak() ;
	keypad(stdscr, TRUE) ;

	curs_set(2) ;

	rectangle(5,5, 15, 15) ;

	int y = 10, x = 10 ;
	move(10, 10) ;

	refresh() ;

	int c ;
	while (c = getch()) {
		switch (c) {
			case KEY_UP:
				y-- ;
				break ;

			case KEY_DOWN:
				y++ ;
				break ;

			case KEY_LEFT:
				x-- ;
				break ;

			case KEY_RIGHT:
				x++ ;
				break ;

			default:
				if (isalpha(c)) {
					printw("%c", c) ;
				}
				break ;
		}

		move(y, x) ;
		refresh() ;
	}

	endwin() ;
}
