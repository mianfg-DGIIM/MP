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

int buscarMinimoArray ( int arr[], const int util, const int inicio ) {
	int min = arr[0], loc = inicio;
	for ( int i = inicio; i < util; i++ )
		if ( arr[i] < min ) {
			min = arr[i];
			loc = i;
		}
	return loc;
}

int ordenarporSeleccion ( int arr[], const int util ) {
	for ( int i = 0; i < util; i++ ) {
		int loc_intercambio = buscarMinimoArray( arr, util, i );
		int aux = arr[i];
		arr[i] = arr[loc_intercambio];
		arr[loc_intercambio] = aux;
	}
}

int main(int argc, char* argv[]) {
	int num_elementos, entrada;
	cout << "Número de elementos: ";
	cin >> num_elementos;
	int arr[DIM];
	cout << endl;
	leerArray(arr, num_elementos);
	cout << endl << "Array leído: ";
	imprimirArray(arr, num_elementos);
	ordenarporSeleccion(arr, num_elementos);
	cout << endl << "Array ordenado: ";
	imprimirArray(arr, num_elementos);
	cout << endl;
}
