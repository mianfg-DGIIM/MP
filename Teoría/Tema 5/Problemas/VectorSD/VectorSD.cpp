/**
 * @file VectorSD.cpp
 * @author Miguel Ángel Fernández Gutiérrez <mianfg>
 */

#include "VectorSD.h"
#include <iostream>
using namespace std;

VectorSD::VectorSD () {
  array = new int[10];
  util = 0;
  capacidad = 10;
}

VectorSD::~VectorSD() {
    delete[] array;
    array = 0;
    util = 0;
    capacidad = 0;
}

VectorSD::VectorSD ( int n ) {
    assert(n>0);
    n = n/10;
    if ( n == 0 )
        n = 1;
    array = new int[n];
    util = 0;
    capacidad = n;
}

VectorSD::VectorSD(const VectorSD &vector) {
    copiar(vector);
}

VectorSD& VectorSD::operator=(const VectorSD &vector) {
    copiar(vector);
    return (*this);
}

int& VectorSD::operator[](int i) {
    assert(i >= 0 && i < util);
    return array[i];
}

bool VectorSD::operator==(const VectorSD &vector) const {
    bool es_igual = true;
    if ( util != vector.util )
        es_igual = false;
    for ( int i = 0; i < util && es_igual; i++ )
        if ( array[i] != vector.array[i] )
            es_igual = false;
    return es_igual;
}

bool VectorSD::operator!=(const VectorSD &vector) const {
    return !((*this)==vector);
}

bool VectorSD::operator<(const VectorSD &vector) const {
    bool es_menor = true;
    int menor_util;
    if ( util < vector.util )
        menor_util = util;
    else
        menor_util = vector.util;
    for ( int i = 0; i < menor_util && es_menor; i++ )
        if ( array[i] >= vector.array[i] )
            es_menor = false;
    if ( es_menor )
        es_menor = util < vector.util;
    return es_menor;
}

bool VectorSD::operator>(const VectorSD &vector) const {
    bool es_mayor = true;
    int menor_util;
    if ( util < vector.util )
        menor_util = util;
    else
        menor_util = vector.util;
    for ( int i = 0; i < menor_util && es_mayor; i++ )
        if ( array[i] <= vector.array[i] )
            es_mayor = false;
    if ( es_mayor )
        es_mayor = util > vector.util;
    return es_mayor;
}

bool VectorSD::operator<=(const VectorSD &vector) const {
    return !((*this)>vector);
}

bool VectorSD::operator>=(const VectorSD &vector) const {
    return !((*this)<vector);
}

VectorSD operator+(const VectorSD &vector) const {

}

ostream& operator<<(ostream&flujo, const VectorSD &vector) {
    flujo << l;
}

int VectorSD::getDato( int pos ) const { // ventaja: podemos usarlo con objetos constantes <!!!>
  if ( pos < util && pos >= 0 )
    return array[pos];
  else {
    cerr << "Posición incorrecta";  // sería mejor lanzar una excepción
    exit(1);
  }
}

void VectorSD::aniadir( int num ) {
  if ( util == capacidad ) {
    redimensionar(capacidad);
  }
  array[util] = caracter;
  util++;
}
