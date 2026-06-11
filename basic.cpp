// MUNDO_LIBRE 11-6-26

#include "basic.hpp"

//IDENTIFICABLE

short Identificable::ide_get() {
    return this->ide;
}

void Identificable::info() {
    std::cout<<"IDE: "<<this->ide<<std::endl;
}

//CONTENEDOR

Array<Contenedor> contenedores;

Contenedor* Contenedor::set(short ide,unsigned short cap) {
    if(ide>=0) {
        Contenedor c;
        Contenedor* pc=contenedores.insert(c);
        pc->ide=ide;
        pc->cap=cap;
        pc->vis=false;
        return pc;
    } else return nullptr;
}

static unsigned short adpes(unsigned short a,unsigned short b) {
    unsigned int r=a+b;
    if(r>=INF) return INF;
    else return (unsigned short)(a+b);
}

unsigned short Contenedor::pec_get() {
    unsigned short pes=0;
    for(auto e:this->con) {
        Objeto* o=objetos.get(e);
        pes=adpes(pes,o->pes);
        Contenedor* c=contenedores.get(e);
        if(c) {
            pes=adpes(pes,c->pec_get());
        }
    }
    return pes;
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

short Contenedor::inserta(short id) {
    if(id>=0 && id!=this->ide_get()) {
        Objeto* o=objetos.get(id);
        if(o) {
            if(o->cnt==-1) {
                unsigned short po=o->pes_get();
                unsigned short pa=this->pec_get();
                if(pa+po<=this->cap) {
                    this->con.push_back(id);
                    o->cnt=this->ide;
                    return 0;
                } else return -1;
            } else return -2;
        } else return -3;
    } else return -4;
}

short Contenedor::quita(short id) {
    if(id>=0) {
        Contenedor* contenido=contenedores.get(id);
        if(contenido->ctn==this->Identificable::ide_get()) {
            short pos=this->con_has(id);
            contenido->ctn=-1;
            std::vector<short>::iterator ppos=this->con.begin()+pos;
            this->con.erase(ppos);
            return 0;
        } else return -1;
    } else return -2;
}

void Contenedor::info() {
    Identificable::info();
    std::cout<<"    VOL: "<<this->vol<<" PES: "<<this->pes_get()<<" CAP: "<<this->cap<<std::endl; 
    std::cout<<"    Contenedor: "<<this->ctn<<std::endl;
    std::cout<<"    Contenido: "<<((this->vis)?"(Visible) ":"(No visible) ");
    for(short e:this->con) std::cout<<e<<" ";
    std::cout<<std::endl;
}

//OBJETO

Array<Objeto> objetos;

Objeto* Objeto::set(short ide,unsigned short pes) {
    Objeto* po=nullptr;
    if(ide>=0) {
        Objeto o;
        po=objetos.insert(o);
        po->ide=ide;
        po->pes=pes;
        po->ctn=-1;
    }
    return po;
}

unsigned short Objeto::pes_get() {
    unsigned short pes=this->pes;
    Contenedor* c=contenedores.get(this->ide);
    if(c) pes=adpes(pes,c->get_pes());
    return pes;
}

short Objeto::ctn_get() {
    return this->ctn;
}

void Objeto::info() {
    this->Identificable::info();
    std::cout<<"    PES: "<<this->pes<<" CTN: "<<this->ctn<<std::endl;
}

//NOMBRE

Array<Nombre> nombres;

Nombre* Nombre::set(short ide,std::string n,std::string a,std::string d) {
    if(ide>=0) {
        Nombre nn;
        Nombre* pn=nombres.insert(nn);
        pn->ide=ide;
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
    this->Identificable::info();
    std::cout<<"    "<<this->nom<<" "<<this->adj<<": "<<this->dsc<<std::endl;
}


//ABRIBLE

Array<Abrible> abribles;

Abrible* Abrible::set(short ide,bool o,short k) {
    Abrible* pa=nullptr;
    if(ide>=0) {
        Abrible a;
        pa=abribles.insert(a);
        pa->ide=ide;
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
    this->Identificable::info();
    std::cout<<"    OPN: "<<this->opn<<" KEY: "<<this->key<<" BRO: "<<this->ibr<<std::endl;
}

//HABITACION

Array<Salida> salidas;

Salida* Salida::set(short ide,std::string n) {
    Salida* ps=nullptr;
    if(ide>=0) {
        Salida s;
        ps=salidas.insert(s);
        ps->ide=ide;
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
    this->Identificable::info();
    std::cout<<"    "<<this->nom<<" CON: "<<this->con<<std::endl;
}

Array<Habitacion> habitaciones;

Habitacion* Habitacion::set(short ide,unsigned char sals) {
    Habitacion* ph=nullptr;
    if(ide>=0) {
        Habitacion h;
        ph=habitaciones.insert(h);
        ph->ide=ide;
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
   this->Identificable::info();
   std::cout<<"    SLS: "<<this->sal.size()<<std::endl;
   for(const auto &e : this->sal) {
       std::cout<<"    SAL: "<<e.first<<" DST: "<<e.second<<std::endl;
    }
}
        







