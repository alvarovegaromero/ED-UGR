#include "Imagen.h"
#include <cmath>

using namespace std; 


//Reservar memoria para la matriz. Común a los constructores
void Imagen :: ReservaMemoria ()
{
	// Solo si se cumplen las precondiciones se reserva memoria 
	img = 0;
 
	if (filas>0 && cols>0) {
		//Vector de punteros a bytes
		img = new byte * [filas];

		for (int f=0; f<filas; f++)
			//Cada vector de punteros apunta a un vector de bytes 
			img[f] = new byte [cols];
	}
}

//Liberar memoria de la matriz. Pone a 0 los atributos de inst
void Imagen :: LiberaMemoria ()
{
	if (img != 0) {

		// Liberar cada una de las filas
		for (int f=0; f<filas; f++)
 			delete [] img[f];

 		// Liberar el vector de punteros
 		delete [] img; 
   
		// Se pone a 0 el puntero que da acceso al vector de punteros a filas
		img = 0;
		filas  = 0;
		cols  = 0;
	}
}

//Constructor por defecto
Imagen :: Imagen (){
	filas = 0;
	cols = 0;

	ReservaMemoria();
}

//Constructor con parámetros
Imagen :: Imagen (int nfilas, int ncols){
	filas = nfilas;
	cols = ncols;

	ReservaMemoria();
}

//Constructor de copia
Imagen :: Imagen (const Imagen & J){
	filas = J.num_filas();
	cols = J.num_columnas();

	ReservaMemoria();

	for (int i = 0; i < filas; i++)
        memcpy (img[i], J.img[i], 
                  J.cols*sizeof(unsigned char));
}

//Destructor
Imagen :: ~Imagen(){
	LiberaMemoria();
}

//Consultor de filas
int Imagen :: num_filas() const{
	return filas;
}

//Consultor de columnas
int Imagen :: num_columnas() const{
	return cols;
}

//Método de cambiar valor de un pixel
void Imagen :: asigna_pixel (int fila, int col, unsigned char valor){
	img[fila][col] = valor;
}

//Método para visualizar el valor de un pixel
byte Imagen :: valor_pixel (int fila, int col) const{
	return img[fila][col];
}

//Método para visualizar la matriz
string Imagen :: ToString (void){
	string cad;

	string delimitador = "..................................";

	cad = "\n" + delimitador + "\n";
	cad = cad + "Filas = " + to_string(num_filas()) + 
		      ", Columnas = " + to_string (num_columnas()) + "\n\n";

	if (img != 0) {	
		for (int f=0; f<num_filas(); f++) {
			cad = cad + "Fila " + to_string(f) + " --> ";
				
			for (int c=0; c<num_columnas(); c++) 
				cad = cad + to_string(img[f][c]) + "  ";
			cad = cad + "\n";
		}
	} 
		
	cad = cad + delimitador + "\n\n";

	return (cad);
}

//Método que permite umbralizar en función de dos valores
void Imagen :: umbralizar(byte T1, byte T2){
	
	for(int i = 0 ; i < filas ; i++)
		for(int j = 0 ; j < cols ; j++)
		{

			if(valor_pixel(i,j) < T1)
				asigna_pixel(i,j, (byte) 0);
			
			else if(valor_pixel(i,j) > T2)
				asigna_pixel(i,j, (byte) 255);	
		}
}

//Método que permite hacer zoom sobre una porcion de una imagen
Imagen Imagen :: ZoomPorcion(int x1, int y1, int x2, int y2){

	Imagen tmp ((2*(x2-x1)-1),(2*(y2-y1)-1));

	for(int i = 0 ; i < (x2-x1) ; i++) //Asignamos los valores que conocemos
		for(int j = 0 ; j < (y2-y1) ; j++) // de la imagen original
			tmp.asigna_pixel(2*i,2*j,valor_pixel(x1+i,y1+j));
	
	tmp.InterpolaColumnas();
	tmp.InterpolaFilas();

	LiberaMemoria();	//Liberamos la memoria dedicada a la img original

	return tmp;
}

//InterpolaColumnas - Necesario para ZoomPorción
void Imagen :: InterpolaColumnas()
{
	byte interpolacion;

	for(int i = 0 ; i < filas ;i = i+2) //Avanzamos en todas las filas
		for(int j = 0 ; j < cols-2 ;j = j+2) //cols-2 ya que ult col iría sola
		{
			interpolacion = (byte) (((int)img[i][j] + (int)img[i][j+2])/2.0);		

			img[i][j+1] = interpolacion; //Insertar en la pos j+1 de la fila
		}	
}

//InterpolaFilas - Necesario para ZoomPorción
void Imagen :: InterpolaFilas()
{
	byte interpolacion;

	for(int i = 0 ; i < filas-2 ;i = i+2) //filas-2 ya que ult fil iría sola
		for(int j = 0 ; j < cols ; j++) //Interpolamos en todas las cols
		{
			interpolacion = (byte) (((int)img[i][j] + (int)img[i][j+2])/2.0);	

			img[i+1][j] = interpolacion; //Insertar entre 2 filas en cada col
		}	
}

