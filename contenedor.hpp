// MUNDO_LIBRE 6-6-26
// Clase contenedor con todo los metodos y almacenamiento

#include "objeto.hpp"

constexpr unsigned short INF=65535;

class Contenedor:public Objeto {
    private:
        unsigned short vol; //volumen
        unsigned short pes; //peso
        unsigned short cap; //capacidad (peso total soportado
        short ctn; //contenedor
        std::vector<short> con; //vector del contenido
        bool vis; //dice si el contenido es visible o no
    public:
        static Contenedor* set(short ide,unsigned short vol,unsigned short pes,unsigned short cap);
        void vis_set(bool vis); //establecemos el valor de la variable vis
        unsigned short vol_get(); //volumen
        unsigned short pes_get(); //peso total, con el contenido incluido
        unsigned short cap_get(); //capacidad total
        bool vis_get(); //conseguimos el valor de la variable vis
        short con_has(short ide); //mira si un objeto ide esta contenido (devuelve el indice o -1 si no encontrado)
        unsigned short con_siz(); //numero de objetos contenidos
        short ctn_get(); //identidad del contenedor
        short inserta(short id); //El objeto recibe un contenedor
                             //0: Insercion correcta
                             //-1: Exceso de peso
                             //-2: Exceso de volumen
                             //-3: El contenido id ya tiene contenedor
                             //-4: id no valido
        short quita(short id); //quita un contenedor
                               //0: quitado correcto
                               //-1: no poseido por este contenedor
                               //-2: id no valido
        void info(); //muestra informacion
};


extern Array<Contenedor> contenedores;
//contiene todos los contenedores definidos

