//#include "../include/pila_max_VD.h"

//ESTAMOS ORDENANDO "LA PILA AL REVES" . AL METER DATOS VAN AL 0
template <class T>
PilaMax<T> :: PilaMax()
{
	num_elementos = 0;
}

template <class T>
const int PilaMax<T> :: n_elementos() const
{
	return num_elementos;
}

template <class T>
const elemento <T> PilaMax<T> :: tope() const
{
	elemento <T> aux;
	T maximo = 0;
	T elemento = 0;

	if(!elementos.empty())
	{
		elemento = elementos.back();
		maximo = maximos.back();
	}

	aux.valor = elemento;
	aux.maximo = maximo;
 
	return aux;
}

template <class T>
bool PilaMax<T> :: vacia() const
{
	return (num_elementos == 0);
}

template <class T>
void PilaMax<T> :: poner(const T & elem)
{
	elementos.push_back(elem);
	
	int ult_maximo = 0;

	if(!maximos.empty())
		ult_maximo = maximos.back();

	if(ult_maximo < elem)
		ult_maximo = elem;

	maximos.push_back(ult_maximo);	

	num_elementos++; 
}

template <class T>
void PilaMax<T> :: quitar()
{

	if(!elementos.empty())	//Mismo num de elementos
	{
		elementos.pop_back();
		maximos.pop_back();
		num_elementos--;
	}
}
