#include <ncurses.h>
#include "Serpiente.h"
#include <string>
#include <string>
#include <cstdlib>
#include <pthread.h>
#include<unistd.h>
#include <sstream>
#include <vector>
using namespace std;

//prototipo 
int posicionesPuntoRojo();

// crear maatriz
string** provisionarMatriz(int);

//liberar matriz
void liberarMatriz(string**&, int);

//evaluar
int evaluarMatriz(string**, int);


//imprimir
string impresion(string** , int);

//llenar
void llenar(string**&,int , int );

//---------------------------------------

int mover(int,int,string**&,Serpiente *);
int crecer(string**&, int, int, int);

/*DEL EJEMPLO CON INPUT*/
void strat_ncurses(bool useRaw,bool usenoECho);
void printMenu(WINDOW * menu,string choices[],int size,int highlight);
//headers de los metodos.
void imprimirmenu(string,int,string);
int movimientos(int,int);
int main(int argc,char** argv){
	Serpiente * snake;
	string** matriz;
	int condicion = 0;
	int puntoX = 0;
	int puntoY = 0;
	matriz = provisionarMatriz(10);
	puntoX = posicionesPuntoRojo();
	puntoY = posicionesPuntoRojo();
	llenar(matriz,puntoX, puntoY);

	string tablero;
	tablero = impresion(matriz, 10);


	for(int i = 0; i<10; i++){
		for(int j=0; j<10; j++){
			matriz[i][j] = " ";
		}
		puntoX = posicionesPuntoRojo();
		puntoY = posicionesPuntoRojo(); 

	}

	matriz[puntoX][puntoY] = "*";

	initscr();
	cbreak();
	string Nombre;
	int yMax,xMax;
	getmaxyx(stdscr,yMax,xMax);
	mvprintw(0,0,"BIENVENIDO: Porfavor ingrese su nombre.");
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
	int gano;
	int Resp=0;
	int m_viejo=0;
	int mov_actual=0;
	int movimiento=0;
	//snake= new Serpiente(Nombre,0,movimientos,0);
	snake= new Serpiente();
	vector <string> gusano;
		for (int i=0;i<5;i++){
			gusano.push_back("G");		
		}
	imprimirmenu(Nombre,movimiento,tablero);
	while(true){
		Resp=getch();
		clear();
		//imprimirMenu();
		if (Resp==10){//10 es el codigo ascii del enter.
			   int i;

			    initscr();

			    curs_set(0);

			    for (i = 40; i <= 80; i++)
			    {
				mvaddch(10, i, ' ');
				refresh();
				mvaddch(10, i+1, 'G');
				refresh();
				napms(100);
			    }

			    curs_set(1);
			    mvaddstr(0, 0, "OH NO PERDIO :C SORRY HERBERT....");
			    refresh();
			    getch();

			    endwin();
						clear();
			mvprintw(0,0,"ingrese movimiento.");
			Resp=getch();
			imprimirmenu(Nombre,movimiento,tablero);
			//Resp=getch();
			m_viejo=mov_actual;
			mov_actual=movimientos(movimiento,Resp);
			if(mov_actual==-1){
				mov_actual=m_viejo;			
			}else{
				gano=mover(gusano.size(),mov_actual,matriz,snake);
				movimiento++;
		}
			//movimiento=movimientos(movimiento,Resp);
		}else{
			imprimirmenu(Nombre,movimiento,tablero);
		}
		if(gano==-1){
			mvprintw(0,0,"OH NO! PERDIO");
			break;
		}else{
			imprimirmenu(Nombre,movimiento,tablero);
		}

	}//Fin del while
	getch();
	endwin();

	//liberar matriz
	liberarMatriz(matriz, 10);
	return 0;
}//Fin del main,

void imprimirmenu(string nombre, int movimiento,string snake){
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
	mvwprintw(puntuacion,1,1,snake.c_str());
	//mvwprintw(tablero,3,10,"%",c);
	mvwprintw(tablero,4,4,mvs.c_str());
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

int posicionesPuntoRojo(){
	int posicion = 0;
	posicion = rand()%9;

	return posicion;
}

//provisionar matriz  size x size
string** provisionarMatriz(int size){
	string** retValue = new string*[size];
	
	for(int i =0; i<size; i++){
		retValue[i] = new string[size];

	}


	return retValue;

}// fin del metodo provicionar matriz

void liberarMatriz(string**& matriz, int size){
	for(int i = 0; i<size; i++){
		delete[] matriz[i];// sin los corchetes solo se  borra la 1era casilla
		matriz[i] = NULL;
	}// fin del for

	cout<< "Liberado"<< endl;
	delete[] matriz;
	matriz = NULL;
}// fin del metodo

//evaluar matriz
int evaluarMatriz(string** matriz, int size){
	int contador =0;
	for(int i =0; i<size; i++){
		for(int j =0; j<size; j++){
			if(matriz[i][j] != " "){
				contador++;	
			}

		}

	}

	return contador;
}// fin de evaluar


string impresion(string** matriz,int size){
	stringstream salida;
	for(int i =0; i<size; i++){
		for(int j =0; j<size; j++){
			salida<< matriz[i][j];

		}
		salida<< "\n";

	}
	
	string totalSalida;
	getline(salida, totalSalida);
	return salida.str();
}

//lenar
void llenar(string**& matriz, int puntoX, int puntoY){
	for(int i = 0; i<10; i++){
		for(int j=0; j<10; j++){
			matriz[i][j] = " ";
		}
	}
	matriz[puntoX][puntoY] = "*";
}
	
int mover(int size,int direccion,string**& Matriz,Serpiente * snake){
	vector <string> pos=snake->getVector();
	vector <string> Nuevo;
	string x=pos[0].at(0)+"";
	string y=pos[0].at(2)+""; 
	int X=atoi(x.c_str());
	int Y=atoi(y.c_str());
	if (crecer(Matriz,X,Y,direccion)!=-1){
		if(direccion==2){//arriba
				for(int i=0; i<size-1;i++){
					Matriz[X][Y+i]="G";
				}
				return 0;
			}else if(direccion==1){//abajo
				for(int i=0; i<size-1;i++){
					Matriz[X][Y-i]="G";
				}
				return 0;
			}else if(direccion==4){//izq
				for(int i=0; i<size-1;i++){
					Matriz[X-i][Y]="G";
				}
				return 0;
			}else if(direccion==3){//derecha
				for(int i=0; i<size-1;i++){
					Matriz[X+i][Y]="G";
				}
			return 0;
		}			
	}else{
		return -1;
	}//del if
}//fin dle metodo


//crece

int crecer(string**& matriz, int posX, int posY, int direccion){
	//int error = 0;
	switch(direccion){
		case 1:
			{
			if((posY-1)<0 ){
				return -1;
			}	
				break;
			}			
		case 2:{
			if((posY+1)>9 ){
				return -1;
			}
			break;
			}
		case 3:{
			if((posX-1)<0){
				return -1;
			}
			
			break;}

		case 4:{
			if((posX+1)>9){
				return -1;
			}
		break;}
	}
	
}

// metodo crecer

//-----------------------



/*movimientos(int m,int Resp){
>>>>>>> edf46cd34477babe289e8689d2652367608f11dd
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



