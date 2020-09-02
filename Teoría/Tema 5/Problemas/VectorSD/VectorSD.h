/**
 * @file VectorSD.h
 * @author Miguel Ángel Fernández Gutiérrez <mianfg>
 */

#ifndef VECTORSD_H
#define VECTORSD_H

#include <iostream>
using namespace std;

class VectorSD {
    int *array;
    int util;
    int capacidad;
public:
    VectorSD();
    ~VectorSD();
    VectorSD(int n);
    VectorSD(const VectorSD &vector);

    VectorSD& operator=(const VectorSD &vector);
    int& operator[](int i);
    bool operator==(const VectorSD &vector) const;
    bool operator!=(const VectorSD &vector) const;
    bool operator<(const VectorSD &vector) const;
    bool operator<=(const VectorSD &vector) const;
    bool operator>(const VectorSD &vector) const;
    bool operator>=(const VectorSD &vector) const;

    VectorSD operator+(const VectorSD &vector) const;
    VectorSD operator-(const VectorSD &vector) const;
    VectorSD& operator+=(const VectorSD &vector);
    VectorSD& operator-=(const VectorSD &vector);

    friend ostream& operator<<(ostream &flujo, const VectorSD &vector);
    friend istream& operator>>(istream &flujo, VectorSD &vector);

    int getDato(int pos) const;
    void setDato(int pos, int num);
    void insertarDato(int pos, int num);
    void eliminarDato(int pos);
    void aniadir(int num);
    friend void ordenar(VectorSD& vector);
private:
    void copiar(const VectorSD &vector);
};

#endif