#include <iostream>
#include "pila_max.h"

using namespace std;

int main(){
	typedef int T; //Cambiar en función de tipo de dato usado

 	PilaMax <T> p;
 	int i;

 	for ( i=10; i>=0 ; i--)
 		p.poner(i);

	p.poner(1);
	p.poner(15);
	p.poner(11);

 	while (!p.vacia() ){
 		elemento <T> x = p.tope();
 		cout << x <<endl;
 		p.quitar();
 	}

 return 0;
}
