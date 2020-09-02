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

int busquedaSecuencialArray ( int arr[], const int util, const int buscar ) {
	int loc = -1;
	for ( int i = 0; i < util && util != -1; i++ )
		if ( arr[i] == buscar )
			loc = i;
	return loc;
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
	cout << endl << "Número a buscar: ";
	cin >> entrada;
	cout << "El número está en: " << busquedaSecuencialArray(arr, num_elementos, entrada) << " (-1 = no está)" << endl;
}
