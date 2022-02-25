#include "imagenES.h"
#include "Imagen.h"

using namespace std;

int main (int argc, char *argv[]){
	const char* fichE = "datos/castillo.pgm";

Umbralizar(fichE, "datos/ejercicio1.pgm", (unsigned char) 100, (unsigned char) 120);

ZoomPorcion(fichE,"datos/ejercicio2.pgm", 86, 86, 86*2, 2*86);

Icono(fichE,"datos/ejercicio3.pgm",100,100);

AumentoContraste(fichE, "datos/ejercicio4.pgm", (byte) 30, (byte) 220);

cout << "Terminando main" << endl;

}
