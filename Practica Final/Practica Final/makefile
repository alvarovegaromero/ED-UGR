HOME = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib
OBJ = $(HOME)/obj

all: $(BIN)/rutas_aereas fin

#......................Ejecutable

$(BIN)/rutas_aereas : $(OBJ)/rutas_aereas.o $(LIB)/libImagen.a \
					  $(INCLUDE)/Punto.h $(INCLUDE)/Ruta.h \
					  $(INCLUDE)/Almacen_Rutas.h $(INCLUDE)/Pais.h \
					  $(INCLUDE)/Paises.h

	@echo
	@echo Creando el ejecutable: rutas_aereas
	@echo
	g++ -o $(BIN)/rutas_aereas $(OBJ)/rutas_aereas.o -lImagen -L$(LIB)

$(BIN)/pruebarotacion : $(OBJ)/pruebarotacion.o $(LIB)/libImagen.a \

	@echo
	@echo Creando el ejecutable: pruebarotacion
	@echo
	g++ -o $(BIN)/pruebarotacion $(OBJ)/pruebarotacion.o -lImagen \
														-L$(LIB)

$(BIN)/pruebapegado : $(OBJ)/pruebapegado.o $(LIB)/libImagen.a \

	@echo
	@echo Creando el ejecutable: pruebapegado
	@echo
	g++ -o $(BIN)/pruebapegado $(OBJ)/pruebapegado.o -lImagen \
														-L$(LIB)

$(BIN)/pruebaruta : $(SRC)/pruebaruta.cpp  $(INCLUDE)/Punto.h $(INCLUDE)/Ruta.h
	@echo
	@echo Creando el ejecutable: pruebaruta
	@echo
	g++ -o $(BIN)/pruebaruta $(SRC)/pruebaruta.cpp $(INCLUDE)/Punto.h \
	$(INCLUDE)/Ruta.h -I$(INCLUDE)


$(BIN)/pruebaalmacen : $(SRC)/pruebaalmacen.cpp  $(INCLUDE)/Punto.h \
					   $(INCLUDE)/Ruta.h $(INCLUDE)/Almacen_Rutas.h
	@echo
	@echo Creando el ejecutable: pruebaalmacen
	@echo
	g++ -o $(BIN)/pruebaalmacen $(SRC)/pruebaalmacen.cpp $(INCLUDE)/Punto.h \
	$(INCLUDE)/Ruta.h $(INCLUDE)/Almacen_Rutas.h -I$(INCLUDE)

$(BIN)/pruebapaises : $(SRC)/pruebapaises.cpp  $(INCLUDE)/Punto.h \
					   $(INCLUDE)/Pais.h $(INCLUDE)/Paises.h
	@echo
	@echo Creando el ejecutable: pruebapaises
	@echo
	g++ -o $(BIN)/pruebapaises $(SRC)/pruebapaises.cpp $(INCLUDE)/Punto.h \
	$(INCLUDE)/Pais.h $(INCLUDE)/Paises.h -I$(INCLUDE)
	
#...................... OBJETOS

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INCLUDE)/imagenES.h
	@echo 
	@echo Creando objeto: imagenES.o
	@echo 
	g++ -c -I$(INCLUDE) -c $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/imagen.o : $(SRC)/imagen.cpp $(INCLUDE)/imagen.h $(INCLUDE)/imagenES.h
	@echo 
	@echo Creando objeto: imagen.o
	@echo 
	g++ -c -I$(INCLUDE) -c $(SRC)/imagen.cpp -o $(OBJ)/imagen.o


$(OBJ)/pruebarotacion.o : $(SRC)/pruebarotacion.cpp $(INCLUDE)/imagen.h
	@echo 
	@echo Creando objeto: pruebarotacion.o
	@echo 
	g++ -c $(SRC)/pruebarotacion.cpp -o $(OBJ)/pruebarotacion.o -I$(INCLUDE) \
		-std=c++11

$(OBJ)/rutas_aereas.o : $(SRC)/rutas_aereas.cpp $(INCLUDE)/Punto.h \
						$(INCLUDE)/Ruta.h \
					  	$(INCLUDE)/Almacen_Rutas.h $(INCLUDE)/Pais.h \
					  	$(INCLUDE)/Paises.h
	@echo 
	@echo Creando objeto: rutas_aereas.o
	@echo 
	g++ -c $(SRC)/rutas_aereas.cpp -o $(OBJ)/rutas_aereas.o -I$(INCLUDE) \
		-std=c++11

$(OBJ)/pruebapegado.o : $(SRC)/pruebapegado.cpp $(INCLUDE)/imagen.h
	@echo 
	@echo Creando objeto: pruebapegado.o
	@echo 
	g++ -c $(SRC)/pruebapegado.cpp -o $(OBJ)/pruebapegado.o -I$(INCLUDE) \
		-std=c++11		

$(OBJ)/pruebaruta.o : $(SRC)/pruebaruta.cpp $(INCLUDE)/Punto.h $(INCLUDE)/Ruta.h
	@echo 
	@echo Creando objeto: pruebaruta.o
	@echo 
	g++ -c $(SRC)/pruebaruta.cpp -o $(OBJ)/pruebaruta.o -I$(INCLUDE) \
		-std=c++11

#...................... BIBLIOTECAS

$(LIB)/libImagen.a : $(OBJ)/imagen.o $(OBJ)/imagenES.o
	@echo 
	@echo Creando biblioteca: imagen.a 
	@echo
	ar rvs $(LIB)/libImagen.a $(OBJ)/imagen.o $(OBJ)/imagenES.o

###########################Limpiar

clean : 

	@echo 
	@echo Borrando objetos
	-rm obj/*
	@echo 

mr.proper : clean

	@echo 
	@echo Borrando ejecutables
	-rm bin/*
	@echo 
	@echo Borrando bibliotecas
	-rm lib/*

#..Extra

fin:
	@echo
	@echo Terminado
	@echo


