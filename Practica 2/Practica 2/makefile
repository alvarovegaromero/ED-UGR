HOME = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib
OBJ = $(HOME)/obj

all: $(BIN)/UsoImagen fin

#......................Ejecutables

$(BIN)/UsoImagen : $(OBJ)/UsoImagen.o $(OBJ)/imagenES.o $(LIB)/libImagen.a \
				   $(LIB)/libImagenES.a
	@echo
	@echo Creando el ejecutable: UsoImagen
	@echo
	g++ -o $(BIN)/UsoImagen $(OBJ)/UsoImagen.o $(OBJ)/imagenES.o -lImagen \
															-lImagenES -L$(LIB)

#...................... OBJETOS

$(OBJ)/imagenES.o : $(SRC)/imagenES.cpp $(INCLUDE)/imagenES.h
	@echo 
	@echo Creando objeto: imagenES.o
	@echo 
	g++ -c -I$(INCLUDE) -c $(SRC)/imagenES.cpp -o $(OBJ)/imagenES.o

$(OBJ)/Imagen.o : $(SRC)/Imagen.cpp $(INCLUDE)/Imagen.h
	@echo 
	@echo Creando objeto: Imagen.o
	@echo 
	g++ -c -I$(INCLUDE) -c $(SRC)/Imagen.cpp -o $(OBJ)/Imagen.o


$(OBJ)/UsoImagen.o : $(SRC)/UsoImagen.cpp $(INCLUDE)/Imagen.h \
					 $(INCLUDE)/imagenES.h 
	@echo 
	@echo Creando objeto: funcsymain.o
	@echo 
	g++ -c $(SRC)/UsoImagen.cpp -o $(OBJ)/UsoImagen.o -I$(INCLUDE) -std=c++11

#...................... BIBLIOTECAS

$(LIB)/libImagen.a : $(OBJ)/Imagen.o
	@echo 
	@echo Creando biblioteca: Imagen.a 
	@echo
	ar rvs $(LIB)/libImagen.a  $(OBJ)/Imagen.o

$(LIB)/libImagenES.a : $(OBJ)/imagenES.o
	@echo 
	@echo Creando biblioteca: ImagenES.a 
	@echo
	ar rvs $(LIB)/libImagenES.a  $(OBJ)/imagenES.o

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


