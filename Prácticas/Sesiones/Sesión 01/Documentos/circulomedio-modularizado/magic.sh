#!/bin/bash

# ESTO NO ES UN MAKEFILE, LO HACE TODO
# USO DEL SCRIPT
# 	./magic.sh nombre_ejecutable nombre_main con_librerias
#		nombre_ejecutable: nombre del archivo binario a crear
# 		nombre_main: nombre del archivo que contiene el main (sin el .cpp)
# 		con_librerias: hay dos opciones
# 			con: hacer la compilación creando librerías en lib
# 			sin: hacer la compilación sin crear librerías en lib

if [ $# -eq 3 ]
then
	if (( $3 == "con" ))
	then
		echo "Creando estructura con librerías"
	elif (( $3 == "sin" ))
	then
		echo "Creando estructura sin librerías"
		for ARCH in `ls ./src`
		do
			g++ -c src/$ARCH.cpp -o obj/$ARCH.o -Iinclude
		done
		g++ obj/*.o -o bin/$1
	else
		echo "El tercer argumento debe ser sin o con"
		for ARCH in `ls ./src -I $2.o`
		do
			g++ -c src/$ARCH.cpp -o obj/$ARCH.o -Iinclude
		done
		rm obj/$2.o
		ar rvs lib/lib$1.a obj/*.o
		g++ obj/$2.o -l$1 -o bin/$1 -Llib
	fi
else
	echo "Número de argumentos incorrecto"

fi

