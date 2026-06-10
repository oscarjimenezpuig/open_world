// MUNDO_LIBRE 9-6-26

#include "habitacion.hpp"

Array<Salida> salidas;

Salida* Salida::set(short ide,std::string n) {
    Salida* ps=nullptr;
    if(ide>=0) {
        Salida s;
        ps=salidas.insert(s);
        ps->Objeto::set(ide);
        ps->nom=n;
        ps->con=-1;
    }
    return ps;
}

bool Salida::con_set(short ide) {
    if(this->con==-1) {
        Salida* sc=salidas.get(ide);
        if(sc && sc->con==-1) {
            sc->con=this->ide_get();
            this->con=ide;
            return true;
        }
    }
    return false;
}

short Salida::con_get() {
    return this->con;
}

void Salida::info() {
    this->Objeto::info();
    std::cout<<"    "<<this->nom<<" CON: "<<this->con<<std::endl;
}

Array<Habitacion> habitaciones;

Habitacion* Habitacion::set(short ide,unsigned char sals) {
    Habitacion* ph=nullptr;
    if(ide>=0) {
        Habitacion h;
        ph=habitaciones.insert(h);
        ph->Objeto::set(ide);
        ph->sal.reserve(sals);
    }
    return ph;
}

static short fnd_sal(std::vector<std::pair<short,short>> v,short sal) {
    for(const auto &e:v) if(e.first==sal) return e.second;
    return -1;
}

short Habitacion::set_sal(short sal,short dir,bool bid) {
    Salida* s=salidas.get(sal);
    Habitacion* h=habitaciones.get(dir);
    if(s && h) {
        short ps=fnd_sal(this->sal,sal);
        if(ps==-1) {
            this->sal.push_back(std::make_pair(sal,dir));
            if(bid && s->con_get()!=-1) {
                Salida* cs=salidas.get(s->con_get());
                if(cs) {
                    short pcs=fnd_sal(h->sal,s->con_get());
                    if(pcs==-1) {
                        h->sal.push_back(std::make_pair(s->con_get(),this->ide_get()));
                        return 0;
                    } else return -4;
                } else return -3;
            } else return 0;
        } else return -2;
    } else return -1;
}
    
short Habitacion::get_sal(short sal) {
    return fnd_sal(this->sal,sal);
}

void Habitacion::info() {
   this->Objeto::info();
   std::cout<<"    SLS: "<<this->sal.size()<<std::endl;
   for(const auto &e : this->sal) {
       std::cout<<"    SAL: "<<e.first<<" DST: "<<e.second<<std::endl;
    }
}
                
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

             
    

    
       

