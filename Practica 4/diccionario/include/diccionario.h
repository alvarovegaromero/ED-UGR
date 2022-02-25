#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

/**
  * @brief Struct que contiene la clave y una lista de info asociada
  */
template <typename T,typename U>
struct data{
    T clave;
    list<U> info_asoci;
 };


/**
  * @brief Operador < para el orden en el diccionario
  */
template <typename T, typename U>
bool operator< (const data<T,U> &d1,const data <T,U>&d2){
	   if (d1.clave<d2.clave)
		     return true;
	   return false;
}

/**
  *  @brief T.D.A. Diccionario
  *
  * Una instancia @e c del tipo de datos abstracto @c Diccionario es una lista
  * de data (struct) , las cuales tienen una clave única y pueden tener múltiples definiciones
  * Así, se comporta como el tipo map.
  *
  * Cabe destacar que la clase es un template y por tanto se puede usar como clave y
  * y definición el tipo de datos que sea conveniente
  * 
  * Invariante de datos: la palabra no debe contener número
  *
  * Función de abstracción: una lista de data
  *
  * @author Álvaro Vega Romero
  * @date 29/11/2020
  */

template <typename T,typename U>
class Diccionario{
  private:
    list<data<T,U> > datos;

/**
  * @brief Copia de otro diccionario en el objeto ímplicito
  * @param Dicc, otro diccionario a partir del cual se copia
  */
    void Copiar(const Diccionario<T,U>& Dicc){
      datos.assign(Dicc.datos.begin(),Dicc.datos.end());
    }

/**
  * @brief Borra todos los datos de la lista de datos
  */
    void Borrar(){
      this->datos.erase(datos.begin(),datos.end());
    }

  public:

/**
  * @brief Constructor por defecto de la clase. 
  * @return Un objeto con una lista vacía
  */
    Diccionario():datos(list<data<T,U> >()){}

/**
  * @brief Constructor de copia de la clase
  * @param Dicc un objeto de la clase Diccionario
  * @return Un objeto con los mismos datos que Diccionario
  */
    Diccionario(const Diccionario &Dicc){
      Copiar(Dicc);
    }

/**
  * @brief Destructor de la clase
  */		
    ~Diccionario(){}

/**
  * @brief Operador de asignación.
  * @param Otro diccionario
  * @return Un objeto que es copia del parámetro
  */
    Diccionario<T,U> & operator=(const Diccionario<T,U> &Dicc);

/**
  * @brief Busca una clave en el diccionario.
  * @param p, la clave que se usará para buscar
  * @param un iterador. Si está la clave, apuntará a ella, si no, a donde debería ir
  * @return Un booleano que muestra si está o no la clave
  */    
    bool Esta_Clave(const T &p, typename list<data<T,U> >::iterator &it_out);

/**
  * @brief Inserta en datos una nueva palabra y sus definiciones
  * @param clave, la clave que se usará
  * @param info. Una lista con las definiciones de la clave
  */ 
    void Insertar(const T& clave,const list<U> &info);

/**
  * @brief Aniade un significado a una clave. 
  *			Si la clave no está en la lista la crea
  * @param clave, la clave que se usará
  * @param p, el significado a agregar a la clave
  */ 
    void AddSignificado_Palabra( const U & s , const T &p); //s es la info

/**
  * @brief Dada una clave, se busca la información relativa y se da
  * @param p, la clave de la que se busca la información
  * @return Una lista con la información de la clave dada
  */     
    list<U>  getInfo_Asoc(const T & p);

/**
  * @brief Devuelve el número de claves/elementos en la lista
  * @return Ese número
  */ 
    inline int size()const{return datos.size();}

