#include <iostream>
#include <cmath>
using namespace std;

#define DIM 100
char MORSE[50];


void morsear ( char morse[], int num, int posicion ) {
  int cambio;
  if ( num >= 0 && num <= 5 ) {
    cambio = num;
    for ( int i = 0; i < 5; i++ ) {
      if ( i < cambio )
        morse[posicion + i] = '.';
      else
        morse[posicion + i] = '-';
    }
  } else if ( num > 5 && num <= 9 ) {
    cambio = num - 5;
    for ( int i = 0; i < 5; i++ ) {
      if ( i < cambio )
        morse[posicion + i] = '-';
      else
        morse[posicion + i] = '.';
    }
  }
}

void arrayMORSE ( char MORSE[] ) {
  for ( int i = 0; i < 10; i++ )
    morsear(MORSE, i, i*5);
  MORSE[50] = '\0';
}

int num_digits ( int num ) {
  int digits = 0;
  if ( num < 0 )
    num *= -1;
  while ( num > 9 ) {
    digits++;
    num /= 10;
  }
  digits++;
  return digits;
}

int reverse ( int num ) {
  int resultado = 0;
  for ( int i = 0; i < num_digits(num); i++ ) {
    cout << endl << "i=" << i;
    resultado += (int) num / pow(10, num_digits(num) - i - 1 ) * pow(10, i);
    cout << endl << "resultado+=" << (int) num / pow(10, num_digits(num) - i - 1 ) * pow(10, i);
    num -= (int) num / pow(10, num_digits(num) - i - 1 ) * pow(10, num_digits(num) - i - 1 );
    cout << endl << "num-=" << (int) num / pow(10, num_digits(num) - i - 1 ) * pow(10, num_digits(num) - i - 1 );
  }
  return resultado;
}

void toMorse ( int num, char morse[] ) {
  arrayMORSE ( MORSE );
  int longitud = 0;
  if ( num < 0 )
    num *= -1;
  while ( num > 9 ) {
    morsear( morse, num % 10, longitud );
    longitud += 5;
    num /= 10;
  }
  morsear( morse, num, longitud );
  longitud+= 5;
  morse[longitud] = '\0';
}

// versión con espacios
void imprimirCadena ( const char array[] ) {
	for ( int i = 0; array[i] != '\0'; i++ ) {
    cout << array[i];
  }
}

int main() {
  int num; char morse[DIM];
  cout << "Introduzca un número natural: ";
  cin >> num;
  toMorse ( num, morse );
  imprimirCadena( morse );
  cout << endl;
  cout << num_digits(123);
  cout << reverse(123);
  cout << pow(10, 10);
}
