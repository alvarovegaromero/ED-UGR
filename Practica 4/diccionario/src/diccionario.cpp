
template <typename T,typename U>
Diccionario<T,U> & Diccionario<T,U> :: operator=(const Diccionario<T,U> &Dicc){
    if (this!=&Dicc){
      	Borrar();
        Copiar(Dicc);
    }
    return *this;
}

template <typename T,typename U>
    bool Diccionario<T,U> :: Esta_Clave(const T &p, typename list<data<T,U> >::iterator &it_out){

      bool encontrado = false;

      if (datos.size()>0){

        it_out = datos.begin();

        while (it_out != datos.end() && (*it_out).clave < p) 
        	it_out++;
        	if ((*it_out).clave == p)
          		encontrado = true;
      	}

      	else
        	it_out=datos.end();

      return encontrado;
    }

template <typename T,typename U>
    void Diccionario<T,U> :: Insertar(const T& clave,const list<U> &info){
      typename list<data<T,U> >::iterator it;
      if (!Esta_Clave(clave,it)){
        data<T,U> p;
        p.clave = clave;
        p.info_asoci=info;
        datos.insert(it,p);
      }
    }

template <typename T,typename U>
    void Diccionario<T,U> :: AddSignificado_Palabra( const U & s , const T &p) //s es la info
    {
    	typename list<data<T,U> >::iterator it;
    	//Supongo que orden de las deficiniones no importa

    	if(Esta_Clave(p,it)) //Añadimos definicion
    	{
    		((*it).info_asoci).insert(((*it).info_asoci).end(),s);
    	}

    	else //Añadimos clave y definición
    	{
    		cout << "b";
    		list<T> lista;
    		lista.insert(lista.begin(),s);
    		Insertar(p,lista);
    	}
    }

template <typename T,typename U>
    list<U> Diccionario<T,U> :: getInfo_Asoc(const T & p) {
      typename list<data<T,U> >::iterator it;
      if (!Esta_Clave(p,it)){
        return list<U>();
      }
      else{
        return (*it).info_asoci;
      }
    }



template <typename T,typename U>
    int Diccionario<T,U> :: NumDefiniciones(const T& clave)
    {
    	int num;

    	num = getInfo_Asoc(clave).size();

    	return num;
    }

template <typename T,typename U>
    void Diccionario<T,U> :: EliminarClave(const T& clave)
    {
    	typename list<data<T,U> >::iterator it;

    	if(Esta_Clave(clave,it))
    	{
    		datos.erase(it);
    	}
    }

template <typename T,typename U>
    string Diccionario<T,U> :: MuestraClaves()
    {
    	string cad = "Las claves son: \n";

  		for (typename list<data<T,U> >::const_iterator i = datos.begin(); i != datos.end(); ++i) 
  		{	   		 
			cad += "\t" + (*i).clave + "\n";
    	}

    	return cad;
    }
