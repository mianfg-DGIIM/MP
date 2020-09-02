#include <iostream>

using namespace std;

#define SIZE 10

void cambiarSigno ( int * p ) {
  for ( int i = 0; i < SIZE; i++ )
    if ( *(p+i) < 0 )
      *(p+i) = *(p+i) * -1;
}

void cambiarSignoV2 ( int * arr ) {
  for ( int *p = arr; p < arr + SIZE; p++ )
    if ( *p < 0 )
      *p = -1 * *p;
}

void cambiarSignoV3 ( int arr[] ) {
  for ( int *p = arr; p < arr + SIZE; p++ )
    if ( *p < 0 )
      *p = -1 * *p;
}

// Los tres funcionan igualmente

int main() {
  int arr[SIZE] = {1,2,3,4,-5,6,-7,8,9,-10};
  cambiarSignoV2(arr);
  for ( int i = 0; i < SIZE; i++ )
    cout << arr[i] << " ";
  cout << endl;
}
