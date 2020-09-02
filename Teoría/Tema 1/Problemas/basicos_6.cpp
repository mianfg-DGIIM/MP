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

int busquedaBinariaArray ( const int arr[], int util, int buscar ) {
	int izq = 0, der = util-1;
	while ( izq <= der ) {
		int centro = (der-izq)/2;
		if ( arr[centro] > buscar )
			der = centro;
		else if ( arr[centro] < buscar )
			izq = centro;
		else
			return centro;
	}
	return -1;
}

int main(int argc, char* argv[]) {
	int num_elementos, buscar;
	cout << "Número de elementos: ";
	cin >> num_elementos;
	int arr[DIM];
	cout << endl;
	leerArray(arr, num_elementos);
	cout << endl << "Array leído: ";
	imprimirArray(arr, num_elementos);
	cout << endl << "Buscar: ";
	cin >> buscar;
	cout << "Se encuentra en el: " << busquedaBinariaArray(arr, num_elementos, buscar) << " (-1 si no está)" << endl;
}
