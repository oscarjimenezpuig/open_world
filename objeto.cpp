// MUNDO_LIBRE 7-6-26

#include"objeto.h"

bool Objeto::set(short ide) {
    if(ide>=0) {
        this->ide=ide;
        return true;
    } else return false;
}

short Objeto::ide_get() {
    return this->ide;
}

void Objeto::info() {
    std::cout<<"IDE: "<<this->ide<<std::endl;
}
