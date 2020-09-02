# Examen junio 2015 (GI)

> Alumno: Miguel Ángel Fernández Gutiérrez

### **Ejercicio 1.** Celdas enlazadas

#### Implementación de @mianfg

~~~
struct Celda {
    double valor;
    Celda* siguiente;
}

void mostrarLista( Celda* lista ) {
    Celda* aux = lista;
    while ( aux != 0 ) {
        cout << aux->valor;
        aux = aux->siguiente;
    }
}
~~~

## Especificación Frecuencias (`.h`)

~~~
struct Pareja {
    int dato;
    int nveces;
};

class Frecuencias {
    Pareja *parejas;    // "npares" datos de tipo "Pareja" ordenados por "dato". 0 si no hay parejas
    int npares;
    ...
}
~~~

## Implementación Frecuencias (`.cpp`)

### **Ejercicio 2.** Frecuencias de enteros: clase

#### Implementación de @mianfg

~~~
Frecuencias::Frecuencias() {
    reservarMemoria(0);
}

Frecuencias::~Frecuencias() {
    liberarMemoria();
}

Frecuencias::Frecuencias(const Frecuencias &frecs) {
    copiar(frecs);
}

Frecuencias& Frecuencias::operator=(const Frecuencias &frecs) {
    liberarMemoria();
    copiar(frecs);
    return (*this);
}

void Frecuencias::reservarMemoria(int n) {
    if ( n>0 ) {
        npares = n;
        parejas = new Parejas[npares];
        for ( int i = 0; i < npares; i++ ) {
            parejas[i].dato = 0;
            parejas[i].nveces = 0;
        }
    } else {
        npares = 0;
        parejas = 0;
    }
}

void Frecuencias::liberarMemoria() {
    if ( n>0 ) {
        delete[] parejas;
        parejas = 0;
        npares = 0;
    }
}

void Frecuencias::copiar(const Frecuencias &frecs) {
    reservarMemoria(frecs.npares);
    // npares = frecs.npares;
    for ( int i = 0; i < npares; i++ ) {
        parejas[i].dato = frecs.parejas[i].dato;
        parejas[i].nveces = frecs.parejas[i].nveces;
    }
}
~~~

### **Ejercicio 3.** Frecuencias de enteros: miembro público

#### Implementación de @mianfg

~~~
void Frecuencias::Add(int entero) {
    bool found = false;
    for ( int i = 0; i < npares && !found; i++ )
        if ( parejas[i].dato == entero ) {
            parejas[i].nveces++;
            found = true;
        }
    if (!found) {
        Frecuencias aux;
        aux.reservarMemoria(npares+1);
        // aux.npares = npares + 1;
        int loc_aniadir = -1;
        for ( int i = 0; i < npares && loc_aniadir != -1; i++ ) {
            if ( parejas[i].dato < entero ) {
                aux.parejas[i].dato = parejas[i].dato;
                aux.parejas[i].nveces = parejas[i].nveces;
            } else {
                loc_aniadir = i;
                aux.parejas[i].dato = entero;
                aux.parejas[i].nveces = 1;
            }
        }

        for ( int i = loc_aniadir+1; i < npares; i++ ) {
            aux.parejas[i].dato = parejas[i-1].dato;
            aux.parejas[i].nveces = parejas[i-1].nveces;
        }

        *this = aux;
        aux.liberarMemoria();
    }
}
~~~

### **Ejercicio 4.** Frecuencias de enteros: sobrecarga de operadores

#### Implementación de @mianfg

~~~
Frecuencias& operator+=(int num) {
    Add(num);
    return *this;
}

ostream& operator<<(ostream& flujo, const Frecuencias &frec) const {
    flujo << num << endl;
    for ( int i = 0; i < n; i++ ) {
        flujo << parejas[i].dato << " " << parejas[i].nveces << endl;
    }
}
~~~

### **Ejercicio 5.** Frecuencias de enteros: uso de la clase

#### Implementación de @mianfg

###### contar.cpp
~~~
// ES EQUIVALENTE
/*void leeEnteros(Frecuencias &frecu,istream& flujo){
  int entero;
  while(flujo){
    flujo>>entero;
    if(flujo)
      frecu+=entero;
  }
}*/

void leerEnteros(Frecuencias &frec, istream& flujo) {
    int entero;
    while ( flujo >> entero ) {
        frec += entero;
    }
}
int main(argc, char* argv[]) {
    Frecuencias frecs;

    if ( argc > 1 ) {
        ifstream fentrada;
        fentrada.open(argv[1]);
        if (!fentrada) return 1;
        else leerEnteros(frecs, fentrada);
    } else {
        leerEnteros(frecs, cin);
    }

    cout << frecs;
}
~~~
