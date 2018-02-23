
#include "Serpiente.h"
#include <iostream>
#include <sstream>

using namespace std;

//Cosntructor 1
Serpiente::Serpiente(string nombreJugador,int pixelesComidos,int movimientos,int puntuacion){
    this->nombreJugador=nombreJugador;
    this->pixelesComidos=pixelesComidos;
    this->movimientos=movimientos;
    this->puntuacion=puntuacion;
}//Fin constructor

//Constructor2
Serpiente::Serpiente(){

}//Fin constructor sencillo

string Serpiente::getNombreJugador(){
    return nombreJugador;
}

void Serpiente:: setNombreJugador(string nombreJugador){

    this->nombreJugador=nombreJugador;

}

int Serpiente::getPixelesComidos(){
    return pixelesComidos;
}

void Serpiente:: setPixelesComidos(int pixelesComidos){

    this->pixelesComidos=pixelesComidos;

}

int Serpiente::getMovimientos(){
    return movimientos;
}

void Serpiente:: setMovimientos(int movimientos){

    this->movimientos=movimientos;

}

int Serpiente::getPuntuacion(){
    return puntuacion;
}

void Serpiente:: setPuntuacion(int puntuacion){

    this->puntuacion=puntuacion;

}

//anadir al vector
void Serpiente:: anidarPosicion(int puntoX, int puntoY){
	stringstream lasPosiciones;
	lasPosiciones << puntoX<< "-"<<puntoY;
	string cadena;
	getline(lasPosiciones, cadena);
	posiciones.push_back(cadena);
}

Serpiente::~Serpiente(){

    cout<<"La instancia de Serpiente fue eliminada";

}
