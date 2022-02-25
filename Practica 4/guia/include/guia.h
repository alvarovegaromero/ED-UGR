#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H
#include <map>
#include <iostream>
#include <string>
using namespace std;
istream & operator>>(istream &is,pair<string,string> &d){
	  
	  getline(is,d.first,'\t');
	  getline(is,d.second);
	  return is;
}	  

/**
  *  @brief T.D.A. Guia
  *
  * Una instancia @e c del tipo de datos abstracto @c Guia es un Diccionario (tipo rep)
  * el cual está formado por un par de strings, uno conteniendo el número
  * y otro el nombre de la persona.
  * 
  * Invariante de datos: El nombre no debe llevar números y el número debe tener un número
  * limitado de número
  *
  * Función de abstracción un único diccionario (map)
  *
  * @author Álvaro Vega Romero
  * @date 29/11/2020
  */

class Guia_Tlf{
	  private:
		    map<string,string> datos; //si admites que haya nombres repetidos tendrías que usar un
					     //multimap
					     
	  public:
		    // Guia_Tlf(){}
		    // Guia_Tlf(const Guia_Tlf & gt);
		    // ~Guia_Tlf(){}
		    // Guia_Tlf & operator=(const Guia_Tlf & gt);

		    /**
		      @brief Acceso a un elemento
		      @param nombre: nombre del elemento  elemento acceder
		      @return devuelve el valor asociado a un nombre, es decir el telÃ©fono
		    */
		    string & operator[](const string &nombre) {
			    return datos[nombre];
		    }
		    
 			/**
		      @brief Devuelve una cadena con el teléfono de una persona
		      @param nombre: nombre del elemento elemento acceder
		      @return devuelve el valor asociado a un nombre, es decir el telefono
		    */
		    string gettelefono(const string & nombre){
			    map<string,string>::iterator it=datos.find(nombre);
			    if (it==datos.end()) 
					return string("");
			    else 
			      	return it->second;
		    }
		     
		    /**
		     @brief Insert un nuevo telefono 
		     @param nombre: nombre clave del nuevo telefono
		     @param tlf: numero de telefono
		     @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
		    */
		    pair<map<string,string>::iterator,bool>  insert(string nombre, string tlf){
			    pair<string,string> p (nombre,tlf);
			    pair< map<string,string> ::iterator,bool> ret;

			    ret=datos.insert(p); 
			    return ret;     	
		    }
		    
		    /**
		     @brief Insert un nuevo telefono 
		     @param p: pair con el nombre y el telefono asociado
		     
		     @return : un pair donde first apunta al nuevo elemento insertado y bool es true si se ha insertado el nuevo tlf o false en caso contrario
		    */
		    pair<map<string,string>::iterator,bool>  insert(pair<string,string> p){
			      
			    pair<map<string,string> ::iterator,bool> ret;

			    ret=datos.insert(p); 
			    return ret;  	
		    }
		     
		    /**
		      @brief Borrar un telefono
		      @param nombre: nombre que se quiere borrar
		      @note: en caso de que fuese un multimap borraria todos con ese nombre
		    */
		    void borrar(const string &nombre){
			   map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
			   map<string,string>::iterator itupper = datos.upper_bound(nombre);//el primero que ya no tiene dicho nombre
			   datos.erase(itlow,itupper);//borramos todos aquellos que tiene dicho nombre
		    }
		    
		    /**
		      @brief Borrar un telefono
		      @param nombre: nombre que se quiere borrar y telefono asociado
		      @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
		    */
		    //con map siempre hay uno con multimap puede existir mas de uno
		    void borrar(const string &nombre,const string &tlf){
		        map<string,string>::iterator itlow = datos.lower_bound(nombre);//el primero que tiene dicho nombre
			   	map<string,string>::iterator itupper = datos.upper_bound(nombre);//el primero que ya no tiene dicho nombre
			   	map<string,string>::iterator it;
			   	bool salir =false;

			   	for (it=itlow; it!=itupper && !salir;++it){
				    if (it->second==tlf){
						datos.erase(it);
						salir =true;
				    }		
			    }		
		    }

		    /**
		      @brief  Numero de telefonos 
		      @return el numero de telefonos asociados
		     */
		    int size()const{
			    return datos.size();
		    }	

		    /**
		      @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
		      @param nombre: nombre sobre el que queremos consultar
		      @return numero de telefonos asociados a un nombre
		     */
		    //al ser un map debe de ser 0 o 1. Si fuese un multimap podríamos tener mas de uno
		    unsigned int contabiliza(const string &nombre){
			      return datos.count(nombre);
		    }
		    
