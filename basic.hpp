// MUNDO_LIBRE 11-6-26

//INCLUDES

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <utility>
#include <cstdint>
#include <map>

//CONSTANTES

constexpr unsigned short ARRDIM=256; // maxima dimension de objetos contenidos en un array
constexpr unsigned short INF=65535; //valor maximo considerado infinito de unsigned short

//TEMPLATES

// Templates utilizados en el programa

//template Array que guarda objetos por el identificador ide.

template<typename T>
class Array {
    private:
        T data[ARRDIM];
        T* ptr=data;
    public:
        unsigned short siz() {
            return data.size();
        }
        T* insert(T d) {
            T* pdata=nullptr;
            if(ptr!=data+ARRDIM) {
                pdata=ptr;
                *ptr++=d;
            }
            return pdata;
        }
        T* get(short ide) {
            for(T* p=data;p!=ptr;p++) if(p->ide_get()==ide) return p;
            return nullptr;
        }
        void info() {
            for(T* p=data;p!=ptr;p++) p->info();
        }
};

//IDENTIFICABLE

//clase que contiene la identidad y metodos para obtenerla

class Identificable {
    protected:
        short ide;
    public:
        short ide_get();
        void info();
};

//CONTENEDOR

// Clase contenedor con todo los metodos y almacenamiento.
// Un contenedor puede ser o no un objeto, si no lo es, no puede ser contenido.

class Contenedor:public Identificable {
    private:
        unsigned short cap; //capacidad (peso total soportado
        std::vector<short> con; //vector del contenido
    public:
        bool vis; //dice si el contenido es visible o no
        static Contenedor* set(short ide,unsigned short cap);
        void vis_set(bool vis); //establecemos el valor de la variable vis
        unsigned short cap_get(); //capacidad total
        unsigned short pec_get(); //obtenemos peso de todo el contenido
        bool vis_get(); //conseguimos el valor de la variable vis
        short con_has(short ide); //mira si un objeto ide esta contenido (devuelve el indice o -1 si no encontrado)
        unsigned short con_siz(); //numero de objetos contenidos
        short inserta(short id); //El contenedor recibe un objeto
                             //0: Insercion correcta
                             //-1: Exceso peso
                             //-2: Objeto ya contenido
                             //-3: No es objeto
                             //-4: Identificador no valido
        short quita(short id); //quita un contenido
                               //0: quitado correcto
                               //-1: no poseido por este contenedor
                               //-2: id no valido
        void info(); //muestra informacion
};

extern Array<Contenedor> contenedores;
//contiene todos los contenedores definidos

//OBJETO

//Objeto es una clase que contiene los de peso y del contenedor
//Un objeto puede ser contenido, si tambien es contenedor puede contener

class Objeto: public Identificable{
    private:
        unsigned short pes; //guarda el peso
        unsigned short cnt; //identidad del contenedor que lo contiene
    public:
        static Objeto* set(short ide,unsigned short pes); //crea un nuevo objeto
        unsigned short pes_get(); //conseguimos el peso del objeto (teniendo en cuenta si es contenedor)
        short ctn_get(); //conseguimos el contenedor
        void info(); //muestra informacion (solo la identidad)
        friend Contenedor;
};

extern Array<Objeto> objetos;
//guarda todos los objetos

//NOMBRE

// Guarda los nombres, adjetivos y descripcion de los objetos

class Nombre: public Identificable {
    private:
        std::string nom; //nombre (obligatorio, diferente de vacio)
        std::string adj; //adjetivo o complemento del nombre (no obligatorio)
        std::string dsc; //descripcion (no obligatorio)
    public:
        static Nombre* set(short ide,std::string nombre,std::string adjetivo="",std::string descripcion="");
        void dsc_set(std::string d); //funcion que cambia la descripcion
        std::string nom_get(); //nombre
        std::string adj_get(); //adjetivo
        std::string dsc_get(); //descripcion
        void info(); //muestra informacion
};

extern Array<Nombre> nombres;
//contiene todos los nombres definidos

//ABRIBLE

// Clase abrible con todo los metodos y almacenamiento

class Abrible:public Identificable {
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

//HABITACION

// Clase habitacion con todo los metodos y almacenamiento

class Salida:public Identificable {
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

class Habitacion:public Identificable {
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

//PSI

// Clase psi que contiene todas las ordenes posibles

class Psi:public Objeto {
    private:
        std::int8_t agr; //indica el nivel de agresividad del psi
        std::int8_t vid; //indica el nivel de vida del psi
        std::int8_t ata; //indica el nivel de ataque del psi
        std::int8_t def; //indica el nivel de defensa del psi
        std::int8_t com; //indica el nivel de comida de un psi

};

extern Array<Psi> psis;
//guarda todos los psis posibles


