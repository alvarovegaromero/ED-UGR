#ifndef PilaMax_vd
#define PilaMax_vd

#include <vector>

/**
 *  @brief T.D.A. PilaMax
 *
 *
 * Una instancia @e v del tipo de datos abstracto PilaMax sobre el tipo @c int es 
 * una lista de elementos del mismo con un funcionamiento @e LIFO (Last In, 
 * First Out). En una pila, las operaciones de inserción y borrado de elementos
 * tienen lugar en uno de los extremos denominado @e Tope.
 *
 * El tipo rep utilizado serán Colas
 *
 * @author Álvaro Vega Romero
 * @date Noviembre 2020
 */
template <class T>
class PilaMax
{
private:
	int num_elementos;
	std::vector<T> elementos;  
	std::vector<T> maximos;  
public:
	/**
     * @brief Constructor por defecto
	 * @return Un objeto de la clase PilaMax
     */
	PilaMax();

	/**
     * @brief Devuelve el tamaño de las Colas usadas en PilaMax
     */
	const int n_elementos() const;

	/**
     * @brief Devuelve el elemento del tope de una pila constante
     */
	const elemento <T> tope() const;

	/**
     * @brief Comprueba si la pila está vacía
     */
	bool vacia() const;

 	/**
     * @brief Añade un elemento "encima" del tope de la pila
     * @param elem Elemento que se va a añadir.
     */
	void poner(const T & elem);

	/**
     * @brief Quita el elemento del tope de la pila
     */
	void quitar();
};

#include "../src/pila_max_VD.cpp"

#endif


