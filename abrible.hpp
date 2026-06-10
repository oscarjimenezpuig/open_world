// MUNDO_LIBRE 9-6-26
// Clase abrible con todo los metodos y almacenamiento

#include "objeto.hpp"

class Abrible:public Objeto {
    private:
        short key; //identificador de llave si tiene
        bool opn; //dice si esta o no abierta;
        short ibr; //abrible hermano que va en consonancia en todo
    public:
        static Abrible* set(short ide,bool open=1,short key=-1); //creacion de un nuevo abrible
        static Abrible* bro(short ide,short bro);//se crea un abrible hermano a bro con ide ide (bro ha de existir)
        short abrir(short key=-1); //abrir un abrible (con o sin llave)
                               //0: correcto
                               //-1: ya abierta
                               //-2: llave no coincide
        short cerrar(); //cerrar un abrible
                        //0: correcto
                        //-1: ya cerrada
        void info(); //informacion del estado del abrible
};

extern Array<Abrible> abribles;
//se guardan todos los abribles
