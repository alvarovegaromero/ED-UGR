#ifndef __RUTA__
#define __RUTA__
#include "Punto.h"
#include <list>


class Ruta{
  private:
    list<Punto> puntos;
    string codigo;

  public:
    Ruta(){}
    string GetCodigo()const { return codigo;}
    list<Punto> GetPuntos()const{ return puntos;}
    int GetSize()const{ return puntos.size();}

    void SetCodigo(string cad)
    {
        codigo = cad;
    }

    void SetPuntos(const list<Punto> & ptos)
    {
        puntos = ptos;
    }

    void insertar(const Punto &pto)
    {
        puntos.push_back(pto);
    }

    void borrar(const Punto &pto)
    {
        iterator it = find(pto);

        if(it != end())
            puntos.erase(it.p);
    }

    friend istream & operator>>(istream & is, Ruta &R){
        Ruta aux;
        int num_puntos = 0;
        Punto pto;

        is>>aux.codigo;
        is>>num_puntos;

        for(int i = 0 ; i < num_puntos ; i++)
        {
            is>>pto;
            aux.insertar(pto);
        }

        R = aux;

        return is;
    }

    friend ostream & operator<<(ostream & os, const Ruta &R){
	   os<<R.codigo<<" "<<R.GetSize()<<" ";

       for(Ruta::const_iterator it = R.begin() ; it != R.end() ; ++it)
            os<<*it<<" ";

       os << endl;
	   return os;
    }

    class const_iterator;
    class iterator{
    private:
        list<Punto>::iterator p;
    public:
        iterator(){}

        iterator & operator ++(){
            ++p;
            return * this;
        }

        iterator & operator --(){
            --p;
            return * this;
        }

        bool operator ==(const iterator  & it){
            return it.p ==p;
        }

        bool operator !=(const iterator  & it){
            return it.p !=p;
        }

        const Punto & operator*()const{
            return *p;
        }

        friend class Ruta;
        friend class const_iterator;
    };

    class const_iterator{
    private:
        list<Punto>::const_iterator p;
    public:
        const_iterator(){}

        const_iterator(const iterator & it){
            p=it.p;
        }

        const_iterator & operator=(const iterator & it){
            p=it.p;
            return *this;
        }

        const_iterator & operator ++(){
            ++p;
            return * this;
        }

        const_iterator & operator --(){
            --p;
            return * this;
        }

        bool operator ==(const const_iterator  & it){
            return it.p ==p;
        }

        bool operator !=(const const_iterator  & it){
            return it.p !=p;
        }

        const Punto &operator*()const {
            return *p;
        }

        friend class Ruta;
    };

    iterator begin(){
        iterator it;
        it.p = puntos.begin();
        return it;
    }

    const_iterator begin()const{
        const_iterator it;
        it.p = puntos.begin();
        return it;
    }

    iterator end(){
        iterator it;
        it.p = puntos.end();
        return it;
    }

    const_iterator end() const{
        const_iterator it;
        it.p = puntos.end();
        return it;
    }

    iterator find(const Punto &p){
        iterator it;
        list<Punto>::iterator i;
        for (i=puntos.begin(); i!=puntos.end() && !((*i)==p);++i);
            it.p=i;
        return it;
    }

    bool operator == (const Ruta & otra) const
    {
        bool igual = true;
        Ruta::const_iterator it_otra = otra.begin();

        if (GetSize() != otra.GetSize())
            igual = false;

        for (list<Punto>::const_iterator it = puntos.begin(); it != puntos.end() && it_otra != otra.end() && igual; ++it, ++it_otra)
        {
            if (*it != *it_otra)
                igual = false;
        }

        return igual;
    }

};
#endif