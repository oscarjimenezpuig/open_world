// MUNDO_LIBRE 6-6-26

#include "contenedor.hpp"

Array<Contenedor> contenedores;

Contenedor* Contenedor::set(short ide,unsigned short vol,unsigned short pes,unsigned short cap) {
    if(ide>=0) {
        Contenedor c;
        Contenedor* pc=contenedores.insert(c);
        pc->Objeto::set(ide);
        pc->vol=vol;
        pc->pes=pes;
        pc->cap=cap;
        pc->ctn=-1;
        pc->vis=false;
        return pc;
    } else return nullptr;
}

void Contenedor::vis_set(bool v) {
    this->vis=v;
}

unsigned short Contenedor::vol_get() {
    return this->vol;
}

unsigned short Contenedor::pes_get() {
    unsigned int pes=this->pes;
    for(long unsigned int k=0;k<this->con.size();k++) {
        Contenedor* pc=contenedores.get(this->con[k]);
        pes+=pc->pes_get();
    }
    pes=(pes>INF)?INF:pes;
    return (unsigned short)pes;
}

unsigned short Contenedor::cap_get() {
    return this->cap;
}

bool Contenedor::vis_get() {
    return this->vis;
}

short Contenedor::con_has(short ide) {
    short lim=(short)this->con.size();
    for(short k=0;k<lim;k++) if(this->con[k]==ide) return k;
    return -1;
}

unsigned short Contenedor::con_siz() {
    return (unsigned short)this->con.size();
}

short Contenedor::ctn_get() {
    return this->ctn;
}

short Contenedor::inserta(short id) {
    if(id>=0 && id!=this->ide_get()) {
        Contenedor* contenido=contenedores.get(id);
        if(contenido->ctn_get()==-1) {
            if(this->vol==INF || this->vol>contenido->vol) {
                if(this->cap==INF || this->pes_get()+contenido->pes_get()<this->cap+this->pes) {
                    this->con.push_back(id);
                    contenido->ctn=this->Objeto::ide_get();
                    return 0;
                } else return -1;
            } else return -2;
        } else return -3;
    } else return -4;
}

short Contenedor::quita(short id) {
    if(id>=0) {
        Contenedor* contenido=contenedores.get(id);
        if(contenido->ctn==this->Objeto::ide_get()) {
            short pos=this->con_has(id);
            contenido->ctn=-1;
            std::vector<short>::iterator ppos=this->con.begin()+pos;
            this->con.erase(ppos);
            return 0;
        } else return -1;
    } else return -2;
}

void Contenedor::info() {
    Objeto::info();
    std::cout<<"    VOL: "<<this->vol<<" PES: "<<this->pes_get()<<" CAP: "<<this->cap<<std::endl; 
    std::cout<<"    Contenedor: "<<this->ctn<<std::endl;
    std::cout<<"    Contenido: "<<((this->vis)?"(Visible) ":"(No visible) ");
    for(short e:this->con) std::cout<<e<<" ";
    std::cout<<std::endl;
}