//Devuelve una imagen con un icono de la imagen del objeto implícito
Imagen Imagen :: Icono (int nf, int nc)
{
	Imagen tmp(nf, nc);
	
	bool propfils_entero = (filas % nf == 0); //Saber si nf es divisor de fils
	bool propcols_entero = (cols % nc == 0);  // o con las columnas para ver
											  //props son enteras

	double proporcion_fils = 1.0 * filas / nf; //Por cada cuantas filas/cols
	double proporcion_cols = 1.0 * cols / nc; //originales se forma en icono 

	
	//Num de filas y cols con prop o mas valores para calcular la media
	int filas_completas = (int) nf * (proporcion_fils - (int) proporcion_fils);
	int cols_completas = (int) nc * (proporcion_cols - (int) proporcion_cols);


	int elem_filcompleta = proporcion_fils; 
	int elem_colcompleta = proporcion_cols;

	if(!propfils_entero)  if (!propcols_entero) 
		elem_filcompleta++;			//Cuantos elem. se cogen de una f o c
									//para los prop_fils primeros
	if (!propcols_entero) 
		elem_colcompleta++;

	//1er for. Hasta filas completas y cols_completas
	
	for(int i = 0 ; i < filas_completas ; i++)
		for(int j = 0 ; j < cols_completas ; j++)
			tmp.img[i][j] = (byte) Media(i*elem_filcompleta,
									 j*elem_colcompleta,
									 (i+1)*(elem_filcompleta)-1,
									 (j+1)*(elem_colcompleta)-1);
						//i+1 y j+1 ya que es hasta el lugar donde calcularemos
						//la prox media. -1 ya que no la incluimos

	//2ndo zona. Hasta la columna final y filas completas

	if(!propcols_entero)	//Si la prop de cols no es entera y el tam de cols
		elem_colcompleta--;	

	for(int i = 0 ; i < filas_completas ; i++)
		for(int j = cols_completas ; j < nc ; j++)	
			tmp.img[i][j] = (byte) Media(i*elem_filcompleta,
									 j*(elem_colcompleta)+cols_completas,
									 (i+1)*(elem_filcompleta)-1,
									 (j+1)*(elem_colcompleta)-1+cols_completas);
	//+cols_completas ya que tenemos que tener en cuenta las cols ya procesadas	
	// y asi en el resto de bucles anidados

	//3er zona. Hasta la fila final y col_completas

	if(!propfils_entero)	//Si la prop de filas no es entera y el tam de filas 
		elem_filcompleta--;	 

	if(!propcols_entero)
		elem_colcompleta++;  //Volvemos a incrementar su valor para llegar a 	 
							//col_completas

	for(int i = filas_completas ; i < nf ; i++)
		for(int j = 0 ; j < cols_completas ; j++)
			tmp.img[i][j] = (byte) Media(i*elem_filcompleta+filas_completas,
									j*elem_colcompleta,
									(i+1)*(elem_filcompleta)-1+filas_completas,
									(j+1)*(elem_colcompleta)-1);

	//4.Resto de Imagen. Hasta la fila y columna final

	if(!propcols_entero)	//Decrementamos si no es entera
		elem_colcompleta--;
	
	for(int i = filas_completas ; i < nf ; i++)
		for(int j = cols_completas ; j < nc ; j++)
			tmp.img[i][j] = (byte) Media(i*elem_filcompleta+filas_completas,
								j*elem_colcompleta+cols_completas,
								(i+1)*(elem_filcompleta)-1+filas_completas,
								(j+1)*(elem_colcompleta)-1+cols_completas);

	return tmp;

	//Si fuese una division entera, solo hariamos el últ bucle anidado
	// ya que fils y cols_completas serian 0.
}

//Media - Necesario para Icono
int Imagen :: Media(int x1, int y1, int x2, int y2)
{
	double valor = 0;	//OJO: pixel 256 es 255 aqui
	for(int i = x1 ; i <= x2 ; i++){
		for(int j = y1; j <= y2 ; j++)
		{
			valor +=(int) img[i][j];
		}
	}
	
	valor = (int) (0.5 + valor / ((x2-x1+1)*(y2-y1+1))); //+0.5 para redondear

	return valor;
}

//Método que permite constrastar una imagen dada entre dos valores
void Imagen :: constrastar(byte min, byte max)
{
	//Primero buscamos el valor mas bajo y mas alto de la matriz de bytes img

	int a = 255;	//Valor inicial el peor caso posible para que se actualice
	int b = 0;

	for(int i = 0; i < filas ; i++)
		for(int j = 0 ; j < cols ; j++)
		{
			if(img[i][j] < a)
				a = img[i][j];
			if(img[i][j] > b)
				b = img[i][j];
		}

	const double cte = (double) (max - min) / (b - a);
	
	for(int i = 0; i < filas ; i++)
		for(int j = 0 ; j < cols ; j++)
		{
			img[i][j] = round(min + (cte * (img[i][j] - a)));
		}
}


