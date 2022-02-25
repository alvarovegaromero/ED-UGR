#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <string>
#include <list>

using namespace std;

template <typename T,typename U>
struct data{
    T clave;
    list<U> info_asoci;
 };

template <typename T, typename U>
bool operator< (const data<T,U> &d1,const data <T,U>&d2){
	   if (d1.clave<d2.clave)
		     return true;
	   return false;
}

template <typename T,typename U>
class Diccionario{
  private:
    list<data<T,U> > datos;

    void Copiar(const Diccionario<T,U>& Dicc){
      datos.assign(Dicc.datos.begin(),Dicc.datos.end());
    }

    void Borrar(){
      this->datos.erase(datos.begin(),datos.end());
    }

  public:
    Diccionario():datos(list<data<T,U> >()){}

    Diccionario(const Diccionario &Dicc){
      Copiar(Dicc);
    }

    ~Diccionario(){}

    //Sugerencia: llevar esta operacion al .cpp
    Diccionario<T,U> & operator=(const Diccionario<T,U> &Dicc){
      if (this!=&Dicc){
        Borrar();
        Copiar(Dicc);
      }
      return *this;
    }

    //Sugerencia: llevar esta operacion al .cpp
    bool Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out){
      if (datos.size()>0){
        //Completar. Hay que iterar para localizar la clave...puede que no este...
      }
      else {
        it_out=datos.end();
        return false;
      }
    }

    //Sugerencia: llevar esta operacion al .cpp
    void Insertar(const T& clave,const list<U> &info){
      typename list<data<T,U> >::iterator it;
      if (!Esta_Clave(clave,it)){
        data<T,U> p;
        p.clave = clave;
        p.info_asoci=info;
        datos.insert(it,p);
      }
    }

    void AddSignificado_Palabra(const T &p, const U & s);

    //Sugerencia: llevar esta operacion al .cpp
    list<U>  getInfo_Asoc(const T & p) {
      typename list<data<T,U> >::iterator it;
      if (!Esta_Clave(p,it)){
        return list<U>();
      }
      else{
        return (*it).info_asoci;
      }
    }

    inline int size()const{return datos.size();}

     /*************************************************************************/
     /****************************FUNCIONES EXTRA******************************/
     //Aniadir aqui


     /*Operator >>. El formato de la entrada es:
          numero de claves en la primera linea
          clave-iésima retorno de carro
          numero de informaciones asociadas en la siguiente linea
          y en cada linea obviamente la informacion asociada
     */
     template <typename sT,typename sU>
     friend istream & operator >>(istream & is,Diccionario<sT,sU> &Dicc);

     /*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre
     listas de listas y otro sobre listas
     */
     template <typename sT,typename sU>
     friend ostream & operator<<(ostream & os, const Diccionario<sT,sU> &Dicc);


     class Iterator {
       //Completar
     };

     class ConstIterator {
       //Completar
     };

     Iterator begin(){
       //Completar
     }

     Iterator end(){
       //Completar
     }

     ConstIterator begin()const{
       //Completar
     }

     ConstIterator end()const {
         //Completar
     }

};

#include "diccionario.cpp"

#endif
