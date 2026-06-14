// MUNDO LIBRE 13-6-26

//se definen lo que es una accion y se guardan todas las acciones en un array


#include "basic.hpp"

namespace Action {

    typedef short (*Function)(short,std::vector<short>); //accion es una funcion que devuelve un resultado y le entra id del objeto que hace la accion y complementos

    short set(std::string name,Function function);
    //se introduce una nueva accion asociada a un nombre 0 si correcto, -1 incorrecto

    short set(std::vector<std::string> names,Function function);
    //multiples nombres que van a parar directamente a la funcion, 0 si todos correctos, negativo por cada entrada no valida

    Function get(std::string name);
    //a partir del nombre se consigue la funcion

}
