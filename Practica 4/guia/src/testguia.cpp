#include <cassert>
#include <fstream>
#include <iostream>
#include <string>
#include "guia.h"

using namespace std;

int main()
{
	Guia_Tlf una;
    Guia_Tlf otra;

    fstream input_data1("./datos/guia.txt", fstream::in);
	input_data1 >> una;

	cout << "Primera lista: " << endl;
	cout << una << endl;

    fstream input_data2("./datos/guia2.txt", fstream::in);
	input_data2 >> otra;

	cout << "Segunda lista: " << endl;
	cout << otra << endl;

 	Guia_Tlf un = una+otra;
 	Guia_Tlf dif = una-otra;

 	cout<<"La union de las dos guias: "<<endl <<un<<endl;
 
 	cout<<"La diferencia de las dos guias: "<<endl <<dif<<endl;

	//***********************************************************************

 	cout << endl << "SEGUNDA PARTE DE LAS PRUEBAS:" << endl << endl;

	//***********************************************************************

    Guia_Tlf uno;

    assert(uno.begin() == uno.end());

    fstream input_data("./datos/telefonos.txt", fstream::in);
	input_data >> uno;

    Guia_Tlf dos(uno);
	assert(dos.begin() != dos.end());

	Guia_Tlf::Iterador it;
	uno.insert("Manolo", "666666666");

    assert(uno["Pedro"] == dos["Pedro"]);
    uno["Pedro"][3] = '7';
    assert(uno["Pedro"] != dos["Pedro"]);

	uno = uno;
	assert(*uno.begin() == *dos.begin());

	Guia_Tlf tres;
    Guia_Tlf cuatro(tres);
	assert(tres.cbegin() == tres.cend());
	assert(cuatro.cbegin() == cuatro.cend());
	tres = uno;
    
    tres["Manolo"][0] = 0;
    assert(uno["Manolo"] != tres["Manolo"]);

    Guia_Tlf cinco = uno - dos;
    assert(cinco["Manolo"] == uno["Manolo"]);
    

    size_t c = 0;
    for (Guia_Tlf::Iterador it = cinco.begin(); it != cinco.end(); ++it)
        //esto debe ejecutarse dos veces. Añadimos contador para que falle
        //si el diccionario contiene más elementos
        //Elementos esperados: Manolo y Pedro (porque a Pedro le hemos cambiado
        //un dígito)
        //usando (*it) en vez de it-> para evitar tener que sobrecargar -> en
        //caso de que el Guia_Tlf::iterator sea implementación propia
        assert(c++ < 2 && ((*it).first == "Manolo" || (*it).first == "Pedro"));
    
    //En la unión de diccionarios, cuando la clave existe en ambos, se puede
    //tomar el valor del primer diccionario o del segundo. Se aceptan ambos.
    Guia_Tlf seis = uno + dos;
    assert((seis["Pedro"] != uno["Pedro"] && seis["Pedro"] == dos["Pedro"])
        || (seis["Pedro"] == uno["Pedro"] && seis["Pedro"] != dos["Pedro"]));

    pair<std::map<string, string>::iterator, bool> p = seis.insert("Pedro", "123456789");
    assert(!p.second);

    cout << "OK" << endl;

	cout << uno << endl;

    cout << "Funciones propias: " << endl << endl;

    uno.ModificaNum("Nuria" , "777777777");
    uno.ModificaNum("Paco" , "987654231"); //No existe - Inserta

    cout << uno << endl;

    cout << "Números de los que empiezan por p: " << endl;
    Guia_Tlf guia_p(uno.NumerosEmpiezan('p'));
    cout << guia_p << endl;

    cout << "Números de los que empiezan entre J y N" << endl;
    Guia_Tlf guia_intervalo(uno.NumerosEntre('j', 'n'));
    cout << guia_intervalo << endl;



    return 0;
}   