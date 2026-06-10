// MUNDO_LIBRE 7-6-26

//Objeto es una clase que solo contiene la identidad, todas las clases la contienen

#include "template.hpp"

class Objeto{
    private:
        short ide; //guarda identificador
    public:
        bool set(short ide); //crea un nuevo objeto
        short ide_get(); //muestra identificador
        void info(); //muestra informacion (solo la identidad)
};

