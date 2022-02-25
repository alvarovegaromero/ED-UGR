HOME = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib
OBJ = $(HOME)/obj

all: $(BIN)/testdiccionario fin

#......................Ejecutables

$(BIN)/testdiccionario : $(SRC)/testdiccionario.cpp  $(INCLUDE)/diccionario.h
	@echo
	@echo Creando el ejecutable: testdiccionario
	@echo
	g++ -o $(BIN)/testdiccionario $(SRC)/testdiccionario.cpp $(INCLUDE)/diccionario.h \
	-I$(INCLUDE)
#...................... OBJETOS

#...................... BIBLIOTECAS

#......................Limpiar

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
