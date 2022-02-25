#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <cstring>
#include <iostream>

using namespace std;

typedef unsigned char byte; //Mostrar niveles de grises con otro nombre

/**
  *  @brief T.D.A. Imagen
  *
  * Una instancia @e c del tipo de datos abstracto @c Imagen es una imagen de
  * niveles de grises formada por dos valores indicando las filas y columnas de
  * una matriz en la que cada celda (o mejor dicho píxel)
  *
  * @author Álvaro Vega Romero
  * @date 20/10/2020
  */

class Imagen{

private:

const static byte BLANCO = 0;
const static byte NEGRO = 255;

int filas; /**< filas de la matriz */
int cols;  /**< columnas de la matriz */
byte **img; /**< Puntero al vector de punteros a bytes (matriz) */

/**
  * @brief Reserva la memoria dinámica que va a usar el TDA
  */
void ReservaMemoria ();

/**
  * @brief Destruye la memoria dinámica que ha usado el TDA 
  */
void LiberaMemoria ();

/**
  * @brief Método llamado por ZoomPorcion para rellenar los huecos de la img
  */
void InterpolaColumnas();

/**
  * @brief Método llamado por ZoomPorcion para rellenar los huecos de la img
  */
void InterpolaFilas();

/**
  * @brief Método llamado por Icono calcular el valor medio de gris en una matriz
  * @param x1, la fila inicial
  * @param y1, la columna inicial
  * @param x2, la fila final (se incluye)
  * @param y2, la columna final (se incluye)
  * @return EL valor medio de gris entre esas posiciones de la matriz
  * @pre x1 <= x2 e y1 <= y2
  */
int Media(int x1, int y1, int x2, int y2);
	
public:	

/**
  * @brief Constructor por defecto de la clase. 
  * @return Crea un objeto con 0 filas y columnas y sin iniciailizar
  */
Imagen ();

/**
  * @brief Constructor de copia de la clase
  * @param J un objeto de la clase Imagen
  * @return Un objeto con la misma matriz que J
  */
Imagen (const Imagen & J); 

/**
  * @brief Constructor con parámetro de la clase
  * @param filas, el número de filas de la matriz
  * @param cols, el número de columnas de la matriz
  * @return Un objeto con la misma matriz que J
  * @pre filas > 0 y cols > 0
  */		
Imagen (int nfilas, int ncols);

/**
  * @brief Destructor de la clase
  */		
~Imagen();

/**
  * @brief Consultor del número de filas de la imagen
  * @return Devuelve un entero con el número
  */
int num_filas() const;

/**
  * @brief Consultor del número de columnass de la imagen
  * @return Devuelve un entero con el número
  */
int num_columnas() const;

/**
  * @brief Cambia el valor de un determinado píxel
  * @param fila, la fila del pixel
  * @param col, la columna del pixel
  * @param valor, el nivel de gris que se quiere poner en el píxel
  * @pre 0 <= fila < num_filas()
  * @pre 0 <= cols < num_columnas() 
  * @pre 
  */
void asigna_pixel (int fila, int col, unsigned char valor);

/**
  * @brief Cambia el valor de un determinado píxel
  * @param fila, la fila del pixel
  * @param col, la columna del pixel
  * @return El valor correspondiente a ese pixel
  * @pre 0 <= fila < num_filas()
  * @pre 0 <= cols < num_columnas() 
  */
byte valor_pixel (int fila, int col) const;

/**
  * @brief Método para visualizar el contenido de la matriz
  * @return Un string con el contenido de la matriz y las filas y columnas
  */
string ToString ();

/**
  * @brief Método para umbralizar una imagen en función de dos extremos
  * @param T1, el extremos inferior para umbralizar
  * @param T2, el extremo superior para umbralizar
  * @pre 0 < = T1 <= T2 <= 255
  */
void umbralizar(byte T1, byte T2);

/**
  * @brief Hace zoom sobre una porción de una imagen. 
  * @param x1, la fila de inicio
  * @param y1, la columna de inicio 
  * @param x2, la fila final
  * @param y2, la columna final 
  * @return un objeto de la clase imagen al cual se le aplicó el zoom
  * @pre x1 <= x2
  * @pre y1 <= y2
  * @pre x1, x2, y1, y2 son posiciones de la imagen
  */
Imagen ZoomPorcion(int x1, int y1, int x2, int y2);

/**
  * @brief Hace zoom sobre una porción de una imagen. 
  * @param x1, la fila de inicio
  * @param y1, la columna de inicio 
  * @param nf, el num de filas del icono
  * @param nc, el num de columans del icono
  * @return un objeto de la clase imagen al cual se le aplicó el zoom
  * @pre nf <= filas_origianales
  * @pre nc <= columnas originales
  * @pre nf y nc > 0
  */
Imagen Icono (int nf, int nc);

/**
  * @brief Aumenta el constraste de una foto mediante una transformación lineal
  * @param min, el valor min del rango
  * @param max, el valor max del rango
  * @pre min <= max
  * @pre La imagen dispone de más un nivel de grises
  */
void constrastar(byte min, byte max);

};

#endif
