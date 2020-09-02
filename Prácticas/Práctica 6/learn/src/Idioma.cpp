/** 
 * @file Idioma.cpp
 * @author Miguel Ángel Fernández Gutiérrez <mianfg@correo.ugr.es>
*/

#include "Idioma.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

Idioma::Idioma() {
    _idioma = "unknown";
    _nBigramas = 0;
    _conjunto = new Bigrama[0];
}

Idioma::Idioma(int nbg) {
    _idioma = "unknown";
    _nBigramas = nbg;
    _conjunto = new Bigrama[nbg];
}

Idioma::Idioma(const Idioma& orig) {
    copiar(orig);
}

Idioma::~Idioma() {
    _idioma = "unknown";
    _nBigramas = 0;
    delete [] _conjunto;
    _conjunto = 0;
}

Idioma& Idioma::operator=(const Idioma& orig) {
    copiar(orig);
    return *this;
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
    _conjunto[p] = bg;
}

int Idioma::findBigrama(const string& bg) const {
    for ( int i = 0; i < _nBigramas; i++ )
        if ( _conjunto[i].getBigrama()[0] == bg[0] && _conjunto[i].getBigrama()[1] == bg[1] )
            return i;
    return -1;
}

void Idioma::ampliarMemoria(int n) {
    int new_size = _nBigramas+n;
    Bigrama* new_conjunto = new Bigrama[new_size];
    for ( int i = 0; i < _nBigramas; i++ )
        new_conjunto[i] = _conjunto[i];
    liberarMemoria();
    _nBigramas = new_size;
    _conjunto = new_conjunto;
}

void Idioma::addBigrama(const Bigrama & bg) {
    int loc = findBigrama(bg.getBigrama());
    if ( loc == -1 ) {
        ampliarMemoria(1);
        _conjunto[_nBigramas-1].setBigrama(bg.getBigrama());
        _conjunto[_nBigramas-1].setFrecuencia(bg.getFrecuencia());
    } else
        _conjunto[loc].setFrecuencia(_conjunto[loc].getFrecuencia() + bg.getFrecuencia());
}

double Idioma::distancia(const Idioma& otro) const {
    
}

void Idioma::ordenar() {
    ordenaDescFrec(_conjunto, _nBigramas);
}

ostream & operator<<(ostream & os, const Idioma & i) {
    os << "MP-BIGRAMAS_IDIOMA-T-1.0" << endl;
    os << i._idioma << endl;
    os << i._nBigramas << endl;
    for ( int k = 0; k < i._nBigramas; k++ )
        os << i._conjunto[k].getBigrama() << " " << i._conjunto[k].getFrecuencia() << endl;
    return os;
}

istream & operator>>(istream & os, Idioma & i) {
    int num, num_bigramas; char c[3]; c[3] = '\0'; Bigrama bgr; string lang;
    os.ignore();
    getline(os, lang);
    getline(os, lang);
    os >> num_bigramas;        
    for ( int k = 0; k < num_bigramas; k++ ) {
        os >> c;
        os >> num;
        bgr.setBigrama(c);
        bgr.setFrecuencia(num);
        i.addBigrama(bgr);
    }
    return os;
}

bool Idioma::salvarAFichero(const char *fichero) const {
    bool status = true;
    ofstream fsalida;
    fsalida.open(fichero);
    if (fsalida)
        fsalida << *this;
    else {
        status = false;
        cerr << "Error guardando datos en " << fichero << endl;
    }
    fsalida.close();
    return status;
}

bool Idioma::cargarDeFichero(const char *fichero) {
    bool status = true;
    ifstream fentrada;
    fentrada.open(fichero);
    if (fentrada)
        fentrada >> *this;
    else {
        status = false;
        cerr << "Error cargando datos de " << fichero << endl;
    }
    fentrada.close();
    return status;
}

void Idioma::reservarMemoria(int n) {
    liberarMemoria();
    _conjunto = new Bigrama[n];
    _nBigramas = n;
}

void Idioma::liberarMemoria() {
    delete[] _conjunto;
    _conjunto = NULL;
    _nBigramas = 0;
}

void Idioma::copiar(const Idioma& otro) {
    _idioma = otro._idioma;
    _nBigramas = otro._nBigramas;
    _conjunto = new Bigrama[_nBigramas];
    for ( int i = 0; i < _nBigramas; i++ )
        _conjunto[i] = otro._conjunto[i];
}
