/**
   @file paquete.cpp
   @author Miguel Ángel Fernández Gutiérrez <mianfg@correo.ugr.es>
**/

#include <iostream>
#include "paquete.h"

using namespace std;

Paquete::Paquete(int id, double peso, int largo, int ancho, int alto) {
    _id = id;
    _peso = peso;
    _largo = largo;
    _ancho = ancho;
    _alto = alto;
}

void Paquete::setId(int id) {
    _id = id;
}

int Paquete::getId() const {
    return _id;
}

void Paquete::setPeso(int peso) {
    _peso = peso;
}

double Paquete::getPeso() const {
    return _peso;
}

void Paquete::setLargo(int largo) {
    _largo = largo;
}

int Paquete::getLargo() const {
    return _largo;
}

void Paquete::setAncho(int ancho) {
    _ancho = ancho;
}
int Paquete::getAncho() const {
    return _ancho;
}

void Paquete::setAlto(int alto) {
    _alto = alto;
}

int Paquete::getAlto()const {
    return _alto;
}

void Paquete::setPaquete(int id, int peso, int largo, int ancho, int alto) {
    _id = id;
    _peso = peso;
    _largo = largo;
    _ancho = ancho;
    _alto = alto;
}
double Paquete::getVolumen() const {
    return 1.0*_largo*_ancho*_alto;
}

double Paquete::calculaPesoVolumetrico() const {
    double peso = getVolumen()/_FACTORVOLUMETRICO;
    if ( peso > _peso )
        return peso;
    else
        return _peso;
}

double Paquete::getFactura() const {
    if ( calculaPesoVolumetrico() < _RANGO1 )
        return _TARIFA1+_TARIFA1*_IVA;
    else if ( calculaPesoVolumetrico() < _RANGO2 )
        return _TARIFA2+_TARIFA2*_IVA;
    else // if ( calculaPesoVolumetrico() < _RANGO3 )
        return _TARIFA3+_TARIFA3*_IVA;
}