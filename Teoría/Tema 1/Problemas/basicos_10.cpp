#include <iostream>

using namespace std;

const int DIM = 100;

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

void imprimirFrecuencias ( char arr[], int util ) {
  int arr_frec[26], char_ascii = -1;
  for ( int i = 0; i < 26; i++ )
    arr_frec[i] = 0;
  for ( int i = 0; i < util; i++ ) {
    if ( (int) arr[i] >= (int) 'A' && (int) arr[i] <= (int) 'Z' )
      char_ascii = ((int) arr[i]) - ((int) 'A');
    else if ( (int) arr[i] >= (int) 'a' && (int) arr[i] <= (int) 'z' )
      char_ascii = ((int) arr[i]) - ((int) 'a');
    if ( char_ascii != -1 )
      arr_frec[char_ascii]++;
    char_ascii = -1;
  }
  for ( int i = 0; i < 26; i++ ) {
    if ( arr_frec[i] != 0 )
      cout << (char) (i+(int)'A') << " -> " << arr_frec[i] << endl;
  }
}

int main(int argc, char* argv[]) {
	int util;
  char arr[DIM];
	leerArray(arr, util);
	cout << endl << "Array leído: ";
	imprimirArray(arr, util);
  cout << endl << endl;
	imprimirFrecuencias(arr, util);
}
