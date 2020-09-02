# Examen julio 2011 (GI)

> Alumno: Miguel Ángel Fernández Gutiérrez

## Clase VectorDinamico

### **Ejercicio 1.** VectorDinamico: redimensionar
###### Código ya implementado

~~~
class VectorDinamico {
    int NumMaxElems;        // número de casillas reservadas en v
    int NumOcupados;        // número de casillas ocupadas
    int * v;                // acceso a los datos
    ...
};
~~~

###### Código a implementar

~~~
bool VectorDinamico::redimensionar(int nuevotam) {
    bool mantiene;
    v_aux = new int[nuevotam];
    NumMaxElems = nuevotam;
    for ( int i = 0; i < nuevotam && i < NumOcupados; i++ )
        v_aux[i] = v[i];
    if ( NumOcupados <= nuevotam ) {
        mantiene = true;
    } else {
        NumOcupados = nuevotam;
        mantiene = false;
    }
    return mantiene;
}
~~~

## Clase Lista

~~~
struct dato {
    float elem;
    int siguiente;
};

class Lista {
    dato* elementos;
    int primero;
    int nelems;
    ...
}
~~~

### **Ejercicio 2a.** Constructor de copia

~~~
Lista::Lista(const Lista &otro) {
    copiar(otro);
}

void Lista::reservarMemoria(int n) {
    elementos = new dato[n];
    primero = 0;
    nelems = n;
}

void Lista::copiar(const Lista &otro) {
    reservarMemoria(otro.nelems);
    nelems = otro.nelems;
    for ( int i = 0; i < nelems; i++ ) {
        elementos[i].elem = otros.elementos[i].elem;
        elementos[i].siguiente = otros.elementos[i].siguiente;
    }
    primero = otro.primero;
}

void liberarMemoria() {
    delete[] elementos;
    elementos = 0;
    primero = 0;
    nelems = 0;
}
~~~

### **Ejercicio 2b.** Sobrecarga de `operator=`

~~~
Lista& Lista::operator=(const Lista &otro) {
    liberarMemoria();
    copiar(otro);
    return (*this);
}
~~~

### **Ejercicio 2c.** Sobrecarga de `operator==`

~~~
...
~~~

...


_Todo esto es demasiado igual..._

## Programa `grep`

### **Ejercicio 3.**

~~~
bool find_in_cstring(const char* cadena, const char* buscar) {
    bool found = false;
    int loc = 0;
    for ( int i = 0; i < strlen(cadena) && !found; i++ ) {
        if ( cadena[i] == buscar[i] ) {
            loc++;
            if ( loc == strlen(buscar) )
                found = true;
        } else
            loc = 0;
    }
    return found;
}
int main(int argc, char* argv[]) {
    ifstream fentrada;
    char cad[500];
    for ( int i = 2; i < argc; i++ ) {
        fentrada.open(argc[i]);
        if ( !fentrada ) {
            cerr << "Error abriendo fichero " << argc[i] << endl;
            return 1;
        }
        int line = 1;
        while ( getline(fentrada, cad) ) {
            if (find_in_cstring(cad, argv[1]))
                cout << argc[i] << " (línea " << line << "): " << cad << endl;
            line++;
        }
        fentrada.close();
    }
}
~~~