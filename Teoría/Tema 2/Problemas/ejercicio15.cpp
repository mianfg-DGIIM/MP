// CORREGIDO EN CLASE

#include <iostream>
#include <fstream> // ifstream
using namespace std;

class VectorSD {
  int *array;
  int util;
  int capacidad;
public:
  VectorSD();
  VectorSD(int n);
  int getDato(int n) const;
  void aniadir(int num);

}

VectorSD::VectorSD () {
  array = new int[10];
  util = 0;
  capacidad = 10;
}

VectorSD::VectorSD ( int n ) {
  if ( n < 0 )
    n = 10;
  array = new int[n];
  util = 0;
  capacidad = n;
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
