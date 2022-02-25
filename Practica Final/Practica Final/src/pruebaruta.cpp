#include "Ruta.h"
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		cout << "Los parametros son:" << endl;
		cout << "1.Fichero con la informacion de una ruta"<<endl;
		return 0;
	}

	ifstream f (argv[1]);
	Ruta ruta;
	f >> ruta;
	cout << "LA ruta es: " << endl << ruta << endl;

	ruta.borrar(Punto(52.50786264022465,13.426141949999987));
	ruta.insertar(Punto(52.50786264022465,13.426141949999987));

	cout << "LA ruta es" << endl << ruta << endl;

	cout << "Los puntos son: " << endl;
	Ruta::const_iterator it = ruta.begin();

	for(it ; it != ruta.end() ; ++it)
		cout << *it << endl;

}

