/** 
 * @file main.cpp
 * @author Miguel Ángel Fernández Gutiérrez <mianfg@correo.ugr.es>
*/
#include <iostream>
#include <cstring>
#include "Bigrama.h"

using namespace std;

int main() {
    // char s[60];
    int frec, nv1, nv2, nv3;
    char cadena[3]; cadena[3] = '\0';
    Bigrama *v1=NULL, *v2=NULL, *v3=NULL;
    
    // Lee número de elementos del primer vector
    cin >> nv1;
    v1 = new Bigrama[nv1];
    // Lee el primer vector
    for ( int i = 0; i < nv1; i++ ) {
        cin >> cadena[0];
        cin >> cadena[1];
        cin >> frec;
        v1[i].setBigrama(cadena);
        v1[i].setFrecuencia(frec);
    }
    
    // Lee número de elementos del segundo vector
    cin >> nv2;
    v2 = new Bigrama[nv2];
    // Lee el segundo vector
    for ( int i = 0; i < nv2; i++ ) {
        cin >> cadena[0];
        cin >> cadena[1];
        cin >> frec;
        v2[i].setBigrama(cadena);
        v2[i].setFrecuencia(frec);
    }
    
    cout << endl <<"Contenido de v1" << endl; imprimeBigramas(v1, nv1);
    cout << endl <<"Contenido de v2" << endl; imprimeBigramas(v2, nv2);
    
    // Posibles operaciones intermedias sobre v1 o v2 
    v3 = new Bigrama[nv1];
    nv3 = nv1;
    
    sumaBigramas(v1, nv1, v2, nv2, v3, nv3);
    delete[] v1;
    delete[] v2;
    
    ordenaAscFrec(v3, nv3);
    cout << endl <<"Contenido de v3" << endl; imprimeBigramas(v3, nv3);
    cout << endl;

    // Limpieza de memoria
    delete[] v3;
    
    return 0;
}

