#!/bin/bash

# SCRIPT PARA CREAR ESTRUCTURA DE ARCHIVOS EN MP
# Alumno: Miguel Ángel Fernández Gutiérrez

# USO DEL SCRIPT
# 	./magic.sh opcion nombre_ejecutable nombre_main nombre_libreria
# 		opcion: hay tres opciones
# 			-con: hacer la compilación creando librerías en lib
# 			-sin: hacer la compilación sin crear librerías en lib
# 			-h o -help: mostrar ayuda
#		nombre_ejecutable: nombre del archivo binario a crear
# 		nombre_main: nombre del archivo que contiene el main (sin el .cpp)
# 		nombre_libreria: nombre de la libreria (si has escogido opción -con)

mkdir bin data doc include lib obj src  &> /dev/null

if [[ "$1" == "-h" || "$1" == "-help" ]]
then
	echo SCRIPT PARA CREAR ESTRUCTURA DE ARCHIVOS EN MP
	echo ""
	echo "El script se usa de la siguiente forma:"
	echo "   ./magic.sh opcion nombre_ejecutable nombre_main nombre_libreria"
	echo ""
	echo "opcion: hay tres opciones"
	echo "   -con: hacer la compilación creando librerías en lib"
	echo "   -sin: hacer la compilación sin crear librerías en lib"
	echo "   -h o -help: mostrar esta ayuda"
	echo "nombre_ejecutable: nombre del archivo binario a crear"
	echo "nombre_main: nombre del archivo que contiene el main (sin el .cpp)"
	echo "nombre_libreria: nombre de la libreria (si has escogido opción -con)"
	echo ""
	echo "NOTA IMPORTANTE: para compilar el programa debes tener al menos:"
	echo "   - Los archivos .cpp en una carpeta, src"
	echo "   - Los archivos .h en una carpeta, include"
elif [[ "$1" == "-sin" ]]
then
	if [[ $# -eq 3 ]]
	then
		echo "Creando estructura sin librerías"
		for ARCH in `ls ./src | sed -e 's/\.cpp$//'`
		do
			echo Creando archivo objeto obj/$ARCH.o
			g++ -c src/$ARCH.cpp -o obj/$ARCH.o -Iinclude
		done
		echo Compilando archivos objeto en binario bin/$1
		g++ obj/*.o -o bin/$2
		echo "Listo :)"
	else
		echo "Has insertado mal los argumentos :("
		echo "Usa ./magic.sh -h para mostrar ayuda"
	fi
elif [[ "$1" == "-con" ]]
then
	if [[ $# -eq 4 ]]
	then
		echo "Creando estructura con librerías"
		rm obj/$2.o &> /dev/null
		for ARCH in `ls ./src | sed -e 's/\.cpp$//'`
		do
			echo Creando archivo objeto obj/$ARCH.o
			g++ -c src/$ARCH.cpp -o obj/$ARCH.o -Iinclude
		done
		echo Creando librería lib/lib$4.a
		ar rvs lib/lib$4.a obj/*.o
		echo Compilando archivos objeto y librería en binario bin/$2
		g++ obj/$3.o -l$4 -o bin/$2 -Llib
		echo "Listo :)"
	else
		echo "Has insertado mal los argumentos :("
		echo "Usa ./magic.sh -h para mostrar ayuda"
	fi
else
	echo "Has insertado una orden que no existe :o"
	echo "Usa ./magic.sh -h para mostrar ayuda"
fi
