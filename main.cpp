#include "action.hpp"

using namespace std;

//PRUEBA

short f_a(short id=0, vector<short> dat={}) {
    cout<<"Hola"<<endl;
    return 0;
}

short f_b(short id=0,vector<short> dat={}) {
    cout<<"Adios"<<endl;
    return 0;
}

int main() {
    vector<string> wds={"Hola","Ho"};
    Action::set(wds,f_a);
    Action::set("Adios",f_b);
    Action::Function f=Action::get("Ho");
    if(f) f(0,{});
    else cout<<"No hay funcion"<<endl;
    return 0;
}

  
