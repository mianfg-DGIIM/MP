#include <iostream>

using namespace std;

void elevarAlCuadrado ( int* dato ) {
  *dato = (*dato)*(*dato);
  dato = 0;
}

int main() {
  int a=6;
  int *q;
  q = &a;
  elevarAlCuadrado(q);
  q = 0;
  cout << a << " " << q << endl;
}
