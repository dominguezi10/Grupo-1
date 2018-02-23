//Bienvenido
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#ifndef SERPIENTE_H
#define SERPIENTE_H


//Inicio clase
class Serpiente{

    //Atributos
    private:
        string nombreJugador;
        int pixelesComidos;
        int movimientos;
        int puntuacion;
	vector<string> posiciones;


    //metodos publicos
    public:
        //prototipos de metodos
        //constructor
        Serpiente();
        Serpiente(string,int,int,int);

        //metodos accersores / mutadores
        string getNombreJugador();
        void setNombreJugador(string);
        int getPixelesComidos();
        void setPixelesComidos(int);
        int getMovimientos();
        void setMovimientos(int);
        int getPuntuacion();
        void setPuntuacion(int);
	vector <string> getVector();
	void setVector(vector <string>);
	//metodos administrativo
	void anidarPosicion(int, int);
	

    //Destructor
    ~Serpiente();


};//Fin de la clase


#endif
