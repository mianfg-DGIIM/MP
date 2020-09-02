#include <iostream>

using namespace std;

#define SIZE 10

void buscarCotas ( int * arr, int * &pMax, int * &pMin ) {
  pMax = arr;
  pMin = arr;
  for ( int *p = arr; p < arr+SIZE; p++ ) {
    if ( *p > *pMax )
      pMax = p;
    if ( *p < *pMin )
      pMin = p;
    }
}

// Los tres funcionan igualmente

int main() {
  int arr[SIZE] = {1,2,3,4,-5,6,-7,8,9,-10};
  int *pMax = 0, *pMin = 0;
  buscarCotas(arr, pMax, pMin);
  cout << "El máximo es " << *pMax << " (" << &pMax << ") y el mínimo es " << *pMin << " (" << &pMin << ")" << endl;
}
