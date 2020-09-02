# Examen junio 2012 (GI)

> Alumno: Miguel Ángel Fernández Gutiérrez

## Especificación PoliLinea (`.h`)

~~~
class Punto {
    int x, y;   // coordenadas de un punto en 2D
    ...
    // haría falta hacer sobrecarga = y constructor por defecto a (0,0)
    // tb getX, getY, setX, setY
};

class PoliLinea {
    Punto *p;   // vector de puntos
    int num;    // número de puntos

    void reservarMemoria(int n);
    void liberarMemoria();
    void copiar(const PoliLinea &otro);
public:
    PoliLinea();
    ~PoliLinea();
    PoliLinea(const PoliLinea &otro);
    PoliLinea& operator=(const PoliLinea &otro);
    Punto& operator[](int n);
    bool operator==(const PoliLinea &otro);
    bool operator!=(const PoliLinea &otro);
    PoliLinea operator+(const Punto &punto) const;
    friend PoliLinea operator+(const Punto &punto, const PoliLinea& lineas);
    bool LeerPolilinea(const char* nombre);
    bool EscribirPolilinea(const char* nombre, const char* comentario=0);
};
~~~

## Implementación PoliLinea (`.cpp`)

### **Ejercicio 1a.** Constructor sin parámetros

~~~
PoliLinea::PoliLinea() {
    reservarMemoria(0);
}

PoliLinea::~PoliLinea() {
    liberarMemoria();
}

void PoliLinea::reservarMemoria(int n) {
    Punto cero;
    if ( n>0 ) {
        p = new Punto[n];
        for ( int i = 0; i < n; i++ )
            p[i] = cero;
        num = n;
    } else {
        num = 0;
        n = 0;
    }
}

void PoliLinea::liberarMemoria() {
    delete[] p;
    p = 0;
    num = 0;
}

void PoliLinea::copiar(const PoliLinea &otro) {
    reservarMemoria(otro.num);
    num = otro.num;
    for ( int i = 0; i < num; i++ )
        p[i] = otro.p[i];
}
~~~

### **Ejercicio 1b.** Constructor de copia y sobrecarga de `operator=`

~~~
PoliLinea::PoliLinea(const PoliLinea &otro) {
    copiar(otro);
}

PoliLinea& PoliLinea::operator=(const PoliLinea &otro) {
    liberarMemoria();
    copiar(otro);
}
~~~

### **Ejercicio 1c.** Sobrecarga de `operator[]`

~~~
Punto& PoliLinea::operator[](int n) {
    if ( n >= 0 && n < num )
        return p[n];
    else
        exit(1);
}
~~~

### **Ejercicio 1d.** Sobrecarga de `operator==` y `operator!=`

~~~
bool PoliLinea::operator==(const PoliLinea &otro) const {
    bool coinciden = true;

    if ( otro.num != num )
        coinciden = false;
    
    // ver si coinciden hacia delante
    for ( int i = 0; i < num && coinciden; i++ )
        if ( otro.p[i] != p[i] )
            coinciden = false;
    
    // ver si coinciden hacia atrás
    for ( int i = 0; i < num && coinciden; i++ )
        if ( otro.p[i] != p[num-i-1] )
            coinciden = false;

    return coinciden;
}

bool PoliLinea::operator!=(const PoliLinea &otro) const {
    return !((*this)==otro);
}
~~~

### **Ejercicio 1e.** Sobrecarga de `operator+`

~~~
PoliLinea PoliLinea::operator+(const Punto &punto) const {
    p_aux = new Punto[num+1];
    for ( int i = 0; i < num; i++ ) {
        p_aux[i] = p[i];
    }
    p_aux[num] = punto;
    delete[] p;
    p = p_aux;
    num++;
}

PoliLinea operator+(const Punto &punto, const PoliLinea& lineas) {
    PoliLinea resultado;
    resultado = resultado + punto;
    for ( int i = 0; i < lineas.num; i++ )
        resultado = resultado + p[i];
    return resultado;
}
~~~

### **Ejercicio 2a.** E/S (I): LeerPolilinea

~~~
bool PoliLinea::LeerPolilinea(const char* nombre) {
    ifstream fentrada;
    fentrada.open(nombre);
    if (!fentrada)
        return false;
    
    string magica;
    getline(fentrada, magica);
    if ( magica != "POLILINEA" )
        return false;
    
    char comprobar_comentario;
    fentrada.get(comprobar_comentario);
    fentrada.putback(comprobar_comentario);
    if ( comprobar_comentario == '#' )
        getline(fentrada, magica);          // ignorar el comentario
    
    fentrada >> num;
    int x_prov, y_prov;
    for ( int i = 0; i < num; i++ ) {
        fentrada >> x_prov >> y_prov;
        p[i].setX(x_prov);
        p[i].setY(y_prov):
    }
    fentrada.close();
    return true;
}
~~~

### **Ejercicio 2b.** E/S (II): EscribirPolilinea

~~~
bool PoliLinea::EscribirPolilinea(const char* nombre, const char *comentario) const {
    ifstream fsalida;
    fsalida.open(nombre);
    if (!fsalida)
        return false;
    fsalida << "POLILINEA" << endl;
    if (comentario!=0)
        fsalida << "#" << comentario << endl;
    for ( int i = 0; i < num; i++ )
        cout << p[i].getX() << " " << p[i].getY() << endl;
    fsalida.close();
    return true;
}
~~~