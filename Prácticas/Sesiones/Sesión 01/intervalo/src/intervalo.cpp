/**
	@file   intervalo.cpp
	@brief  Implementación de la clase @p Intervalo
	@author Miguel Ángel Fernández Gutiérrez - 1º DGIIM 2017/2018, MP Grupo A
**/

#include <iostream>
#include <assert.h>
#include "intervalo.h"
using namespace std;

bool Intervalo::validar(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior) {
	return ( cotaInferior < cotaSuperior ) || ( cotaInferior == cotaSuperior && cerradoInferior == cerradoSuperior);
}

Intervalo::Intervalo() {
	cerradoInf = false;
	cerradoSup = false;
	cotaInf = 0;
	cotaSup = 0;
}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior) {
	assert (validar(cotaInferior,cotaSuperior, true, true));
	cotaInf = cotaInferior;
	cotaSup = cotaSuperior;
	cerradoInf = true;
	cerradoSup = true;
}

Intervalo::Intervalo(double cotaInferior, double cotaSuperior, bool cerradoInferior, bool cerradoSuperior) {
	assert (validar(cotaInferior,cotaSuperior, cerradoInferior, cerradoSuperior));
	cotaInf = cotaInferior;
	cotaSup = cotaSuperior;
	cerradoInf = cerradoInferior;
	cerradoSup = cerradoSuperior;
}

double Intervalo::getCotaInf()const {
	return cotaInf;
}

double Intervalo::getCotaSup()const {
	return cotaSup;
}

bool Intervalo::esCerradoInf()const {
	return cerradoInf;
}

bool Intervalo::esCerradoSup()const {
	return cerradoSup;
}

bool Intervalo::esVacio()const {
	return ( cotaInf == cotaSup ) && !cerradoInf && !cerradoSup;
}

bool Intervalo::estaDentro(double n)const {
	if ( cerradoInf && cerradoSup )
		return n >= cotaInf && n <= cotaSup;
	else if ( !cerradoInf && cerradoSup )
		return n > cotaInf && n <= cotaSup;
	else if ( cerradoInf && !cerradoSup )
		return n >= cotaInf && n < cotaSup;
	else
		return n > cotaInf && n < cotaSup;
}

void escribir(const Intervalo &i) {
	if ( i.esCerradoInf() )
		cout << "[";
	else
		cout << "(";
	cout << i.getCotaInf() << "," << i.getCotaSup();
	if ( i.esCerradoSup() )
		cout << "]";
	else
		cout << ")";
}

void leer(Intervalo &i) {
	char lectura;
	double cotaInf, cotaSup;
	bool cerradoInf, cerradoSup;
	cin >> lectura;
	if ( lectura == '[' )
		cerradoInf = true;
	else if ( lectura == '(' )
		cerradoInf = false;
	else {
		cout << "Fallo al leer las cotas. Inserte [, (, ) ó ]" << endl;
		assert(false);
	}
	cin >> cotaInf >> lectura >> cotaSup >> lectura;
	if ( lectura == ']' )
		cerradoSup = true;
	else if ( lectura == ')' )
		cerradoSup = false;
	else {
		cout << "Fallo al leer las cotas. Inserte [, (, ) ó ]" << endl;
		assert(false);
	}
	Intervalo i2(cotaInf, cotaSup, cerradoInf, cerradoSup);
	i = i2;
}
