// MUNDO_LIBRE 7-6-26
// Guarda los nombres, adjetivos y descripcion de los objetos

#include "contenedor.hpp"

class Nombre: public Objeto {
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
