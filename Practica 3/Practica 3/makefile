HOME = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib
OBJ = $(HOME)/obj

all: $(BIN)/usopilas_max fin

#......................Ejecutables

$(BIN)/usopilas_max : $(SRC)/usopilas_max.cpp  $(INCLUDE)/pila_max.h
	@echo
	@echo Creando el ejecutable: uso_pila_max
	@echo
	g++ -o $(BIN)/usopilas_max $(SRC)/usopilas_max.cpp $(INCLUDE)/pila_max.h \
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


