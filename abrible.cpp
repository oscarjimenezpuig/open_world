// MUNDO_LIBRE 9-6-26

#include "abrible.hpp"

Array<Abrible> abribles;

Abrible* Abrible::set(short ide,bool o,short k) {
    Abrible* pa=nullptr;
    if(ide>=0) {
        Abrible a;
        pa=abribles.insert(a);
        pa->Objeto::set(ide);
        pa->opn=o;
        pa->key=k;
        pa->ibr=-1;
    }
    return pa;
}

Abrible* Abrible::bro(short ide,short bro) {
    Abrible* ab=abribles.get(bro);
    Abrible* pa=nullptr;
    if(ab && ab->ibr==-1) {
        pa=Abrible::set(ide,ab->opn,ab->key);
        if(pa) {
            pa->ibr=ab->ide_get();
            ab->ibr=ide;
        }
    }
    return pa;
}

short Abrible::abrir(short key) {
    if(this->opn==false) {
        if(this->key==-1 || this->key==key) {
            this->opn=true;
            Abrible* pa=abribles.get(this->ibr);
            if(pa) pa->opn=true;
            return 0;
        } else return -2;
    } else return -1;
}

short Abrible::cerrar() {
    if(this->opn==true) {
        this->opn=false;
        Abrible* pa=abribles.get(this->ibr);
        if(pa) pa->opn=false;
        return 0;
    } else return -1;
}

void Abrible::info() {
    this->Objeto::info();
    std::cout<<"    OPN: "<<this->opn<<" KEY: "<<this->key<<" BRO: "<<this->ibr<<std::endl;
}
        


