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

bool localizarSecuencialArray ( int arr[], int desde, int hasta, int buscar ) {
	bool loc = false;
	for ( int i = desde; i < hasta && !loc; i++ ) {
		if ( arr[i] == buscar )
			loc = true;
	}
	return loc;
}

void eliminarRepetidosArray ( int arr[], int & util ) {
	for ( int i = 1; i < util; i++ ) {
		if ( localizarSecuencialArray( arr, 0, i, arr[i] ) ) {
			for ( int k = i; k < util; k++ )
				arr[k] = arr[k+1];
			util -= 1;
			i--;
		}
	}
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
	eliminarRepetidosArray(arr, num_elementos);
	cout << endl << "Repetidos eliminados: ";
	imprimirArray(arr, num_elementos);
	cout << endl;
}
