// MUNDO_LIBRE 9-6-26
// Clase habitacion con todo los metodos y almacenamiento

#include "objeto.hpp"

class Salida:public Objeto {
    private:
        std::string nom; //nombre de la salida
        short con; //identidad de la contrasalida (si existe)
    public:
        static Salida* set(short ide,std::string nom);
        bool con_set(short ide); //se define contrasalida, necesario que exista la contra salida y no sea contrasalida de nadie
        short con_get();//se consigue la contrasalida
        void info();
};

extern Array<Salida> salidas;
//guarda todas las salidas disponibles

class Habitacion:public Objeto {
    private:
        std::vector<std::pair<short,short>> sal; //variable que guarda la identidad de la salida con la identidad del destino
    public:
        static Habitacion* set(short ide,unsigned char sals); //definimos una habitacion reservando espacio para las salidas
        short set_sal(short sal,short dir,bool bid=false); //definimos una nueva salida con su llegada (han de existir ambas) posibilidad de establecer contradireccion 
                                                           //0: correcto
                                                           //-1: habitacion o salida no definida
                                                           //-2: salida ya usada
                                                           //-3: no existe contrasalida
                                                           //-4: contrasalida ya usada
        short get_sal(short sal); //a partir del identificador de la salida sd da la llegada
        void info(); //informacion de la salida
};

extern Array<Habitacion> habitaciones;
//guarda todas las habitaciones disponibles
