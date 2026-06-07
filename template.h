// MUNDO_LIBRE 6-6-26
// Templates utilizados en el programa

#include "aventura.h"

//template Array que guarda objetos por el identificador ide.

constexpr unsigned short ARRDIM=256; // maxima dimension de objetos contenidos en un array

template<typename T>
class Array {
    private:
        T data[ARRDIM];
        T* ptr=data;
    public:
        unsigned short siz() {
            return data.size();
        }
        T* insert(T d) {
            T* pdata=nullptr;
            if(ptr!=data+ARRDIM) {
                pdata=ptr;
                *ptr++=d;
            }
            return pdata;
        }
        T* get(short ide) {
            for(T* p=data;p!=ptr;p++) if(p->ide_get()==ide) return p;
            return nullptr;
        }
        void info() {
            for(T* p=data;p!=ptr;p++) p->info();
        }
};
