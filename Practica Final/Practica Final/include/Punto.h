#ifndef __PUNTO__
#define __PUNTO__

#include <iostream>

using namespace std;

class Punto{
	private:
	double latitud; //dos double o un pair, pero más comodo
	double longitud;

	public:
	Punto()  {
	    set_lat(0);
	    set_longi(0);
  	}	
	Punto(double lat, double longi)
	{
		set_lat(lat);
		set_longi(longi);
	}
		
	//set y get
   	void set_lat(double lat)
   	{
   		latitud = lat;
   	}

   	void set_longi(double longi)
   	{
   		longitud = longi;
   	}

   	double GetLatitud(void) const
   	{
   		return latitud;
   	}

	double GetLongitud(void) const
	{
		return longitud;
	}

	bool operator==(const Punto & pto) const
	{
		return(latitud == pto.latitud && longitud == pto.longitud);
	}
	bool operator<(const Punto & pto) const
	{
		if(latitud > pto.latitud)
      		return false;
    	else if(latitud < pto.latitud)
      		return true;
    	else
      		if(longitud > pto.longitud )
        		return false;
      		else 
        		return true;
	}

	bool operator!=(const Punto & pto) const
	{
		return(!(*this==pto));
	}

	bool operator>(const Punto & pto) const
	{
		return(!(*this==pto) && !(*this < pto));
	}

	//Operator << y >>
    friend istream & operator >>(istream & is,Punto & pto)
    {
		is.ignore(256, '(');
  		is >> pto.latitud;
  		is.ignore(256, ',');
  		is >> pto.longitud;
  		is.ignore(256, ')');

	    return is;
    }

    friend ostream & operator <<(ostream & os,const Punto & pto)
    {
        os << "(" << pto.GetLatitud() << "," << pto.GetLongitud() << ")";

	    return os;
    }
};

#endif
