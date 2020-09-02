#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int DIM = 100;

void generarArray( int arr[], const int util, const int min, const int max ) {
	srand(time(NULL));
	for ( int i = 0; i < util; i++ ) {
		arr[i] = rand() % (max-min+1) + min;
	}
}

void imprimirArray ( int array[], const int util ) {
	cout << util << endl;
	for ( int i = 0; i < util; i++ )
		cout << array[i] << " ";
	cout << endl;
}

int main() {
	int num_elementos, min, max;
	cout << "Número de elementos: ";
	cin >> num_elementos;
	cout << "Mínimo: ";
	cin >> min;
	cout << "Máximo: ";
	cin >> max;
	int arr[DIM];
	generarArray(arr, num_elementos, min, max);
	cout << endl;
	imprimirArray(arr, num_elementos);
}
