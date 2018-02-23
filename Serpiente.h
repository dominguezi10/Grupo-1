//Bienvenido
#include <string>
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

    //Destructor
    ~Serpiente();


};//Fin de la clase


#endif