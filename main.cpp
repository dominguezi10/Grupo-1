#include <ncurses.h>
#include "Serpiente.h"
#include <string>
#include <string>
#include <cstdlib>
#include <pthread.h>
#include<unistd.h>
#include <sstream>

using namespace std;
/*DEL EJEMPLO CON INPUT*/
void strat_ncurses(bool useRaw,bool usenoECho);
void printMenu(WINDOW * menu,string choices[],int size,int highlight);
//headers de los metodos.
void imprimirmenu(string);
int main(int argc,char** argv){
	initscr();
	cbreak();
	string Nombre;
	int yMax,xMax;
	getmaxyx(stdscr,yMax,xMax);
	mvprintw(0,0,"BIENVENIDO: POrfavor ingrese su nombre.");
	char ch = getch();
	stringstream ss;
	    while ( ch != '\n' ){
		Nombre.push_back( ch );
		ss<<ch;

		ch = getch();
	    }
	move(1,0);
	printw("%s", ss.str());
	getch();
	noecho();
	
	clear();
	int Resp;
	imprimirmenu(Nombre);
	int movimiento;
	while(true){
		Resp=getch();
		clear();
		//imprimirMenu();
		if (Resp==10){//10 es el codigo ascii del enter.
			mvprintw(0,0,"ingrese movimiento.");
			Resp=getch();
			clear();
			imprimirmenu(Nombre);
		}else{
			imprimirmenu(Nombre);
		}
	}//Fin del while
	getch();
	endwin();
	return 0;
}//Fin del main,

void imprimirmenu(string nombre){
	initscr();
	noecho();
	cbreak();
	//double movimiento=Movimiento;
	int yMax,xMax;
	double c=0;
	getmaxyx(stdscr,yMax,xMax);
	WINDOW * puntuacion=newwin(35,xMax-50,0,50);
	WINDOW * tablero=newwin(35,xMax-12,0,5);
	mvwprintw(tablero,1,1,"JUAGADOR");

	printw("%c", nombre);
	//mvwprintw(tablero,2,10,nombre);
	mvwprintw(tablero,3,3,"Puntos");
	mvwprintw(tablero,3,10,"%",c);
	wrefresh(tablero);
	
	
	wrefresh(tablero);
	box(puntuacion,0,0);
	box(tablero,0,0);
	refresh();
	wrefresh(tablero);
	wrefresh(puntuacion);
}


/*WINDOW * puntuacion=newwin(35,xMax-50,0,50);
	WINDOW * tablero=newwin(35,xMax-12,0,5);
	box(puntuacion,0,0);
	box(tablero,0,0);
	refresh();
	wrefresh(tablero);
	wrefresh(puntuacion);
	keypad(tablero,true);
	string opciones[5]={"1-","2-","3-","4-","5-"};
	int subrayar=0;*/



