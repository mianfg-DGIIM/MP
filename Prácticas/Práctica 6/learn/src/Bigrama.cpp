/** 
 * @file Bigrama.cpp
 * @author Miguel Ángel Fernández Gutiérrez <mianfg@correo.ugr.es>
*/

#include <cstring>
#include <iostream>
#include "Bigrama.h"

using namespace std;

Bigrama::Bigrama() {
    _bigrama[0] = '\0';
    _frecuencia = -1;
}

const char* Bigrama::getBigrama() const {
    return _bigrama;
}

int Bigrama::getFrecuencia() const {
    return _frecuencia;
}

void Bigrama::setBigrama(const char cadena[]) {
    if (strlen(cadena) == 2) {
        strcpy(_bigrama, cadena);
        _bigrama[2] = '\0';
    }
}

void Bigrama::setFrecuencia(int frec) {
    _frecuencia = frec;
}

bool esBigramaMenor( const char* a, const char* b ) {
    bool esMenor = false;
    if ( a[0] < b[0] )
        esMenor = true;
    else if ( a[0] == b[0] )
        if ( a[1] < b[1] )
            esMenor = true;
    return esMenor;
}

void ordenaAscFrec(Bigrama *v, int n) {
    for ( int i = 0; i < n; i++ ) {
        int loc = i;
        for ( int j = i+1; j < n; j++ )
            if ( v[j].getFrecuencia() < v[loc].getFrecuencia() )
                loc = j;
        Bigrama aux = v[i];
        v[i] = v[loc];
        v[loc] = aux;
    }
}

void ordenaDescFrec(Bigrama *v, int n) {
    for ( int i = 0; i < n; i++ ) {
        int loc = i;
        for ( int j = i+1; j < n; j++ )
            if ( v[j].getFrecuencia() > v[loc].getFrecuencia() )
                loc = j;
        Bigrama aux = v[i];
        v[i] = v[loc];
        v[loc] = aux;
    }
}

void ordenaAscBigr(Bigrama *v, int n) {
    Bigrama* aux = new Bigrama[n];
    char* bigrama_minuscula;
    for ( int i = 0; i < n; i++ ) {
        bigrama_minuscula = new char[3];
        bigrama_minuscula[2] = '\0';
        for ( int j = 0; j < 2; j++ )
            bigrama_minuscula[j] = tolower(v[i].getBigrama()[j]);
        aux[i].setBigrama(bigrama_minuscula);
        delete[] bigrama_minuscula;
    }
    for ( int i = 0; i < n; i++ ) {
        int loc = i;
        for ( int j = i+1; j < n; j++ )
            if ( esBigramaMenor(aux[j].getBigrama(), aux[loc].getBigrama()) )
                loc = j;
        Bigrama cop = v[i];
        v[i] = v[loc];
        v[loc] = cop;
    }
    delete[] aux;
}

void imprimeBigramas(const Bigrama *v, int n)  {
    cout << "Lista de " << n << " bigramas:" <<endl;
    for (int i=0; i<n; i++)
        cout << v[i].getBigrama()[0] << v[i].getBigrama()[1] << "-" << v[i].getFrecuencia()<< ", "; // << endl;
}

void copiarBigrama( const Bigrama *original, Bigrama *& v, int n ) {
    for ( int i = 0; i < n; i++ )
        v[i] = original[i];
}

void sumaBigramas(const Bigrama *v1, int nv1, const Bigrama *v2, int nv2, Bigrama *&res, int & nres) {
    Bigrama *v1_temp, *v2_temp;
    v1_temp = new Bigrama[nv1];
    v2_temp = new Bigrama[nv2];
    copiarBigrama(v1, v1_temp, nv1);
    copiarBigrama(v2, v2_temp, nv2);
    ordenaAscBigr(v1_temp, nv1);
    ordenaAscBigr(v2_temp, nv2);
    for ( int i = 0; i < nv1; i++ ) {
        res[i].setBigrama(v1_temp[i].getBigrama());
        res[i].setFrecuencia(v1_temp[i].getFrecuencia()+v2_temp[i].getFrecuencia());
    }
    delete[] v1_temp;
    delete[] v2_temp;
}