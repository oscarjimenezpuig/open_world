// MUNDO_LIBRE 11-6-26

#include "basic.hpp"

//OBJETO

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

//NOMBRE

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

//CONTENEDOR

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

//ABRIBLE

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

//HABITACION

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
        







