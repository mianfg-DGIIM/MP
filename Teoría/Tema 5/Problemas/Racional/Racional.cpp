/**
 * @file Racional.cpp
 * @author Miguel Ángel Fernández Gutiérrez <mianfg>
 */

#include "Racional.h"
#include <iostream>

Racional::Racional() {
    _num = 0;
    _denom = 1;
}

Racional::Racional(int entero) {
    _num = entero;
    _denom = 1;
}

Racional::Racional(int num, int denom) {
    _num = num;
    _denom = denom;
}

int Racional::getNumerador() const {
    return _num;
}

int Racional::getDenominador() const {
    return _denom;
}

Racional Racional::operator+(const Racional &racional) const {
    Racional suma;
    suma._num = _num*racional._denom + racional._num*_denom;
    suma._denom = _denom*racional._denom;
    suma.irreducible();
    return suma;
}

Racional Racional::operator+(int entero) const {
    Racional suma(entero);
    suma += *this;
    return suma;
}

Racional operator+(int entero, const Racional &racional) {
    Racional suma(entero);
    suma += racional;
    return suma;
}

Racional Racional::operator-(const Racional &racional) const {
    return (*this)+(-1)*racional;
}

Racional Racional::operator-(int entero) const {
    return (*this)+(-1)*entero;
}

Racional operator-(int entero, const Racional &racional) {
    return entero+(-1)*racional;
}

Racional Racional::operator*(const Racional &racional) const {
    Racional producto;
    producto._num = _num*racional._num;
    producto._denom = _denom*racional._denom;
    producto.irreducible();
    return producto;
}

Racional Racional::operator*(int entero) const {
    Racional producto(entero);
    return (*this)*producto;
}

Racional operator*(int entero, const Racional &racional) {
    Racional producto(entero);
    producto *= racional;
    return producto;
}

Racional Racional::operator/(const Racional &racional) const {
    Racional divisor;
    divisor._num = racional._denom;
    divisor._denom = racional._num;
    return (*this)*divisor;
}

Racional Racional::operator/(int entero) const {
    Racional divisor(entero);
    return (*this)/divisor;
}

Racional operator/(int entero, const Racional &racional) {
    Racional dividendo(entero);
    return dividendo/racional;
}

Racional& Racional::operator+=(const Racional &racional) {
    *this = *this + racional;
    return *this;
}

Racional& Racional::operator+=(int entero) {
    Racional num(entero);
    (*this)+=num;
    return *this;
}

Racional& Racional::operator-=(const Racional &racional) {
    *this = *this - racional;
    return *this;
}

Racional& Racional::operator-=(int entero) {
    Racional num(entero);
    (*this)-=num;
    return *this;
}

Racional& Racional::operator*=(const Racional &racional) {
    _num = _num*racional._num;
    _denom = _denom*racional._denom;
    irreducible();
    return *this;
}

Racional& Racional::operator*=(int entero) {
    Racional num(entero);
    (*this)*=num;
    return *this;
}

Racional& Racional::operator/=(const Racional &racional) {
    _num = _num*racional._denom;
    _denom = _denom*racional._num;
    irreducible();
    return *this;
}

Racional& Racional::operator=(const Racional &racional) {
    _num = racional._num;
    _denom = racional._denom;
    return *this;
}

Racional& Racional::operator=(int num) {
    _num = num;
    _denom = 1;
    return *this;
}

ostream& operator<<(ostream &flujo, const Racional &racional) {
    flujo << racional._num << "/" << racional._denom;
    return flujo;
}

istream& operator>>(istream &flujo, Racional &racional) {
    char divisor; int num_temp, denom_temp;
    flujo >> num_temp >> divisor >> denom_temp;
    if ( divisor == '/' ) {
        racional._num = num_temp;
        racional._denom = denom_temp;
    } else
        cerr << "ERROR (Racional): debe insertar un racional de la forma num/denom" << endl;
    return flujo;
}

void Racional::irreducible() {
    for ( int i = _denom; i > 1; i-- ) {
        if ( _num % i == 0 && _denom % i == 0 ) {
            _num /= i;
            _denom /= i;
        }
    }
}