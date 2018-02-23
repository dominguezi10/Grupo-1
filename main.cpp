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
void imprimirmenu(string,int);
int movimientos(int,int);
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
	noecho();
	
	clear();
	int Resp=0;
	int m_viejo=0;
	int mov_actual=0;
	int movimiento=0;
	imprimirmenu(Nombre,movimiento);
	while(true){
		Resp=getch();
		clear();
		//imprimirMenu();
		if (Resp==10){//10 es el codigo ascii del enter.
			
			mvprintw(0,0,"ingrese movimiento.");
			
			imprimirmenu(Nombre,movimiento);
			Resp=getch();
			//Resp=getch();
			m_viejo=mov_actual;
			mov_actual=movimientos(movimiento,Resp);
			if(mov_actual==-1){
				mov_actual=m_viejo;
			//sleep(5);//tarda 5 segs en seguir
			}else{
				movimiento++;
		}
			
			//movimiento=movimientos(movimiento,Resp);
		}else{
			imprimirmenu(Nombre,movimiento);
		}
	}//Fin del while
	getch();
	endwin();
	return 0;
}//Fin del main,

void imprimirmenu(string nombre, int movimiento){
	initscr();
	noecho();
	cbreak();
	clear();
	//double movimiento=Movimiento;
	int yMax,xMax;
	double c=0;
	string mvs="-"+movimiento;
	getmaxyx(stdscr,yMax,xMax);
	WINDOW * puntuacion=newwin(35,xMax-50,0,50);
	WINDOW * tablero=newwin(35,xMax-12,0,5);
	mvwprintw(tablero,1,1,"JUAGADOR");
	mvwprintw(tablero,2,1,nombre.c_str());
	//mvwprintw(tablero,2,10,nombre);
	mvwprintw(tablero,3,3,"MOVIMIENTOS");
	//mvwprintw(tablero,3,10,"%",c);
	mvwprintw(tablero,4,1,mvs.c_str());
	wrefresh(tablero);
	wrefresh(tablero);
	box(puntuacion,0,0);
	box(tablero,0,0);
	refresh();
	wrefresh(tablero);
	wrefresh(puntuacion);
}
int movimientos(int m,int Resp){
	switch(Resp){
		case 'w':{
			mvprintw(0,0,"A");
			return 1;
			break;
			}
		case 's':{
			mvprintw(0,0,"Ab");
			return 2;
			break;
			}
		case 'a':{
			mvprintw(0,0,"IZ");
			return 3;			
			break;
			}
		case 'd':{
			mvprintw(0,0,"DE");
			return 4;
			break;
			}
		default:{
			mvprintw(0,0,"INV");
			return -1;
			break;
			}
	}

}
//addstr(ss.str());
	//printw(Nombre.c_str());
	//getch();

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



