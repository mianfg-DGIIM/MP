# Examen junio 2013 (GI)

> Alumno: Miguel Ángel Fernández Gutiérrez

## Especificación BigInt (`.h`)

~~~
class BigInt {
    int* _numero;
    int _n;

    void reservarMemoria(int n);
    void liberarMemoria();
    void copiar(const BigInt &otro);
public:
    BigInt();
    ~BigInt();
    BigInt(const char* cadena);
    BigInt(unsigned int num);
    BigInt(const BigInt &otro);
    BigInt operator+(const BigInt &otro) const;
    friend ostream& operator<<(ostream& flujo, const BigInt &big_int);
    friend istream& operator>>(istream& flujo, BigInt &big_int);
}
~~~

## Implementación BigInt (`.cpp`)

### **Ejercicio 1.** Constructor sin parámetros y destructor

~~~
BigInt::BigInt() {
    reservarMemoria(0);
}

BigInt::~BigInt() {
    liberarMemoria();
}

void BigInt::reservarMemoria(int n) {
    if (n>0) {
        _n = n;
        _numero = new int*[_n];
    } else {
        _n = 1;
        _numero = new int*[1];
        _numero[1] = 0;
    }
}

void BigInt::liberarMemoria() {
    delete[] _numero;
    _numero = 0;
    _n = 0;
}
~~~

### **Ejercicio 2a.** Constructor a partir de cadena de caracteres

~~~
BigInt::BigInt(const char* cadena) {
    reservarMemoria(strlen(cadena));
    for ( int i = 0; i < _n; i++ )
        _numero[i] = cadena[_n-i-1];
}
~~~

### **Ejercicio 2b.** Constructor a partir de `unsigned int`

~~~
BigInt::BigInt(unsigned int num) {
    _n = 1;
    int aux = num;
    while ( aux > 9 ) {
        aux /= 10;
        _n++;
    }
    reservarMemoria(_n);
    // CUIDADO que están almacenados al revés
    for ( int i = 0; i < _n; i++ ) {
        _numero[i] = num % 10;
        num /= 10;
    }
}
~~~

### **Ejercicio 3.** Constructor de copia y operador de asignación

~~~
BigInt::BigInt(const BigInt &otro) {
    copiar(otro);
}

BigInt& BigInt::operator=(const BigInt &otro) {
    liberarMemoria();
    copiar(otro);
    return (*this);
}

void BigInt::copiar(const BigInt &otro) {
    _n = otro._n;
    reservarMemoria(_n);
    for ( int i = 0; i < _n; i++ )
        _numero[i] = otro._numero[i];
}
~~~

### **Ejercicio 4.** Sobrecarga de `operator+`

~~~
BigInt BigInt::operator+(const BigInt &otro) const {
    const BigInt *mayor, *menor;
    if ( _n > otro._n )
        *mayor = &*this;
        *menor = &otro;
    else
        *mayor = &otro;
        *menor = &*this;

    BigInt resultado(*mayor);

    int acarreo = 0;

    int i;

    // sumar lo primero (menor a resultado)
    for ( int i = 0; i < menor->_n; i++ ) {
        resultado._numero[i] += menor->_numero[i] + acarreo;
        if ( resultado._numero[i] > 9 ) {
            resultado._numero[i] -= 10;
            acarreo = 1;
        } else
            acarreo = 0;
    }

    // si sigue habiendo acarreo
    while ( acarreo && i < resultado._n ) {
        resultado._numero[i] += acarreo;
        if ( resultado._numero[i] > 9 ) {
            resultado._numero[i] -= 10;
            acarreo = 1;
        } else
            acarreo = 0;
        i++;
    }

    // si el último dígito es mayor que nueve, añadimos un nuevo dígito
    if ( resultado._numero[resultado._n-1] > 9 ) {
        int* nuevo_numero = new int[_n+1];
        for ( int i = 0; i < _n; i++ )
            nuevo_numero[i] = resultado._numero[i];
        nuevo_numero[_n] = resultado._numero[_n-1] / 10; // realmente es 1
        nuevo_numero[_n-1] -= 10;
        delete[] resultado._numero;
        resultado._numero = nuevo_numero;
        resultado._n++;
    }
}
~~~

### **Ejercicio 5.** Sobrecarga de `operator<<`

~~~
ostream& operator<<(ostream& flujo, const BigInt &big_int) {
    for ( int i = _n-1; i >= 0; i++ )
        flujo << big_int._numero[i];
    return flujo;
}
~~~

### **Ejercicio 6.** Sobrecarga de `operator>>`

~~~
istream& operator>>(istream& flujo, BigInt &big_int) {
    string cadena;
    flujo >> cadena;
    BigInt big_int_aux(cadena.c_str());
    big_int = big_int_aux;
    return flujo;
}
~~~

### **Ejercicio 7.** Escribir `.h`

Ver inicio del documento.

### **Ejercicio 8.** Sumar todos los valores de un fichero: `suma.cpp`

Suponemos que siempre se llama al programa como `$ <suma> fichero.txt`.

~~~
int main(argc, char* argv[]) {
    BigInt resultado; BigInt almacenar;
    ifstream flujo;
    flujo.open(argv[1]);
    if (!flujo)
        return 1;
    while ( flujo >> almacenar )
        resultado = resultado + almacenar;
    cout << resultado;
    return 0;
}
~~~