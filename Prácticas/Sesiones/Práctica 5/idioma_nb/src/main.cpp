/** 
 * @file main.cpp
 * @author Miguel Ángel Fernández Gutiérrez <mianfg@correo.ugr.es>
*/

#include <iostream>
#include <cstring>
#include "Bigrama.h"
#include "Idioma.h"

using namespace std;

int main(int narg, char * args[]) {
    if (narg < 3) {
        cerr << "Error en la llamada.\n   idioma <bigrama> <fich1.bgr> <fich2.bgr> ..."<<endl;
        return 1;
    }

    Idioma idioma;
    
    bool status = true;

    for ( int i = 2; i < narg && status; i++ )
        status = idioma.addDeFichero(args[i]);
    
    if (status) {
        cout << endl << "El bigrama " << args[1] << " tiene una frecuencia de "
                << idioma.getPosicion(idioma.findBigrama(args[1])).getFrecuencia()
                << " en el idioma " << idioma.getIdioma() << " ("
                << idioma.getSize() << " bigramas)" << endl;
    }
    
    idioma.liberarMemoria();
    
    // if (status) return 0; else return 1;
}