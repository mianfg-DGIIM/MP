# Makefile para Práctica 2 de MP
# Autor: Miguel Ángel Fernández Gutiérrez

# Definición de macros para definir las carpetas de trabajo
BIN=./bin
OBJ=./obj
SRC=./src
INC=./include
LIB=./lib
ZIP=./zip
DOC=./doc

# Opciones de compilación
# 	-Wall muestra todas las advertencias
# 	-g compila en modo "depuración"
OPT=-Wall -g

# Nombre de la práctica
PRJ=practica2

# Macros del makefile

all : $(BIN)/intervalo
$(BIN)/intervalo : $(OBJ)/main.o $(LIB)/libintervalo.a
	g++ -o $(BIN)/intervalo $(OBJ)/main.o -lintervalo -L$(LIB)

$(OBJ)/intervalo.o: $(SRC)/intervalo.cpp $(INC)/intervalo.h
	g++ $(OPT) -c $(SRC)/intervalo.cpp -o $(OBJ)/intervalo.o -I$(INC)

$(OBJ)/main.o: $(SRC)/main.cpp $(INC)/intervalo.h
	g++ $(OPT) -c $(SRC)/main.cpp -o $(OBJ)/main.o -I$(INC)

$(LIB)/libintervalo.a: $(OBJ)/intervalo.o
	ar -rvs $(LIB)/libintervalo.a $(OBJ)/intervalo.o

clean:
	@echo "Limpiando..."
	rm -rf $(OBJ)/*.o $(BIN)/* $(LIB)/* $(ZIP)/* $(DOC)/latex $(DOC)/html

zip: clean
	@echo "Generando ZIP del proyecto " $(PRJ)
	zip -r $(ZIP)/$(PRJ).zip *

doxy:
	doxygen doc/intervalo.doxy
