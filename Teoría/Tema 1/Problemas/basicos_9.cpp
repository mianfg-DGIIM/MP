#include <iostream>

using namespace std;

const int DIM = 100;

void leerArray ( double arr[], const int util ) {
	double entrada;
	for ( int i = 0; i < util; i++ ) {
		cout << "Elemento " << i << ": ";
		cin >> entrada;
		arr[i] = entrada;
	}
}

void imprimirArray ( double arr[], const int util ) {
	for ( int i = 0; i < util; i++ )
		cout << arr[i] << " ";
}

bool igual( double x, double y, double epsilon ) {
  return x == y;
}

void mezclarUnicos ( const double arr1[], int util_1, const double arr2[], int util_2, double arr_res[], int & util_res ) {
  util_res = 0;
  int loc_1 = 0, loc_2 = 0;
  while ( loc_1 < util_1 && loc_2 < util_2 ) {
    if ( arr1[loc_1] == arr2[loc_2] ) {
      arr_res[util_res] = arr1[loc_1];
      loc_1++;
      loc_2++;
      util_res++;
    } else if ( arr1[loc_1] < arr2[loc_2] ) {
      arr_res[util_res] = arr1[loc_1];
      loc_1++;
      util_res++;
    } else {
      arr_res[util_res] = arr2[loc_2];
      loc_2++;
      util_res++;
    }
    if ( loc_1 == util_1 )
      reached_1 = true;
    if ( loc_2 == util_2 )
      reached_2 = true;
  }
  if ( loc_2 < util_2 ) {
    for ( int i = loc_2; i < util_2; i++ ) {
      arr_res[util_res] = arr2[i];
      util_res++;
    }
  } else {
    for ( int i = loc_1; i < util_1; i++ ) {
      arr_res[util_res] = arr1[i];
      util_res++;
    }
  }
}

/*
void mezclarUnicos ( const double arr1[], int util_1, const double arr2[], int util_2, double arr_res[], int & util_res ) {
  util_res = 0;
  int loc_1 = 0, loc_2 = 0;
  bool reached_1 = false, reached_2 = false;
  while ( !reached_1 && !reached_2 ) {
    if ( arr1[loc_1] == arr2[loc_2] ) {
      arr_res[util_res] = arr1[loc_1];
      loc_1++;
      loc_2++;
      util_res++;
    } else if ( arr1[loc_1] < arr2[loc_2] ) {
      arr_res[util_res] = arr1[loc_1];
      loc_1++;
      util_res++;
    } else {
      arr_res[util_res] = arr2[loc_2];
      loc_2++;
      util_res++;
    }
    if ( loc_1 == util_1 )
      reached_1 = true;
    if ( loc_2 == util_2 )
      reached_2 = true;
  }
  if ( reached_1 && !reached_2 ) {
    for ( int i = loc_2; i < util_2; i++ ) {
      arr_res[util_res] = arr2[i];
      util_res++;
    }
  } else {
    for ( int i = loc_1; i < util_1; i++ ) {
      arr_res[util_res] = arr1[i];
      util_res++;
    }
  }
}
*/

int main(int argc, char* argv[]) {
	int util_1, util_2, util_res;
  double arr1[DIM], arr2[DIM], mezclado[DIM];
  cout << "Número de elementos (array 1): ";
	cin >> util_1;
	leerArray(arr1, util_1);
	cout << endl << "Array leído: ";
	imprimirArray(arr1, util_1);
  cout << endl << endl;
  cout << "Número de elementos (array 2): ";
	cin >> util_2;
	leerArray(arr2, util_2);
	cout << endl << "Array leído: ";
	imprimirArray(arr2, util_2);
  cout << endl;
	mezclarUnicos(arr1, util_1, arr2, util_2, mezclado, util_res);
	cout << endl << "Mezclado: ";
  imprimirArray(mezclado, util_res);
	cout << endl;
}
