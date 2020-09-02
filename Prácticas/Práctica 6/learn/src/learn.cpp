/** 
 * @file learn.cpp
 * @author Miguel Ángel Fernández Gutiérrez <mianfg@correo.ugr.es>
*/

#include <iostream>
#include <cstring>
#include <string>

#include "ContadorBigramas.h"

using namespace std;

/**
 * @brief Imprime mensaje de ayuda
 */
void pinta_mensaje() {
    cout << "Formato:" << endl;
    cout << "learn {-c|-a} [-t|-b] [-l nombreIdioma] [-f ficheroSalida] texto1.txt texto2.txt texto3.txt .... " << endl;
    cout << "           aprende el codigo para el lenguaje nombreIdioma a partir de los ficheros texto1.txt texto2.txt texto3.txt ..." << endl;
    cout << endl;
    cout << "Parámetros:" << endl;
    cout << "-c|-a: operación crear fichero de idioma (-c) o añadir a fichero de idioma (-a)" << endl;
    cout << "-l nombreIdioma: idioma (unknown por defecto)" << endl;
    cout << "-f ficheroSalida:  nombre del fichero de salida (salida.bgx por defecto)" << endl;
    cout << "texto1.txt texto2.txt texto3.txt ....: nombres de los ficheros de entrada (debe haber al menos 1)" << endl;
}

int main(int argc, char *argv[]) {
    /// Cadena de caracteres válidos de ISO8859-1 para múltiples idiomas
    string valid="abcdefghijklmnopqrstuvwxyz\xE0\xE1\xE2\xE3\xE4\xE5\xE6\xE7\xE8\xE9\xEA\xEB\xEC\xED\xEE\xEF\xF0\xF1\xF2\xF3\xF4\xF5\xF6\xF8\xF9\xFA\xFB\xFC\xFD\xFE\xFF"; 
    
    string nombre_idioma = "unknown";
    string fichero_salida = "out.bgr";
    int start_ficheros = 2;
    
    /// análisis y comprobación de formato
    bool status = false;
    if ( argc > 1 )
        if ( strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-a") == 0 )
            status = true;
    if ( argc > 5 && status ) {
        if ( strcmp(argv[2], "-l") == 0 && strcmp(argv[4], "-f") == 0 ) {
            nombre_idioma = argv[3];
            fichero_salida = argv[5];
            start_ficheros = 6;
        } else if ( strcmp(argv[2], "-f") == 0 && strcmp(argv[4], "-l") == 0 ) {
            fichero_salida = argv[3];
            nombre_idioma = argv[5];
            start_ficheros = 6;
        }
    } else if ( argc > 3 && status ) {
        if ( strcmp(argv[2], "-l") == 0 ) {
            nombre_idioma = argv[3];
            start_ficheros = 4;
        } else if ( strcmp(argv[2], "-f") == 0 ) {
            fichero_salida = argv[3];
            start_ficheros = 4;
        }
    }
    
    cout << endl;
    
    if (argc <= start_ficheros) status = false;
    
    if ( !status ) {
        cerr << "Formato de request inválido" << endl;
        cout << endl;
        pinta_mensaje();
        return 1;
    }
    
    ContadorBigramas frecuencias(valid);
    ContadorBigramas frecuencias_aux(valid);
    
    if ( strcmp(argv[1], "-a") == 0 ) {
        Idioma init;
        status = init.cargarDeFichero(fichero_salida.c_str());
        frecuencias.fromIdioma(init);
        if (status) cout << "Fichero " << fichero_salida << " cargado correctamente" << endl << endl;
    }
    
    if ( !status ) {
        cerr << "Error abriendo fichero " << fichero_salida << endl;
        return 1;
    }
    
    for ( int i = start_ficheros; i < argc && status; i++ ) {
        status = frecuencias_aux.calcularFrecuenciasBigramas(argv[i]);
        frecuencias += frecuencias_aux;
        if (status) cout << "Fichero " << argv[i] << " añadido correctamente" << endl;
    }
    
    if ( !status )
        return 1;
    
    
    
    Idioma convertido = frecuencias.toIdioma();
    convertido.setIdioma(nombre_idioma);
    convertido.ordenar();
    status = convertido.salvarAFichero(fichero_salida.c_str());
    
    if ( !status )
        return 1;
    else
        cout << endl << "Proceso realizado satisfactoriamente :)\nCompruebe su fichero " << fichero_salida << endl;
    
    return 0;
}
