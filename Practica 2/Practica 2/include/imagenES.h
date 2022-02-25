/**
  * @file imagenES.h
  * @brief Fichero cabecera para la E/S de imágenes
  *
  * Permite la E/S de archivos de tipo PGM,PPM
  *
  */

#ifndef _IMAGEN_ES_H_
#define _IMAGEN_ES_H_

#include "Imagen.h"

/**
  * @brief Tipo de imagen
  *
  * Declara una serie de constantes para representar los distintos tipos
  * de imágenes que se pueden manejar.
  *
  * @see LeerTipoImagen
  */
enum TipoImagen {IMG_DESCONOCIDO, IMG_PGM, IMG_PPM};

/**
  * @brief Devuelve el tipo de imagen del archivo
  *
  * @param nombre indica el archivo de disco que consultar
  * @return Devuelve el tipo de la imagen en el archivo
  *
  * @see TipoImagen
  */
TipoImagen LeerTipoImagen (const char *nombre);

/**
  * @brief Lee una imagen de tipo PPM
  *
  * @param nombre archivo a leer
  * @param filas Parámetro de salida con las filas de la imagen.
  * @param columnas Parámetro de salida con las columnas de la imagen.
  * @return puntero a una nueva zona de memoria que contiene @a filas x @a columnas x 3
  * bytes que corresponden a los colores de todos los píxeles en formato
  * RGB (desde la esquina superior izqda a la inferior drcha). En caso de que no
  * no se pueda leer, se devuelve cero. (0).
  * @post En caso de éxito, el puntero apunta a una zona de memoria reservada en
  * memoria dinámica. Será el usuario el responsable de liberarla.
  */
unsigned char *LeerImagenPPM (const char *nombre, int& fils, int& cols);

/**
  * @brief Escribe una imagen de tipo PPM
  *
  * @param nombre archivo a escribir
  * @param datos punteros a los @a f x @a c x 3 bytes que corresponden a los valores
  *    de los píxeles de la imagen en formato RGB.
  * @param f filas de la imagen
  * @param c columnas de la imagen
  * @return si ha tenido éxito en la escritura.
  */
bool EscribirImagenPPM (const char *nombre, const unsigned char *datos, 
                        const int fils, const int cols);

/**
  * @brief Lee una imagen de tipo PGM
  *
  * @param nombre archivo a leer
  * @param filas Parámetro de salida con las filas de la imagen.
  * @param columnas Parámetro de salida con las columnas de la imagen.
  * @return puntero a una nueva zona de memoria que contiene @a filas x @a columnas
  * bytes que corresponden a los grises de todos los píxeles
  * (desde la esquina superior izqda a la inferior drcha). En caso de que no
  * no se pueda leer, se devuelve cero. (0).
  * @post En caso de éxito, el puntero apunta a una zona de memoria reservada en
  * memoria dinámica. Será el usuario el responsable de liberarla.
  */
unsigned char *LeerImagenPGM (const char *nombre, int& fils, int& cols);

/**
  * @brief Escribe una imagen de tipo PGM
  *
  * @param nombre archivo a escribir
  * @param datos punteros a los @a f x @a c bytes que corresponden a los valores
  *    de los píxeles de la imagen de grises.
  * @param f filas de la imagen
  * @param c columnas de la imagen
  * @return si ha tenido éxito en la escritura.
  */
bool EscribirImagenPGM (const char *nombre, const unsigned char *datos, 
                        const int fils, const int cols);

/**
  * @brief Obteniene un objeto del TDA Imagen, dado un fichero
  * @param *nombre, El nombre del fichero pgm
  * @return Un objeto del TDA Imagen
  * @pre Debe ser un fichero pgm (de niveles de grises)
  */
Imagen FicheroAImagen (const char *nombre);

/**
  * @brief Obteniene un fichero pgm, dado un objeto del TDA Imagen
  * @param *nombre, El nombre del fichero pgm
  */
void ImagenAFichero (const char *nombre, Imagen& obj);


/**
  * @brief Consigue dado un fichero pgm, otro, pero umbralizado entre 2 valores
  * @param *fichE, El nombre del fichero pgm de entrada
  * @param *fichS, El nombre del fichero pgm de salida (ya umbralizado)
  * @param T1, el extremo inferior para umbralizar 
  * @param T2, el extremo superior para umbralizar 
  * @pre 0 < = T1 <= T2 <= 255
  */
void Umbralizar(const char *fichE, const char *fichS, byte T1, byte T2);

/**
  * @brief Hace zoom sobre una porción de una imagen. 
  * @param *fichE, El nombre del fichero pgm de entrada
  * @param *fichS, El nombre del fichero pgm de salida (aplicado el zoom)
  * @param x1, la fila de inicio
  * @param y1, la columna de inicio 
  * @param x2, la fila final
  * @param y2, la columna final 
  * @pre x1 <= x2
  * @pre y1 <= y2
  * @pre x1, x2, y1, y2 son posiciones de la imagen
  */
void ZoomPorcion(const char *fichE, const char *fichS, int x1, int y1, 
				 int x2, int y2);

/**
  * @brief Consigue un icono dado
  * @param *fichE, El nombre del fichero pgm de entrada
  * @param *fichS, El nombre del fichero pgm de salida (aplicado el icono)
  * @param nf, el num de filas del icono
  * @param nc, el num de columnas del icono
  * @pre nf <= filas_origianales
  * @pre nc <= columnas originales
  * @pre nf y nc > 0
  */
void Icono(const char *fichE, const char *fichS, int nf, int nc);

/**
  * @brief Aumenta el constraste de una foto mediante una transformación lineal
  * @param *fichE, El nombre del fichero pgm de entrada
  * @param *fichS, El nombre del fichero pgm de salida (aplicado el icono)
  * @param min, el valor min del rango
  * @param max, el valor max del rango
  * @pre min <= max
  * @pre La imagen dispone de más un nivel de grises
  */
void AumentoContraste(const char *fichE, const char *fichS, byte min, byte max);

#endif

/* Fin Fichero: imagenES.h */
