/** 
 * @file Idioma.h
 * @author Miguel Ángel Fernández Gutiérrez <mianfg@correo.ugr.es>
*/

#include "Idioma.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

Idioma::Idioma() {
    _idioma = "empty";
    _nBigramas = 0;
    _conjunto = new Bigrama[0];
}

Idioma::Idioma(int nbg) {
    _idioma = "empty";
    _nBigramas = nbg;
    _conjunto = new Bigrama[nbg];
}
    
void Idioma::reservarMemoria(int n) {
    liberarMemoria();
    _conjunto = new Bigrama[n];
    _nBigramas = n;
}

void Idioma::ampliarMemoria(int n) {
    int new_size = _nBigramas+n;
    Bigrama* new_conjunto = new Bigrama[new_size];
    for ( int i = 0; i < _nBigramas; i++ ) {
        new_conjunto[i] = _conjunto[i];
    }    
    liberarMemoria();
    _nBigramas = new_size;
    _conjunto = new_conjunto;
}

void Idioma::liberarMemoria() {
    delete[] _conjunto;
    _conjunto = NULL;
    _nBigramas = 0;
}

std::string Idioma::getIdioma() const {
    return _idioma;
}
    
void Idioma::setIdioma(const std::string& id) {
    _idioma = id;
}

Bigrama Idioma::getPosicion(int p) const {
    return _conjunto[p];
}

void Idioma::setPosicion(int p, const Bigrama & bg) {
    _nBigramas++;
    Bigrama* new_conjunto = new Bigrama[_nBigramas];
    for ( int i = 1; i < _nBigramas; i++ )
        if ( i < p )
            new_conjunto[i] = _conjunto[i];
        else if ( i > p )
            new_conjunto[i] = _conjunto[i-1];
    new_conjunto[p] = bg;
    delete[] _conjunto;
    _conjunto = new_conjunto;
}

int Idioma::findBigrama(const string bg) const {
    for ( int i = 0; i < _nBigramas; i++ )
        if ( _conjunto[i].getBigrama()[0] == bg[0] && _conjunto[i].getBigrama()[1] == bg[1] )
            return i;
    return -1;
}

void Idioma::addBigrama(const Bigrama & bg) {
    int loc = findBigrama(bg.getBigrama());
    if ( loc == -1 ) {
        ampliarMemoria(1);
        _conjunto[_nBigramas-1].setBigrama(bg.getBigrama());
        _conjunto[_nBigramas-1].setFrecuencia(bg.getFrecuencia());
    } else {
        _conjunto[loc].setFrecuencia(_conjunto[loc].getFrecuencia() + bg.getFrecuencia());
    }
}

bool Idioma::cargarDeFichero(const char *fichero) {
    bool status = true;
    int num, num_bigramas; char c[3]; c[3] = '\0'; Bigrama bgr;
    ifstream fentrada;
    cout << endl << "Abriendo fichero " << fichero << endl;
    fentrada.open(fichero);
    if (fentrada) {
        fentrada.ignore();
        getline(fentrada, _idioma);
        getline(fentrada, _idioma);
        cout << "Idioma detectado: " << _idioma << endl;
        fentrada >> num_bigramas;
        if (!fentrada) {
            cerr << "Error de lectura del fichero " << fichero << endl;
            status = false;
        }
        for ( int i = 0; i < num_bigramas && status; i++ ) {
            fentrada >> c;
            fentrada >> num;
            bgr.setBigrama(c);
            bgr.setFrecuencia(num);
            liberarMemoria();
            addBigrama(bgr);
            if (!fentrada) {
                cerr << "Error cargando datos del fichero " << fichero << endl;
                status = false;
            }
        }
        fentrada.close();
    } else {
        cerr << "Error abriendo el fichero " << fichero << endl;
        status = false;
    }
    if (status)
        cout << "OK" << endl;
    return status;
}

bool Idioma::addDeFichero(const char *fichero) {
    bool status = true;
    int num, num_bigramas; char c[3]; c[3] = '\0'; Bigrama bgr; string lang;
    ifstream fentrada;
    cout << endl << "Abriendo fichero " << fichero << endl;
    fentrada.open(fichero);
    if (fentrada) {
        fentrada.ignore();
        getline(fentrada, lang);
        getline(fentrada, lang);
        cout << "Idioma detectado: " << lang << endl;
        if ( _idioma == "empty" ) {
            setIdioma(lang);
        } else {
            if ( lang != _idioma ) {
                cerr << "ERROR Idioma no compatible con " << _idioma << endl;
                status = false;
            }
        }
        
        fentrada >> num_bigramas;
        if (status) cout << "Leyendo " << num_bigramas << " bigramas" << endl;
        if (!fentrada) {
            cerr << "ERROR de lectura del fichero " << fichero << endl;
            status = false;
        }
        for ( int i = 0; i < num_bigramas && status; i++ ) {
            fentrada >> c;
            fentrada >> num;
            bgr.setBigrama(c);
            bgr.setFrecuencia(num);
            addBigrama(bgr);
            if (!fentrada) {
                cerr << "ERROR cargando datos del fichero " << fichero << endl;
                status = false;
            }
        }
        fentrada.close();
    } else {
        cerr << "ERROR abriendo el fichero " << fichero << endl;
        status = false;
    }
    if (status)
        cout << "OK" << endl;
    return status;
}