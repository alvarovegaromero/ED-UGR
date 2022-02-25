//#include "../include/pila_max_cola.h" 

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

	aux.valor = elementos.frente();
	aux.maximo = maximos.frente();
 
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
	Cola <T> tmp = (*this).elementos;
	Cola <T> tmp_maximos = (*this).maximos;
	T ult_maximo = -1;

	while (!vacia()) //Mientras no esté vacía, vaciamos la cola implicita
	{
		quitar();
	}

	elementos.poner(elem);

	if(!tmp_maximos.vacia())
		ult_maximo = tmp_maximos.frente();

	if(elem > ult_maximo)
		ult_maximo = elem;

	maximos.poner(ult_maximo);

	T num_elementos_antes = tmp.num_elementos();

	while(!tmp.vacia())
	{
		elementos.poner(tmp.frente());
		tmp.quitar();
		
		maximos.poner(tmp_maximos.frente());
		tmp_maximos.quitar();
	}		
	
	num_elementos = num_elementos_antes;
	num_elementos++;
}

template <class T>
void PilaMax<T> :: quitar()
{
	if(!elementos.vacia()) 
	{
		num_elementos--;
		elementos.quitar();
		maximos.quitar();
	}
}


