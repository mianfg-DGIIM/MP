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

int buscarMinimoArray ( int arr[], const int util ) {
	int min = arr[0];
	for ( int i = 0; i < util; i++ )
		if ( arr[i] < min )
			min = arr[i];
	return min;
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
	cout << endl << "Mínimo: " << buscarMinimoArray(arr, num_elementos) << endl;
}
