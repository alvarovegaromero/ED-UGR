#ifndef __ALMACEN_RUTA__
#define __ALMACEN_RUTA__
#include "Ruta.h"
#include <map>

class Almacen_Rutas{
  private:
    map<string, Ruta> rutas;
    multimap<Punto, string> puntos;

  public:
    Almacen_Rutas(){}
    Ruta GetRuta(const string cad)
    { 
        return rutas[cad];
    }
    
    Almacen_Rutas GetRutas_Con_Punto(const Punto &P)
    {
        Almacen_Rutas Al;
        Ruta R;

/*
        pair< multimap<Punto, string>::iterator, multimap<Punto, string>::iterator > intervalo;
        intervalo = puntos.equal_range(P); -> Debería de funcionar, pero devuelve basura, buscando un punto que no es
        cout << (intervalo.first)->first << "   " << (intervalo.first)->second << endl;
        cout << (intervalo.second)->first << "   " << (intervalo.second)->second << endl;

        for (multimap<Punto, string>::iterator it = intervalo.first; it != intervalo.second ; ++it)
*/

        for(multimap<Punto, string>::iterator it = puntos.begin(); it != puntos.end() ; ++it)
        {
            if (it->first == P)
            {
                R = GetRuta(it->second);
                Al.insertar(R);
            }
        }

        return Al;
    }

    string GetCodigo(const Ruta & ruta) const
    {
        map<string, Ruta>::const_iterator it;
        bool encontrado = false;
        string cad;

        for(it = rutas.begin() ; it != rutas.end() && !encontrado; ++it)
        {
            if(it->second == ruta)
            {
                cad = it->first;
                encontrado = true;
            }
        }

        return cad;
    }

    void SetRuta(const string cad, const Ruta & ruta) 
    {
        map<string, Ruta>::iterator it;

        it = rutas.find(cad);

        if(it != rutas.end())
            rutas[cad] = ruta;
    }

    void insertar(const Ruta & ruta)
    {
        rutas[ruta.GetCodigo()] = ruta;

        Ruta::const_iterator it = ruta.begin();
        pair <Punto, string> aux;

        aux.second = ruta.GetCodigo();

        for(it ; it != ruta.end() ; ++it)
        {
            aux.first = *it;

            puntos.insert(aux);
        }
    }

    void borrar(const Ruta & ruta)
    {
        if (ruta == GetRuta(ruta.GetCodigo()))
            borrar(ruta.GetCodigo());

        for(multimap<Punto, string>::iterator it = puntos.begin(); it != puntos.end() ; ++it)
        {
            if (it->second == ruta.GetCodigo())
            {
                puntos.erase(it);
            }
        }
    }

    void borrar(const string cad)
    {
        rutas.erase(cad);
    }


    friend istream & operator>>(istream & is, Almacen_Rutas &R)
    {
        Almacen_Rutas aux;

        if (is.peek()=='#'){
            string a;
            getline(is,a);
        } 

        Ruta ruta;
        while(is >> ruta)
        {
            aux.insertar(ruta);
        }

        R = aux;
        return is;
    }

    friend ostream & operator<<(ostream & os, const Almacen_Rutas &R){
	    os << "#Rutas" << endl;

        for(const_iterator it = R.begin() ; it != R.end() ; ++it)
            os<<(*it).second;
        
        os << endl;
	    return os;
    }

    class const_iterator;
    class iterator{
    private:
        map<string, Ruta>::iterator p;
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

        const pair<string, Ruta> operator*()const{
            return *p;
        }

        friend class Almacen_Rutas;
        friend class const_iterator;
    };

    class const_iterator{
    private:
        map<string, Ruta>::const_iterator p;
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

        const pair<string, Ruta> operator*()const {
            return *p;
        }

        friend class Almacen_Rutas;
    };

    iterator begin(){
        iterator it;
        it.p = rutas.begin();
        return it;
    }

    const_iterator begin()const{
        const_iterator it;
        it.p = rutas.begin();
        return it;
    }

    iterator end(){
        iterator it;
        it.p = rutas.end();
        return it;
    }

    const_iterator end() const{
        const_iterator it;
        it.p = rutas.end();
        return it;
    }

    iterator find(const string codigo){
        iterator it;
        map<string, Ruta>::iterator i;
        for (i=rutas.begin(); i!=rutas.end() && !((*i).first==codigo);++i);
            it.p=i;
        return it;
    }
};
#endif