#include "Paises.h"

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
	Pais paises;
	f >> paises;

	cout << paises << endl;

}