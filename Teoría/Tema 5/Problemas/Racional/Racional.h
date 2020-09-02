/**
 * @file Racional.h
 * @author Miguel Ángel Fernández Gutiérrez <mianfg>
 */

#ifndef RACIONAL_H
#define RACIONAL_H

#include <iostream>
using namespace std;

/**
 * @class Racional
 * @brief Clase para trabajar con números racionales
 */
class Racional {
public:
    Racional();
    Racional(int entero);
    Racional(int num, int denom);
    int getNumerador() const;
    int getDenominador() const;

    /// sobrecarga: racional + racional
    Racional operator+(const Racional &racional) const;
    /// sobrecarga: racional + entero
    Racional operator+(int entero) const;
    /// sobrecarga: entero + racional
    friend Racional operator+(int entero, const Racional& racional);

    /// sobrecarga: racional - racional
    Racional operator-(const Racional &racional) const;
    /// sobrecarga: racional - entero
    Racional operator-(int entero) const;
    /// sobrecarga: entero - racional
    friend Racional operator-(int entero, const Racional& racional);

    /// sobrecarga: racional * racional
    Racional operator*(const Racional &racional) const;
    /// sobrecarga: racional * entero
    Racional operator*(int entero) const;
    /// sobrecarga: entero * racional
    friend Racional operator*(int entero, const Racional& racional);

    /// sobrecarga: racional / racional
    Racional operator/(const Racional &racional) const;
    /// sobrecarga: racional / entero
    Racional operator/(int entero) const;
    /// sobrecarga: entero / racional
    friend Racional operator/(int entero, const Racional& racional);

    /// sobrecarga: racional += racional
    Racional& operator+=(const Racional &racional);
    /// sobrecarga: racional += entero
    Racional& operator+=(int entero);

    /// sobrecarga: racional -= racional
    Racional& operator-=(const Racional &racional);
    /// sobrecarga: racional -= entero
    Racional& operator-=(int entero);

    /// sobrecarga: racional *= racional
    Racional& operator*=(const Racional &racional);
    /// sobrecarga: racional *= entero
    Racional& operator*=(int entero);

    /// sobrecarga: racional /= racional
    Racional& operator/=(const Racional &racional);
    /// sobrecarga: racional /= entero
    Racional& operator/=(int entero);

    /// sobrecarga: racional == racional
    bool operator==(const Racional & racional);
    /// sobrecarga: racional == entero
    bool operator==(int entero);
    /// sobrecarga: entero == racional
    friend bool operator==(int entero, const Racional &racional);

    /// sobrecarga: racional != racional
    bool operator!=(const Racional &racional);
    /// sobrecarga: racional != entero
    bool operator!=(int entero);
    /// sobrecarga: entero != racional
    friend bool operator!=(int entero, const Racional &racional);

    /// sobrecarga: racional = racional
    Racional& operator=(const Racional & racional);
    /// sobrecarga: racional = entero
    Racional& operator=(int entero);

    friend ostream& operator<<(ostream &flujo, const Racional &racional);
    friend istream& operator>>(istream &flujo, Racional &racional);
private:
    int _num;
    unsigned int _denom;
    void irreducible();
};

#endif