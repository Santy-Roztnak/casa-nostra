#ifndef ARBOL_H
#define ARBOL_H
#include "node.h"

template<class T>
class arbolFamilia{
    private:
        Node<T>* raiz;

    public:
        arbolFamilia();

        void InsertarMiembros(T data);
        Node<T>* BuscarMiembro(int id);
        void modificaDato(int id);



};
#endif