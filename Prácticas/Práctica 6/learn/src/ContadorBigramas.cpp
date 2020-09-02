/** 
 * @file ContadorBigramas.cpp
 * @author Miguel Ángel Fernández Gutiérrez <mianfg@correo.ugr.es>
*/

#include "ContadorBigramas.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ContadorBigramas::ContadorBigramas(const std::string& caracteresValidos) {
    _caracteresValidos = caracteresValidos;
    reservarMemoria(_caracteresValidos.size());
}

ContadorBigramas::ContadorBigramas(const ContadorBigramas & orig) {
    copiar(orig);
}

ContadorBigramas::~ContadorBigramas() {
    liberarMemoria();
}

int ContadorBigramas::getSize() const {
    return _caracteresValidos.size();
}

int ContadorBigramas::getBigramasActivos() const {
    int contador = 0;
    for ( int i = 0; i < _caracteresValidos.size(); i++ )
        for ( int j = 0; j < _caracteresValidos.size(); j++ )
            if ( _bigramas[i][j] > 0 )
                contador++;
    return contador;
}

bool ContadorBigramas::addBigrama(const char cadena[], int frecuencia) {
    int i, j;
    localizarBigrama( cadena, i, j );
    if ( i != -1 && j != -1 ) {
        _bigramas[i][j] += frecuencia;
        return true;
    } else
        return false;
}

ContadorBigramas& ContadorBigramas::operator=(const ContadorBigramas& orig) {
    copiar(orig);
    return *this;
}

ContadorBigramas& ContadorBigramas::operator+=(const ContadorBigramas& rhs) {
    for ( int i = 0; i < _caracteresValidos.size(); i++ )
        for ( int j = 0; j < _caracteresValidos.size(); j++ )
            _bigramas[i][j] += rhs._bigramas[i][j];
    return *this;
}

bool ContadorBigramas::calcularFrecuenciasBigramas(const char* nfichero) {
    /// reseteamos la matriz _bigramas haciendo que todas sus posiciones sean 0
    liberarMemoria();
    reservarMemoria(_caracteresValidos.size());
    
    bool retval = true;
    string palabra;
    char bigr[3]; bigr[3] = '\0';
    int i=-1, j=-1;
    ifstream fentrada;
    fentrada.open(nfichero);
    if (fentrada) {
        while (fentrada >> palabra)
            for ( int k = 0; k < palabra.size() - 1; k++ ) {
                bigr[0] = tolower(palabra[k]); bigr[1] = tolower(palabra[k+1]);
                addBigrama(bigr, 1);
            }
        fentrada.close();
    } else {
        retval = false;
        cerr << "Error abriendo el fichero" << nfichero << endl;
    }
    
    return retval;
}

Idioma ContadorBigramas::toIdioma() const {
    Idioma contador;
    Bigrama bigrama;
    for ( int i = 0; i < _caracteresValidos.size(); i++ )
        for ( int j = 0; j < _caracteresValidos.size(); j++ )
            if ( _bigramas[i][j] > 0 ) {
                bigrama = toBigrama(i, j);
                contador.addBigrama(bigrama);
            }
    return contador;
}

void ContadorBigramas::fromIdioma(const Idioma &i) {
    /// reseteamos la matriz _bigramas haciendo que todas sus posiciones sean 0
    liberarMemoria();
    reservarMemoria(_caracteresValidos.size());
    
    int a, b;
    for ( int k = 0; k < i.getSize(); k++ ) {
        localizarBigrama(i.getPosicion(k).getBigrama(), a, b);
        if ( a != -1 && b != -1 )
            _bigramas[a][b] = i.getPosicion(k).getFrecuencia();
    }
        
}


void ContadorBigramas::reservarMemoria(int n) {
    int** bigramas = new int*[n];
    for ( int i = 0; i < n; i++ )
       bigramas[i] = new int[n];
    _bigramas = bigramas;
    for ( int i = 0; i < n; i++ )
        for ( int j = 0; j < n; j++ )
            _bigramas[i][j] = 0;
}

void ContadorBigramas::liberarMemoria() {
    for ( int i = 0; i < _caracteresValidos.size(); i++ )
        delete[] _bigramas[i];
    delete[] _bigramas;
    _bigramas = 0;
    // _caracteresValidos = "";
}

void ContadorBigramas::copiar(const ContadorBigramas & otro) {
    _caracteresValidos = otro._caracteresValidos;
    for ( int i = 0; i < otro._caracteresValidos.size(); i++ )
        for ( int j = 0; j < otro._caracteresValidos.size(); j++ )
            _bigramas[i][j] = otro._bigramas[i][j];
}



void ContadorBigramas::localizarBigrama( const char cadena[], int &i, int &j ) const {
    i = -1; j = -1;
    for ( int a = 0; a < _caracteresValidos.size() && i == -1; a++ )
        if ( _caracteresValidos[a] == cadena[0] )
            i = a;
    for ( int b = 0; b < _caracteresValidos.size() && j == -1; b++ )
        if ( _caracteresValidos[b] == cadena[1] )
            j = b;
}

Bigrama ContadorBigramas::toBigrama( int i, int j ) const {
    Bigrama bigr;
    char* cadena = new char[3]; cadena[2] = '\0';
    cadena[0] = _caracteresValidos[i];
    cadena[1] = _caracteresValidos[j];
    bigr.setBigrama(cadena);
    bigr.setFrecuencia(_bigramas[i][j]);
    delete[] cadena;
    return bigr;
}