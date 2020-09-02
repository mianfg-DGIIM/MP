#include <iostream>
using namespace std;

#include <Racional.h>

int main() {
    Racional r1, r2;
    int x;
    /*cout << "Insertar racional r1: ";
    cin >> r1;
    cout << "Insertar racional r2: ";
    cin >> r2;*/
    cout << "Insertar racionales r1, luego r2: ";
    cin >> r1 >> r2;
    cout << "Insertar entero x: ";
    cin >> x;
    cout << "Números insertados:" << endl;
    cout << "r1=" << r1 << "; r2=" << r2 << "; x=" << x << endl;
    cout << "r1+r2=" << r1+r2 << endl;
    cout << "r1+x=" << r1+x << endl;
    cout << "x+r1=" << x+r1 << endl;
    cout << "r1-r2=" << r1-r2 << endl;
    cout << "r1-x=" << r1-x << endl;
    cout << "x-r1=" << x-r1 << endl;
    cout << "r1*r2=" << r1*r2 << endl;
    cout << "r1*x=" << r1*x << endl;
    cout << "x*r1=" << x*r1 << endl;
    cout << "r1/r2=" << r1/r2 << endl;
    cout << "r1/x=" << r1/x << endl;
    cout << "x/r1=" << x/r1 << endl;
    // todavía no los he implementado, pero es muy sencillo de hacerlo
    /*cout << "r1==r2=" << r1==r2 << endl;
    cout << "r1!=r2=" << r1!=r2 << endl;
    cout << "r1<r2=" << r1<r2 << endl;
    cout << "r1>r2=" << r1>r2 << endl;*/
}