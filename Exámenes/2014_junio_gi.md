# Examen junio 2014 (GI)

> Alumno: Miguel Ángel Fernández Gutiérrez

### Ejercicio 1

~~~
struct Celda {
    int dato;
    Celda* sig;
}

void crearListaEnlazada(Celda* lista, int primer_dato) {
    Celda* lista = new Celda;
    lista->dato = primer_dato;
    lista->sig = 0;
}

void aniadirDatoListaEnlazada(Celda* lista, int num) {
    Celda* aux = new Celda;
    aux->dato = num;
    aux->siguiente = lista;
    lista = aux;
}

void mostrarLista(Celda *lista) {
    Celda* aux = new Celda;
    while ( aux != 0 ) {
        cout << aux->dato;
        aux = aux->sig;
    }
    delete aux;
}

void eliminarLista(Celda *lista) {
    
}
~~~

## Especificación Barquitos (`.h`)

~~~
class Barquitos {
    int** _tablero;
    int _nfilas;
    int _ncolumnas;
};
~~~

## Implementación Barquitos (`.cpp`)

### **Ejercicio 2a.** Constructor y destructor

~~~
Barquitos::Barquitos() {
    reservarMemoria(0);
}

Barquitos::~Barquitos() {
    liberarMemoria();
}

void Barquitos::reservarMemoria(int nfilas, ncolumnas) {
    if ( nfilas > 0 && ncolumnas > 0 ) {
        _nfilas = nfilas;
        _ncolumnas = ncolumnas;
        _tablero = new int*[_nfilas];
        for ( int i = 0; i < _nfilas; i++ )
            _tablero[i] = new int[_ncolumnas];
        for ( int i = 0; i < _nfilas; i++ )
            for ( int j = 0; j < _ncolumnas; j++ )
                _tablero[i][j] = 9;
    } else {
        _nfilas = 0;
        _ncolumnas = 0;
        _tablero = 0;
    }
}

void Barquitos::liberarMemoria() {
    if ( _nfilas > 0 && _ncolumnas > 0 ) {
        for ( int i = 0; i < _nfilas; i++ )
            delete[] _tablero[i];
        delete[] _tablero;
        _tablero = 0;
        _dim = 0;
    }
}
~~~

### **Ejercicio 2b.** Constructor de copia y sobrecarga de `operator=`

~~~
Barquitos::Barquitos(const Barquitos &otro) {
    copiar(otro);
}

Barquitos& Barquitos::operator=(const Barquitos &otro) {
    liberarMemoria();
    copiar(otro);
}

void copiar(const Barquitos &otro) {
    _nfilas = otro._nfilas;
    _ncolumnas = otro._ncolumnas;
    reservarMemoria(_nfilas, _ncolumnas);
    for ( int i = 0; i < _nfilas; i++ )
        for ( int j = 0; j < _ncolumnas; j++ )
            _tablero[i][j] = otro._tablero[i][j];
}
~~~

### **Ejercicio 2c.** Comprobar si es posible colocar un barco

~~~
// función auxiliar para comprobar si puede colocarse un barco en [fila, columna]
bool Barquitos::comprobarPosicionamiento(int fila, int columna) const {
    posicionable = true;

    // comprobar que se coloca en un lugar de la matriz
    if ( !( fila >= 0 && fila < _nfilas && columna >= 0 && columna < _ncolumnas ) )
        posicionable = false;
    
    // para acceder a lugares en la matriz y no producir core
    if ( posicionable ) {
        // comprobar que se coloca en un lugar con agua
        if ( _tablero[fila][columna] != 9 )
            posicionable = false;

        for ( int i = fila-1; i <= fila+1 && posicionable; i++ )
            for ( int j = columna-1; j <= columna+1 && posicionable; j++ )
                // comprobar que se puede acceder a esa dirección
                if ( i >= 0 && i < _nfilas && j >= 0 && j < _ncolumnas )
                    if ( _tablero[i][j] != 9 )
                        posicionable = false;
    }

    return posicionable;
}

bool Barquitos::Colocar(char fila, int columna, int tam, char direccion) const {
    bool es_posible = true;
    int fila_num = fila - 'A';
    int columna_num = columna;  // para consistencia de ambas variables
    
    if ( tam >= 9 )
        es_posible = false;

    if ( direccion == 'V' && es_posible )
        for ( int i = fila_num; i <= fila_num + tam && es_posible; i++ )
            es_posible = comprobarPosicionamiento(columna_num, i);
    else if ( direccion == 'H' && es_posible )
        for ( int i = columna_num; i <= columna_num + tam && es_posible; i++ )
            es_posible = comprobarPosicionamiento(i, fila_num);
    else
        es_posible = false;

    return es_posible;
}
~~~

### **Ejercicio 2d.** Insertar barco en el tablero

**Nota:** doy por hecho que puedo posicionarlo, así que intento posicionarlo varias veces hasta que lo consigo (por la suposición anterior), usando un `while`.
~~~
// auxiliar para generar un tipo de barco aleatorio de tamaño fijo
void Barquitos::generarAleatorioTamanio(char &fila, int &columna, int tam, char &direccion) const {
    fila = Aleatorio('A', 'A'+_nfilas);
    columna = Aleatorio(0, _ncolumnas);
    direccion = 'H';
    int dir_seed = Aleatorio(0,1);
    if ( dir_seed == 0 )
        direccion = 'V';
}

void Barquitos::insertar(int tam) {
    // buscar un barco aleatorio que pueda insertarse
    char fila; int columna; char direccion;
    generarAleatorioTamanio(fila, columna, tam, direccion);
    while ( !Colocar(fila, columna, tam, direccion) )
        generarAleatorioTamanio(fila, columna, tam, direccion);
    
    int fila_num = fila - 'A';
    int columna_num = columna;

    // ahora ya puedo insertarlo
    if ( direccion = 'V' )
        for ( int i = fila_num; i <= fila_num+tam; i++ )
            _tablero[i][columna_num] = tam;
    else
        for ( int i = columna_num; i <= columna_num+tam; i++ )
            _tablero[fila_num][i] = tam;
}
~~~

### **Ejercicio 3a.** E/S (I): Leer

~~~
bool Barquitos::Leer(const char* fichero) {
    ifstream fentrada;
    fentrada.open(fichero);
    if (!fentrada)
        return false;
    // leer palabra mágica
    char magic[100];
    fin.getline(magic, 100);
    if (strcmp(cadena, "MP-BARQ-V1.0")==0) {
        liberarMemoria();
        fentrada >> _nfilas;
        fentrada >> _ncolumnas;
        while( fentrada >> )
            ... // en binario ¿?
    } else
        return false;
    fentrada.close();
    return true;
}
~~~

### **Ejercicio 3a.** E/S (I): Escribir

~~~
// me da pereza hacerlo jeje, es igual que el de arriba pero al fichero
~~~