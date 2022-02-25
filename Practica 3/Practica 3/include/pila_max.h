#ifndef Elemento
#define Elemento
#include <iostream>
using namespace std;

template <class T>
struct elemento{
	T valor;
	T maximo;

	friend ostream & operator << (ostream &o,const elemento &e)
	{
		o << "Elemento: " << e.valor << endl << "Maximo: " << e.maximo << endl;

		return o;
	}
};
#endif

#define CUAL_COMPILA 2
#if CUAL_COMPILA==1
#include "pila_max_VD.h"
#elif CUAL_COMPILA==2
#include "pila_max_cola.h"
#endif

