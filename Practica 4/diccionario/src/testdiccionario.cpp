#include "diccionario.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

/*
istream &operator>>(istream &is, Diccionario<string, string> &D) {
  int np;
  is >> np;
  is.ignore(); // quitamos \n

  Diccionario<string, string> Daux;
  for (int i = 0; i < np; ++i) {
    string clave;

    getline(is, clave);

    int ns;
    is >> ns;
    is.ignore(); // quitamos \n

    list<string> laux;
    for (int j = 0; j < ns; ++j) {
      string s;
      getline(is, s);

      laux.insert(laux.end(), s);
    }

    Daux.Insertar(clave, laux);
  }

  D = Daux;

  return is;
}

ostream &operator<<(ostream &out, const Diccionario<string, string> &d) {
  for (Diccionario<string, string>::const_iterator i = d.cbegin();
       i != d.cend(); ++i) {
    out << (*i).clave << ":\n";

    for (list<string>::const_iterator j = (*i).info_asoci.begin();
         j != (*i).info_asoci.end(); ++j)
      out << '\t' << *j << '\n';

    out << endl;
  }

  return out;
}
*/

int main() {
  Diccionario<string, string> uno;

  // Comprobar iteradores para diccionario vacío
  assert(uno.begin() == uno.end());

  fstream input_data("./datos/data.txt", fstream::in);
  input_data >> uno;

  Diccionario<string, string> dos(uno);

  cout << uno << endl;

  uno.AddSignificado_Palabra(
      "f. Dicho grave y sucinto que encierra doctrina o moralidad",
      "Sentencia");

  assert(uno.getInfo_Asoc("Sentencia").front() ==
         "f. Frase o dicho que implica un juicio,una enseñanza.");
  
  assert(uno.getInfo_Asoc("Sentencia").back() ==
         "f. Dicho grave y sucinto que encierra doctrina o moralidad");

  assert(uno.getInfo_Asoc("Sentencia").front() ==
         dos.getInfo_Asoc("Sentencia").front());
  assert(uno.getInfo_Asoc("Sentencia").back() !=
         dos.getInfo_Asoc("Sentencia").back());

  assert(uno.getInfo_Asoc("Sentencia").front() ==
         "f. Frase o dicho que implica un juicio,una enseñanza.");

  Diccionario<string, string> tres;
  assert(tres.cbegin() == tres.cend());
  uno = tres;
  assert(uno.begin() == uno.end());
  assert(dos.begin() != dos.end());

  cout << "Funciones propias: " << endl;

  assert(dos.NumDefiniciones("Sentencia") == 2); //uno se copia a basura(3)

  dos.EliminarClave("Compilador");
  assert(dos.NumDefiniciones("Compilador") == 0);

  cout << dos.MuestraClaves();

  Diccionario<string, string>::ConstIterador it = dos.cbegin();

 // for(it ; it != dos.cend() ; ++it)
 //  cout << *it.clave << endl;

  cout << "--Pruebas terminadas--" << endl;

  return 0;
}