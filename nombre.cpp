// MUNDO_LIBRE 7-6-26

#include "nombre.h"

Array<Nombre> nombres;

Nombre* Nombre::set(short ide,std::string n,std::string a,std::string d) {
    if(ide>=0) {
        Nombre nn;
        Nombre* pn=nombres.insert(nn);
        pn->Objeto::set(ide);
        pn->nom=n;
        pn->adj=a;
        pn->dsc=d;
        return pn;
    } else return nullptr;
}

void Nombre::dsc_set(std::string d) {
    this->dsc=d;
}

std::string Nombre::nom_get() {
    return this->nom;
}

std::string Nombre::adj_get() {
    return this->adj;
}

std::string Nombre::dsc_get() {
    return this->dsc;
}

void Nombre::info() {
    this->Objeto::info();
    std::cout<<"    "<<this->nom<<" "<<this->adj<<": "<<this->dsc<<std::endl;
}



//PRUEBA

int main() {
    Nombre* a=Nombre::set(0,"Oscar");
    Nombre* b=Nombre::set(1,"Patricio Lopez");
    Nombre* c=Nombre::set(2,"Pico","Famulo","Es un tio bien plantado");
    nombres.info();
    return 0;
}

      
