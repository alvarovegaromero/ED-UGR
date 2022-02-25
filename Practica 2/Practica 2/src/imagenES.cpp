 /**
  * @file imagenES.cpp
  * @brief Fichero con definiciones para la E/S de imágenes
  *
  * Permite la E/S de archivos de tipo PGM,PPM
  *
  */

#include <fstream>
#include <string>

#include "imagenES.h"

using namespace std;


TipoImagen LeerTipo(ifstream& f){
  char c1,c2;
  TipoImagen res= IMG_DESCONOCIDO;

  if (f){
    c1=f.get();
    c2=f.get();
    if (f && c1=='P')
      switch (c2) {
        case '5': res= IMG_PGM; break;
        case '6': res= IMG_PPM; break;
        default: res= IMG_DESCONOCIDO;
      }
  }
  return res;
}

// _____________________________________________________________________________

TipoImagen LeerTipoImagen(const char *nombre){
  ifstream f(nombre);
  return LeerTipo(f);
}


// _____________________________________________________________________________

char SaltarSeparadores (ifstream& f){
  char c;
  do{
    c= f.get();
  } while (isspace(c));
  f.putback(c);
  return c;
}

// _____________________________________________________________________________

bool LeerCabecera (ifstream& f, int& fils, int& cols){
    int maxvalor;
    string linea;
    while (SaltarSeparadores(f)=='#')
      getline(f,linea);
    f >> cols >> fils >> maxvalor;
    
    if (/*str &&*/ f && fils>0 && fils<5000 && cols>0 && cols<5000){
        f.get(); // Saltamos separador
        return true;
    }
    else 
      return false;
}



// _____________________________________________________________________________

unsigned char *LeerImagenPPM (const char *nombre, int& fils, int& cols){
  unsigned char *res=0;
  fils=0;
  cols=0;
  ifstream f(nombre);
  
  if (LeerTipo(f)==IMG_PPM){
    if (LeerCabecera (f, fils, cols)){
        res= new unsigned char[fils*cols*3];
        f.read(reinterpret_cast<char *>(res),fils*cols*3);
        if (!f){
          delete[] res;
          res= 0;
        }
    }
  }
  return res;
}

// _____________________________________________________________________________

unsigned char *LeerImagenPGM (const char *nombre, int& fils, int& cols){
  unsigned char *res=0;
  fils=0;
  cols=0;
  ifstream f(nombre);
  
  if (LeerTipo(f)==IMG_PGM){
    if (LeerCabecera (f, fils, cols)){
      res= new unsigned char[fils*cols];
      f.read(reinterpret_cast<char *>(res),fils*cols);	

      if (!f){
        delete[] res;
        res= 0;
      }
    }
  }

  return res;
}

// _____________________________________________________________________________

bool EscribirImagenPPM (const char *nombre, const unsigned char *datos, 
                        const int fils, const int cols){
  ofstream f(nombre);
  bool res= true;
  
  if (f){
    f << "P6" << endl;
    f << cols << ' ' << fils << endl;
    f << 255 << endl;
    f.write(reinterpret_cast<const char *>(datos),fils*cols*3);
    if (!f)
      res=false;
  }
  return res;
}
// _____________________________________________________________________________

bool EscribirImagenPGM (const char *nombre, const unsigned char *datos, 
                        const int fils, const int cols){
  ofstream f(nombre);
  bool res= true;

  if (f){
    f << "P5" << endl;
    f << cols << ' ' << fils << endl;
    f << 255 << endl;
    f.write(reinterpret_cast<const char *>(datos),fils*cols);

    if (!f){
      res=false;
	}
  }

  return res;
}

// _____________________________________________________________________________

Imagen FicheroAImagen (const char *nombre){

	int fils = 0;
	int cols = 0;	 

	unsigned char * res = LeerImagenPGM (nombre, fils, cols);

	Imagen obj (fils, cols);

	int k = 0;

	for(int i = 0 ; i < fils ; i++){
		for(int j = 0 ; j < cols ; j++){
			obj.asigna_pixel(i,j, res[k]);
			k++;
		}
	}

	delete [] res;

	return obj;
}

// _____________________________________________________________________________

void ImagenAFichero (const char *nombre, Imagen& obj){

	unsigned char *res= new unsigned char[obj.num_columnas() * obj.num_filas()];	

	int k = 0;

	for(int i = 0 ; i < obj.num_filas() ; i++)
		for(int j = 0 ; j < obj.num_columnas() ; j++)
		{
			res[k] = (byte) obj.valor_pixel(i,j);
			k++;
		}
	
	EscribirImagenPGM (nombre, res, obj.num_filas(), obj.num_columnas());
	delete [] res;
}

// _____________________________________________________________________________

void Umbralizar(const char *fichE, const char *fichS, byte T1, byte T2){

	Imagen imagen = FicheroAImagen (fichE);	;

	imagen.umbralizar(T1,T2);
	
	ImagenAFichero(fichS, imagen);
	
}

// _____________________________________________________________________________

void ZoomPorcion(const char *fichE, const char *fichS, int x1, int y1, 
				 int x2, int y2){

	Imagen imagen = FicheroAImagen (fichE);	;

	Imagen zoom(imagen.ZoomPorcion(x1,y1,x2,y2));

	ImagenAFichero(fichS, zoom);

}

// _____________________________________________________________________________

void Icono(const char *fichE, const char *fichS, int nf, int nc){
	Imagen imagen = FicheroAImagen (fichE);

	Imagen icono(imagen.Icono(nf,nc));

	ImagenAFichero(fichS, icono);
}

// _____________________________________________________________________________

void AumentoContraste(const char *fichE, const char *fichS, byte min, byte max){
	Imagen imagen = FicheroAImagen (fichE);

	imagen.constrastar(min,max);

	ImagenAFichero(fichS, imagen);

}

/* Fin Fichero: imagenES.cpp */

