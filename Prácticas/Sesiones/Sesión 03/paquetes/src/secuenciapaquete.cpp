/**
   @file secuenciapaquete.cpp
   @author Miguel Ángel Fernández Gutiérrez <mianfg@correo.ugr.es>
**/

#include <iostream>
#include "secuenciapaquete.h"

using namespace std;

void cleanSecuenciaPaq(Paquete s[], int & util) {
    Paquete vacio;
    for ( int i = 0; i < MAXPAQ; i++ )
        s[i] = vacio;
    util = 0;
}

bool addSecuenciaPaq(Paquete s[], int & util, const Paquete & p) {
    const int MAX_PAQ = 25;
    if ( util == MAX_PAQ )
        return false;
    else {
        s[util] = p;
        util++;
        return true;
    }
}

double getTotalSecuenciaPaq(const Paquete s[], const int util) {
    double precio = 0;
    for ( int i = 0; i < util; i++ )
        precio += s[i].getFactura();
    return precio;
}

Paquete paqueteMayorSecuenciaPaq(const Paquete s[], const int util) {
    int loc = -1;
    double mayor_volumen = 0;
    for ( int i = 0; i < util; i++ )
        if ( s[i].getVolumen() > mayor_volumen ) {
            loc = i;
            mayor_volumen = s[i].getVolumen();
        }
    return s[loc];
}

double getMediaSecuenciaPaq(const Paquete s[], const int util) {
    return getTotalSecuenciaPaq( s, util ) / util;
}

int numPaqueteAltosSecuenciaPaq(const Paquete s[], const int util, const int altura) {
    int contador = 0;
    for ( int i = 0; i < util; i++ )
        if ( s[i].getAlto() > altura )
            contador++;
    return contador;
}

int numPaquetesSuperiorSecuenciaPaq(const Paquete s[], const int util ) {
    int contador = 0;
    double media = getMediaSecuenciaPaq( s, util );
    for ( int i = 0; i < util; i++ )
        if ( s[i].getFactura() > media )
            contador++;
    return contador;    
}