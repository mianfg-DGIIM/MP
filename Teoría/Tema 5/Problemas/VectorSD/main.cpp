#include <iostream>

#include "VectorSD.h"

using namespace std;

int main( int argc, char* argv[] ) {
    VectorSD v;
    VectorSD vCcopia;
    if (argc == 1)
        cin >> v;
    else {
        ifstream flujo(argv[1]);
        if (!flujo) {
            cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
            return 1;
        }
        flujo >> v;
    }
    vCopia = v;
    ordenar(vCopia);
    cout << "Array original:" << endl << v;
    cout << "\nArray copia:" << endl << vCopia;
    return 0;
}