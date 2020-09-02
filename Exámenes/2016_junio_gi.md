# Examen junio 2016 (GI)

> Alumno: Miguel Ángel Fernández Gutiérrez

### **Ejercicio 1.** Vectores-C

#### Resolución de @mianfg

~~~
bool comprobarOcurrencia( const double* vector, int util, double find ) {
    bool found = false;
    for ( int i = 0; i < util && !found, i++ )
        if ( vector[i] == find )
            found = true;
    return found;
}

int MezclarUnico(const double* vector1, int util1, const double* vector2, int util2, double* vector_salida) {
    int index1 = 0, index2 = 0;
    int util_salida = 0;
    while (index1 < util1 && index2 < util2) {
        if ( vector1[index1] < vector2[index2] ) {
            if ( !comprobarOcurrencia(vector_salida, util_salida, vector1[index1]) ) {
                vector_salida[util_salida] = vector1[index1];
                util_salida++;
            }
            index1++;
        } else {
            if ( !comprobarOcurrencia(vector_salida, util_salida, vector2[index2]) ) {
                vector_salida[util_salida] = vector2[index2];
                util_salida++;
            }
            index2++;
        }
    }
    while (index1 < util1) {
        if ( !comprobarOcurrencia(vector_salida, util_salida, vector1[index1]) ) {
            vector_salida[util_salida] = vector1[index1];
            util_salida++;
        }
        index1++;
    }
    while (index2 < util2) {
        if ( !comprobarOcurrencia(vector_salida, util_salida, vector2[index2]) ) {
            vector_salida[util_salida] = vector2[index2];
            util_salida++;
        }
        index2++;
    }
    return util_salida;
}
~~~

## Especificación SkyLine (`.h`)

~~~
class SkyLine {
    double *abscisas;       // abscisas[i] > abscisas[i-1]
    double *alturas;        // alturas[i] >= 0 && alturas[n-1] == 0
    int n;                  // tamaño de los vectores anteriores
public:
}
~~~

## Implementación SkyLine (`.cpp`)
### **Ejercicio 2.** SkyLine: clase

#### Implementación de @mianfg

~~~
SkyLine::SkyLine() {
    reservarMemoria(0);
}

SkyLine::~SkyLine() {
    liberarMemoria();
}

SkyLine::SkyLine(double abscisa1, double abscisa2, double altura) {
    reservarMemoria(2);
    if ( abscisa1 < abscisa2 ) {
        abscisas[0] = abscisa1;
        abscisas[1] = abscisa2;
    } else {
        abscisas[0] = abscisa2;
        abscisas[1] = abscisa1;
    }
    alturas[0] = altura;
}

SkyLine::SkyLine(const SkyLine &sky) {
    copiar(sky);
}

SkyLine& SkyLine operator=(const SkyLine &sky) {
    liberarMemoria();
    copiar(sky);
    return (*this);
}
SkyLine::reservarMemoria(int m) {
    if ( m>0 ) {
        n = m;
        abscisas = new double[n];
        alturas = new double[n];
        for ( int i = 0; i < n; i++ ) {
            abscisas[i] = 0;
            alturas[i] = 0;
        }
    } else {
        n = 0;
        abscisas = 0;
        alturas = 0;
    }
}

SkyLine::liberarMemoria() {
    if ( n>0 ) {
        delete[] abscisas;
        abscisas = 0;
        delete[] alturas;
        alturas = 0;
    }

    n = 0;
}

void SkyLine::copiar(const SkyLine &sky) {
    n = sky.n;
    reservarMemoria(n);
    for ( int i = 0; i < n; i++ ) {
        abscisas[i] = sky.abscisas[i];
        alturas[i] = sky.alturas[i];
    }
}
~~~

### **Ejercicio 3.** SkyLine: miembro público

#### Implementación de @mianfg

~~~
double SkyLine::Altura(double abscisa) {
    double altura = 0;
    for ( int i = 0; i < n; i++ )
        if ( abscisas[i] > abscisa )
            if ( i != 0 )
                altura = alturas[i-1];
    return altura;
}
~~~

### **Ejercicio 4.** SkyLine: sobrecarga de operadores

#### Implementación de @mianfg

~~~
SkyLine SkyLine::operator+(const SkyLine &sky) const {
    SkyLine suma;
    double* abscisas_aux = new double[n+sky.n];
    suma.n = MezclarUnico(abscisas, n, sky.abscisas, sky.n, abscisas_aux);
    suma.reservarMemoria(n);
    for ( int i = 0; i < n; i++ ) {
        suma.alturas[i] = Altura((abscisas_aux[i]+abscisas_aux[i+1])/2) + sky.Altura((abscisas_aux[i]+abscisas_aux[i+1])/2);
        suma.abscisas[i] = abscisas_aux[i];
    
    delete[] abscisas_aux;
    return suma;
}

ostream& operator<<(ostream& flujo, const SkyLine &sky) {
    flujo << sky.n << endl;
    for ( int i = 0; i < n; i++ ) {
        flujo << sky.abscisas[i] << " " << sky.abscisas[i+1] << " " << sky.alturas[i] << endl;
    }
}

istream& operator>>(istream& flujo, SkyLine &sky) {
    flujo >> sky.n;
    sky.liberarMemoria();
    sky.reservarMemoria(sky.n);
    for ( int i = 0; i < n; i++ )
        flujo >> sky.abscisas[i] >> sky.abscisas[i+1] >> sky.alturas[i];
}
~~~

### **Ejercicio 5.** SkyLine: funciones externas y ficheros

#### Implementación de @mianfg

~~~
bool SkyLine::Cargar(const char* fichero) {
    // falta comprobación de cadena mágica
    ifstream fentrada;
    fentrada.open(fichero);
    if (!fentrada)
        return false;
    fentrada >> (*this);
    if (fentrada)
        return true;
    else
        return false;
}

bool SkyLine::Salvar(const char* fichero) const {
    ifstream fsalida;
    fsalida.open(fichero);
    fsalida << (*this);
    if (fsalida)
        return true;
    else
        return false;
}
~~~
