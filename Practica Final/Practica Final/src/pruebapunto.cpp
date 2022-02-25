#include "Punto.h"
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
	if(argc!=2)
	{
		cout << "Los parametros son:" << endl;
		cout << "1.Fichero con la informacion de un punto"<<endl;
		return 0;
	}

	ifstream f (argv[1]);
	Punto pto1;
	f >> pto1;
	cout << "EL primer pto es" << pto1 << endl;

	Punto pto2(17.246400332673307, -19.670602940234403);
	cout << "El segundo pto es: " << pto2 << endl;

	if(pto2 < pto1)
		cout << "EL punto mayor es: " << pto1;
	else
		cout << "EL punto mayor es: " << pto2;

}