		    /**
		      @brief Limpia la guia
		     */
		    void clear(){
			    datos.clear();
		    }	 

		    /**
		      @brief Union de guias de telefonos
		      @param g: guia que se une
		      @return: una nueva guia resultado de unir el objeto al que apunta this y g
		    */
		    Guia_Tlf operator+(const Guia_Tlf & g){
				Guia_Tlf aux(*this);
				map<string,string>::const_iterator it;

				for (it=g.datos.begin();it!=g.datos.end();++it){
				   aux.insert(it->first,it->second);
				}	  

				return aux;
		    }	   
		    	      
		    /**
		      @brief Diferencia de guias de telefonos
		      @param g: guia que se une
		      @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
		    */
		    Guia_Tlf operator-(const Guia_Tlf & g){
				Guia_Tlf aux(*this);
				map<string,string>::const_iterator it;

				for (it=g.datos.begin();it!=g.datos.end();++it){
				   aux.borrar(it->first,it->second);
				}	  

				return aux;
		    }
		    
		    /**
		      @brief Escritura de la guia de telefonos
		      @param os: flujo de salida. Es MODIFICADO
		      @param g: guia de telefonos que se escribe
		      @return el flujo de salida
		     */ 
		    friend ostream & operator<<(ostream & os, Guia_Tlf & g){
			    map<string,string>::iterator it;

			    for (it=g.datos.begin(); it!=g.datos.end();++it){
					os<<it->first<<"\t"<<it->second<<endl;
			    }

			    return os;
		    }
		    
		    /**
		      @brief Lectura de  la guia de telefonos
		      @param is: flujo de entrada. ES MODIFICADO
		      @param g: guia de telefonos. ES MODIFICADO
		      @return el flujo de entrada
		    */
		    friend istream & operator>>(istream & is, Guia_Tlf & g){
			    pair<string,string> p;
			    Guia_Tlf aux;
			      
			    while (is>>p){
				  	aux.insert(p);
			    }

			    g=aux;

			    return is;
		    }


		    //Funciones extra:

		    /**
		      @brief Modifica el número de una persona. Si no está lo inserta
		      @param nombre: El nombre de la persona
		      @param num_nuevo: El nuevo número de nombre
		    */
		    void ModificaNum(string nombre, string num_nuevo)
		    {
				datos[nombre] = num_nuevo;
		    }

		    /**
		      @brief Hace una lista con la gente cuyo nombnre
		      @param letra: La letra por la que empieza el nombre
		      @return Una lista con esos números
		    */
		    Guia_Tlf NumerosEmpiezan(char letra)
		    {
		    	Guia_Tlf aux;
			    map<string,string>::const_iterator it;
			    bool terminado = false;

			    for(it = datos.begin() ; it != datos.end() && !terminado ; ++it)
			    {
			    	if((it->first)[0] == toupper(letra))
			    	{
			    		aux.insert(*it);
			    	}
			    	else if((it->first)[0] > toupper(letra))
			    		terminado = true;
			    }

		    	return aux;
		    }

		   	Guia_Tlf NumerosEntre(char letra_inicio, char letra_final)
		    {
		    	char inicio = letra_inicio;
		    	char final = letra_final;

		    	if(inicio < final)
		    	{
		    		inicio = letra_final;
		    		final = letra_inicio;
		    	}

		    	Guia_Tlf aux;
			    map<string,string>::const_iterator it;
			    bool terminado = false;

			    for(it = datos.begin() ; it != datos.end() && !terminado ; ++it)
			    {
			    	if((it->first)[0] >= toupper(letra_inicio) 
			    		&& (it->first)[0] <= toupper(letra_final))
			    	{
			    		aux.insert(*it);
			    	}
			    	else if((it->first)[0] > toupper(letra_final))
			    		terminado = true;
			    }

		    	return aux;
		    }

		    //Clases iterador

		    /**
  * @brief Clase iterador. Iterador para el uso externo
  */
    class Iterador {
		private:
			map<string,string>::iterator it;
		public:
			Iterador(): it(0){}

			~Iterador(){}

			pair<string,string> operator * ( ) const 
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

			friend class Guia_Tlf;
            friend class ConstIterador;
    };

/**
  * @brief Clase iterador constante. Iterador constante para el uso externo
  */
    class ConstIterador 
    {
	    private:
			map<string,string>::const_iterator it;
		public:
				ConstIterador():it(0){}

				~ConstIterador(){}

				const pair<string,string> operator * () const 
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

				friend class Guia_Tlf;
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
#endif

