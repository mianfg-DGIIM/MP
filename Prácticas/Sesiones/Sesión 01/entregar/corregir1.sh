unzip practica1.zip
g++ -c src/main.cpp -o obj/main.o -Iinclude
g++ -c src/intervalo.cpp -o obj/intervalo.o -Iinclude
ar rvs lib/libintervalo.a obj/intervalo.o
g++ obj/main.o -lintervalo -o bin/intervalo -Llib
bin/intervalo < data/intervalo.dat
