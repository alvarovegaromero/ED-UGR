#include "Almacen_Rutas.h"

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
	Almacen_Rutas alm;
	f >> alm;

	cout << alm << endl;

	alm.borrar("R2");

	cout << alm << endl;

	cout << "Ruta:" << endl;
	cout << alm.GetRuta("R5");

	Ruta ruta;

	ruta.insertar(Punto(34.520418555522845,69.20082090000005));
	ruta.insertar(Punto(52.50786264022465,13.426141949999987));
	ruta.insertar(Punto(7.406652727545182,12.344585699999925));
	ruta.insertar(Punto(-0.18659558628491132,-78.4305382));
	ruta.insertar(Punto(40.40051528912146    ,-3.5916460749999635));
	ruta.SetCodigo("R1");

	alm.borrar(ruta);

	cout << alm << endl;

	cout << alm.GetCodigo(ruta) << endl;

	f.close();
}
