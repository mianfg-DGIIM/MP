#include <iostream>

using namespace std;

const int DIM = 100;

void leerArray ( int arr[], const int util ) {
	int entrada;
	for ( int i = 0; i < util; i++ ) {
		cout << "Elemento " << i << ": ";
		cin >> entrada;
		arr[i] = entrada;
	}
}

void imprimirArray ( int arr[], const int util ) {
	for ( int i = 0; i < util; i++ )
		cout << arr[i] << " ";
}

void reemplazar( int arr[], int & util, int arr_in[], int util_in ) {
  for ( int i = 0; i < util_in; i++ )
    arr[i] = arr_in[i];
  util = util_in;
}

void secuenciaMonotona ( const int arr[], int util, int arr_resultado[], int & util_resultado ) {
	int loc = 0;
	int longitud = 0;
	util_resultado = 0;
	for ( int i = 0; i < util; i++ ) {
		if ( i == 0 ) {
			longitud = 1;
		} else {
			if ( arr[i] >= arr[i-1] ) {
				longitud++;
				if ( longitud > util_resultado ) {
					util_resultado = longitud;
					loc = i - longitud;
				}
			} else {
				util_resultado = 1;
			}
		}
	}

	for ( int i = 0; i < util_resultado; i++ ) {
		arr_resultado[i] = arr[loc + i + 1];
	}
}

/*
void secuenciaMonotona ( const int arr[], int util, int arr_resultado[], int & util_resultado ) {
  int arr_aux[DIM];
  int util_aux = 0;
  util_resultado = 0;
	for ( int i = 0; i < util; i++) {
    if ( i == 0 ) {
      arr_aux[0] = arr[0];
      util_aux = 1;
    } else {
      if ( arr[i] >= arr[i-1] ) {
        arr_aux[util_aux] = arr[i];
        util_aux++;
        if ( util_aux > util_resultado )
          reemplazar( arr_resultado, util_resultado, arr_aux, util_aux );
      } else {
        util_aux = 1;
        arr_aux[0] = arr[i];
      }
    }

  }
}

void secuenciaMonotonaUltima ( int arr[], int util, int arr_resultado[], int & util_resultado ) {
  util_resultado = 0;
	for ( int i = 0; i < util; i++) {
    if ( i == 0 ) {
      arr_resultado[0] = arr[0];
      util_resultado = 1;
    } else {
      if ( arr[i] >= arr[i-1] ) {
        arr_resultado[util_resultado] = arr[i];
        util_resultado++;
      } else {
        util_resultado = 1;
        arr_resultado[0] = arr[0];
      }
    }
  }
}
*/

int main(int argc, char* argv[]) {
	int num_elementos, num_elementos_resultado;
	cout << "Número de elementos: ";
	cin >> num_elementos;
	int arr[DIM];
  int arr_monotona[DIM];
	cout << endl;
	leerArray(arr, num_elementos);
	cout << endl << "Array leído: ";
	imprimirArray(arr, num_elementos);
	secuenciaMonotona(arr, num_elementos, arr_monotona, num_elementos_resultado);
	cout << endl << "Secuencia monótona: ";
  imprimirArray(arr_monotona, num_elementos_resultado);
	cout << endl;
}
