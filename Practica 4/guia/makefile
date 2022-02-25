HOME = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
INCLUDE = $(HOME)/include
LIB = $(HOME)/lib
OBJ = $(HOME)/obj

all: $(BIN)/testguia fin

#......................Ejecutables

$(BIN)/testguia : $(SRC)/testguia.cpp  $(INCLUDE)/guia.h
	@echo
	@echo Creando el ejecutable: testguia
	@echo
	g++ -o $(BIN)/testguia $(SRC)/testguia.cpp $(INCLUDE)/guia.h \
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
