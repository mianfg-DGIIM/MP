#include <iostream>

using namespace std;

#define DIM 100

void leerArray ( char arr[], int & util ) {
	char entrada;
  cout << "Inserte a continuación caracteres. Finalice con '#':" << endl;
  int i = 0;
  while ( entrada != '#' ) {
		cin >> entrada;
		arr[i] = entrada;
    i++;
	}
  util = i;
}

void imprimirArray ( char arr[], const int util ) {
	for ( int i = 0; i < util; i++ )
		cout << arr[i];
}

void eliminarEspacios ( char arr[], int util ) {
  int length = 0, loc = -1;
  for ( int i = 0; i < util; i++ ) {
    if ( arr[i] == ' ' ) {
      if ( length == 0 ) {
        loc = i;
        length = 1;
      } else
        length++;
    } else {
      if ( length > 1 ) {
        for ( int i = loc; i < util; i++ ) {
          arr[loc] = arr[loc + length];
        }
        util -= length;
      }
      loc = -1;
      length = 0;
    }
  }
}

int main(int argc, char* argv[]) {
	int util;
  char arr[DIM];
	leerArray(arr, util);
	cout << endl << "Array leído: ";
	imprimirArray(arr, util);
	eliminarEspacios(arr, util);
  cout << endl << "Array sin espacios: ";
  imprimirArray(arr, util);
  cout << endl;
}
