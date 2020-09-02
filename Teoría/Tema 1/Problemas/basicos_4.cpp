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

void invertirArray ( int arr[], const int util ) {
	for ( int i = 0; i < util / 2; i++ ) {
		int aux = arr[i];
		arr[i] = arr[util-i-1];
		arr[util-i-1] = aux;
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
	invertirArray(arr, num_elementos);
	cout << endl << "Array invertido: ";
	imprimirArray(arr, num_elementos);
	cout << endl;
}
