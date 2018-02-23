#include <ncurses.h>
#include "Serpiente.h"
#include <string>
using namespace std;
/*DEL EJEMPLO CON INPUT*/
void strat_ncurses(bool useRaw,bool usenoECho);
void printMenu(WINDOW * menu,string choices[],int size,int highlight);
int main(int argc,char** argv){


initscr();
noecho();
cbreak();

int yMax,xMax;
getmaxyx(stdscr,yMax,xMax);
WINDOW * puntuacion=newwin(6,xMax-12,yMax-8,5);
WINDOW * tablero=newwin(6,xMax-12,yMax-8,5);
box(puntuacion,0,0);
box(tablero,0,0);
refresh();
wrefresh(tablero);
keypad(tablero,true);
string opciones[5]={"1-","2-","3-","4-","5-"};
int subrayar=0;
int Resp;
while(true){
	Resp=getch();
	if (Resp==10){//10 es el codigo ascii del enter.
		printw("PUEDE REALIZAR SU MOVIMIENTO.");
		Resp=getch();
		if (!(Resp!='w'&&Resp!='a'&&Resp!='s'&&Resp!='d')){	
			switch(Resp){
				case KEY_UP:{
					subrayar--;
					if(subrayar==-1){
						subrayar=0;
					}
					break;
					    }
				case KEY_DOWN:{
					subrayar++;
					if(subrayar==5){
						subrayar=4;
					}
					break;
					      }
				default:
		
					break;
			}//Fin del switch

		}
		
	}else{//NO presiono enter
		printw("Tecla INVALIDA.");
	}
	
}//Fin del while
	printw("Tu eleccion fue: %s",opciones[subrayar].c_str());
	getch();
	endwin();
	return 0;
}
