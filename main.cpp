#include "basic.hpp"

//PRUEBA

int main() {
    Salida* s=Salida::set(0,"NORTE");
    Salida* t=Salida::set(1,"SUR");
    s->con_set(1);
    Habitacion* h=Habitacion::set(2,2);
    Habitacion* i=Habitacion::set(3,2);
    Habitacion* j=Habitacion::set(4,2);
    std::cout<<h->set_sal(0,3,true)<<i->set_sal(0,4,true)<<std::endl;
    salidas.info();
    habitaciones.info();
    return 0;
}

  
