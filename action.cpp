#include "action.hpp"

std::map<std::string,Action::Function> actmap; //map que guarda las acciones por su nombre(que es la key)

short Action::set(std::string n,Action::Function f) {
    if(actmap.insert(std::pair{n,f}).second) return 0;
    else return -1;
}

short Action::set(std::vector<std::string> names,Action::Function f) {
    short res=0;
    for(auto e:names) res+=set(e,f);
    return res;
}   

Action::Function Action::get(std::string n) {
    std::map<std::string,Action::Function>::iterator pf=actmap.find(n);
    if(pf==actmap.end()) return nullptr;
    else return pf->second;
}
    