     /*************************************************************************/
     /****************************FUNCIONES EXTRA******************************/

/**
  * @brief Devuelve el número de definiciones dada una clave
  * @param clave, la clave de la cual se va a buscar información
  * @return Ese número
  */ 
    int NumDefiniciones(const T& clave);

/**
  * @brief ELimina una clave y sus definiciones de la lista
  * @param clave, La clave que se eliminará y su info asociada
  */ 
    void EliminarClave(const T& clave);

/**
  * @brief Muestra las claves que se encuentran activas en el diccionario
  * @return Una cadena con la información previa
  */ 
    string MuestraClaves();

    /**
      @brief Lectura del diccionario
      @param is: flujo de entrada. ES MODIFICADO
      @param Dicc: diccionario. ES MODIFICADO
      @return el flujo de entrada
    */
    template <typename sT,typename sU>
    friend istream & operator >>(istream & is,Diccionario<sT,sU> &Dicc)
    {
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

  		Dicc = Daux;

  		return is;
	}

    /**
      @brief Escritura del Diccionario
      @param os: flujo de salida. Es MODIFICADO
      @param g: diccionario que se escribe
      @return el flujo de salida
    */ 
    template <typename sT,typename sU>
    friend ostream & operator<<(ostream & os, Diccionario<sT,sU> &Dicc)
    {
      for (ConstIterador it = Dicc.cbegin();
          it != Dicc.cend(); ++it)
      {
          os << "Clave: " << (*it).clave << endl;
          os << "Informacion disponible: " << endl;

          for (typename list<sU>::const_iterator definicion_actual = (*it).info_asoci.begin();
              definicion_actual != (*it).info_asoci.end(); definicion_actual++)
                  os << "\t- " << (*definicion_actual) << endl;
          
          os << "**************************************************************" << endl;
      }

      return os;
    }

/**
  * @brief Clase iterador. Iterador para el uso externo
  */
    class Iterador {
		private:
			typename std::list<data<T,U>>::iterator it;
		public:
			Iterador(): it(0){}

			~Iterador(){}

			data<T,U> & operator * ( ) const 
			{
				return *it;
			}

			Iterador& operator++()
			{
				it++;
				return *this;
			}

			Iterador& operator--()
			{
				it--;
				return *this;
			}

			bool operator != (const Iterador& i) const
			{
				return(it != i.it);
			}

			bool operator == (const Iterador& i) const
			{
				return(it == i.it);
			}

			friend class Diccionario<T,U>;
      friend class ConstIterador;
    };

/**
  * @brief Clase iterador constante. Iterador constante para el uso externo
  */
    class ConstIterador 
    {
    private:
			typename std::list<data<T,U>>::const_iterator it;
		public:
			ConstIterador():it(0){}

			~ConstIterador(){}

			const data<T,U> & operator * () const
			{
				return *it;
			}

			ConstIterador& operator++()
			{
				it++;
				return *this;
			}

			ConstIterador& operator--()
			{
				it--;
				return *this;
			} 

			bool operator != (const ConstIterador & i) const
			{
				return(!(*this==i));
			}

			bool operator == (const ConstIterador & i) const
			{
				return(it==i.it);
			}

			friend class Diccionario<T,U>;
    };

/**
  * @brief Devuelve un iterador apuntando al inicio de los datos
  * @return Un iterador al inicio de los datos
  */
    Iterador begin(){
     	Iterador i;
     	i.it = datos.begin();
     	return i;
    }

/**
  * @brief Devuelve un iterador apuntando al final de los datos
  * @return Un iterador al final de los datos
  */
    Iterador end(){
       Iterador i;
       i.it = datos.end();
       return i;
    }

/**
  * @brief Devuelve un iterador cte apuntando al inicio de los datos
  * @return Un iterador cte al inicio de los datos
  */
    ConstIterador cbegin() const{
        ConstIterador i;
     	i.it = datos.begin();
     	return i;
    }

/**
  * @brief Devuelve un iterador cte apuntando al final de los datos
  * @return Un iterador cte al final de los datos
  */
    ConstIterador cend() const {
       ConstIterador i;
       i.it = datos.end();
       return i;
     }

};

#include "../src/diccionario.cpp"

#endif
