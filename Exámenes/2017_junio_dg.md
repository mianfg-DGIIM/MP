# Examen junio 2017 (DG)

> Alumno: Miguel Ángel Fernández Gutiérrez

## Especificación (`.h`)

~~~
// CUIDADO CON LOS INCLUDE


struct InfoCiudad {
	char *nombre;
	int poblacion;
};

class RedCiudades {
private:
	int num_ciudades;			// número de ciudades
	InfoCiudad *info;			// info[i] : info de la ciudad i
	double **distancia;			// distancia[i][j] : distancia entre ciudades i y j

	void reservarMemoria(int n);
	void liberarMemoria();
	void copiar(const RedCiudades &red);
public:
	// se dispone de los métodos
	NumCiudades();				// devuelve el número de ciudades
	Distancia(int i, int j);	// devuelve distancia entre dos ciudades
	NombreCiudad(int i);		// devuelve nombre de una ciudad
								// (en realidad, dirección de inicio)
	PoblacionCiudad(int i);		// devuelve número de habitantes

	// EJERCICIO 1: constructor por defecto
	RedCiudades();
	// EJERCICIO 1: ver si está vacía
	bool EstaVacia() const;
	// EJERCICIO 1: destructor
	~RedCiudades();
	// EJERCICIO 1: constructor de copia
	RedCiudades(const RedCiudades &red);
	// EJERCICIO 1: operador de asignación
	RedCiudades& operator=(const RedCiudades & red);

	// EJERCICIO 2: operador de salida
	friend ostream& operator<<(ostream &flujo, const RedCiudades &red);
	// EJERCICIO 2: operador de entrada
	friend istream& operator>>(istream &flujo, RedCiudades &red);

	// EJERCICIO 3: constructor con argumento fichero
	
	LeerRedCiudades(
};
~~~

## Implementación (`.cpp`)

### **Ejercicio 1:** métodos básicos de la clase

#### Implementación de @mianfg

~~~
RedCiudades::RedCiudades() {
	reservarMemoria(0);
}

bool RedCiudades::EstaVacia() const {
	return (num_ciudades == 0);
}

RedCiudades::~RedCiudades() {
	liberarMemoria();
}

RedCiudades::RedCiudades(const RedCiudades &red) {
	copiar(red);
}

RedCiudades& RedCiudades::operator=(const RedCiudades &red) {
	liberarMemoria();
	copiar(red);
}

void RedCiudades::reservarMemoria(int n) {
	if ( n>0 ) {
		info = new InfoCiudad[n];
		for ( int i = 0; i < n; i++ ) {
			info[i].nombre = 0;
			info[i].poblacion = 0;
		}
		distancia = new double*[n];
		for ( int i = 0; i < n; i++ ) {
			distancia[i] = new double[n];
			for ( int j = 0; j < n; j++ )
				distancia[i][j] = 0;
		}
		num_ciudades = n;
	} else {
		num_ciudades = 0;
		distancia = 0;
		info = 0;
	}
	
}

void RedCiudades::liberarMemoria() {
	if ( info ) {
		for ( int i = 0; i < num_ciudades; i++ )
			delete[] info[i].nombre;
		delete[] info;
		info = 0;
	}
	
	if ( distancia ) {
		for ( int i = 0; i < num_ciudades, i++ )
			delete[] distancia[i];
		delete[] distancia;
		distancia = 0;
	}

	num_ciudades = 0;
}

void RedCiudades::copiar(const RedCiudades &red) {
	reservarMemoria(red.num_ciudades);
	num_ciudades = red.num_ciudades;
	for ( int i = 0; i < num_ciudades; i++ ) {
		info[i].nombre = new char[strlen(red.info[i].nombre)];
		strcpy(info[i].nombre, red.info[i].nombre);
		info[i].poblacion = red.info[i].poblacion;
		for ( int j = 0; j < num_ciudades; j++ )
			distancia[i][j] = red.distancia[i][j];
	}
}
~~~

### **Ejercicio 2:** sobrecarga de operadores

#### Implementación de @mianfg

~~~
ostream& operator<<(ostream& flujo, const RedCiudades &red) {
	flujo << num_ciudades << endl;
	for ( int i = 0; i < num_ciudades; i++ )
		flujo << i << " " << info[i].nombre << " " << info[i].poblacion << endl;
	for ( int i = 0; i < num_ciudades; i++ )
		for ( int j = 0; j < num_ciudades; j++ )
			if ( i <= j )
				flujo << i << " " << j << " " << distancia[i][j] << endl;
	return flujo;
}

istream& operator>>(istream& flujo, RedCiudades& red) {
	int num; string cadena; int index1, index2;
	flujo >> red.num_ciudades;
	red.liberarMemoria();
	red.reservarMemoria(red.num_ciudades);
	for ( int i = 0; i < red.num_ciudades; i++ ) {
		flujo >> num >> cadena >> red.info[num].poblacion;
		red.info[num].nombre = new char[cadena.size()];
		strcpy(red.info[num].nombre, cadena.c_str());
	}
		
	while ( flujo >> index1 ) {
		flujo >> index2 >> red.distancia[index1][index2];
		red.distancia[index2][index1] = red.distancia[index1][index2];
	}
}
~~~

### **Ejercicio 3:** métodos y funciones para E/S

#### Implementación de @mianfg

~~~
RedCiudades::RedCiudades(const char* fichero) {
	if ( !LeerRedCiudades(fichero) ) {
		cerr << "ERROR en RedCiudades::RedCiudades(const char*fichero): no se pudo abrir el fichero, asignando entrada vacía." << endl;
		reservarMemoria(0);
	}
}

bool RedCiudades::LeerRedCiudades(const char* fichero) {
	ifstream fentrada;
	fentrada.open(fichero);
	// COMPROBAR SI LO HEMOS ABIERTO
	if (!fentrada)
		return false;
	string palabra_magica;
	fentrada >> palabra_magica;
	if ( strcmp(palabra_magica, "RED")==0 )
		return false;
	fentrada >> (*this);
	fentrada.close();
	return true;
}

bool RedCiudades::EscribirRedCiudades(const char* fichero) {
	ifstream fsalida;
	fsalida.open(fichero);
	fichero << (*this);
	bool status = fsalida;
	fsalida.close();
	return status;
}
~~~

### **Ejercicio 4:** métodos de cálculo

~~~
int RedCiudades::CiudadMejorConectada() const {
	int mejor_conectada = -1;
	double suma = 0;
	double mejor_suma = 0;
	for ( int i = 0; i < num_ciudades; i++ ) {
		suma = 0; // MUY IMPORTANTE
		for ( int j = 0; j < num_ciudades; j++ ) {
			suma += distancia[i][j];
		}
		if ( suma > mejor_suma ) {
			mejor_suma = suma;
			mejor_conectada = i;
		}
	}

	return mejor_conectada;
}

int RedCiudades::MejorEscalaEntre(int i, int j) const {
	int ciudad_intermedia = -1;
	bool primera_distancia = false;
	double distancia;
	double distancia_optima;
	for ( int k = 0; k < num_ciudades; k++ ) {
		if ( distancia[i][k] > 0 ) {
			if ( distancia[k][j] > 0 ) {
				distancia = distancia[i][k] + distancia[k][j];
				if (!primera_distancia) {
					distancia_optima = distancia;
					primera_distancia = true;
				}
				if ( distancia <= distancia_optima ) {
					distancia_optima = distancia;
					ciudad_intermedia = k;
				}
			}
		}
	}
	return ciudad_intermedia;
}
~~~

#### Corrección

_En `CiudadMejorConectada` se refiere a la **ciudad con mayor número de conexiones**, lo que he hecho no tiene sentido alguno -- **¡¡¡cuidado con los enunciados!!!**_

~~~
int RedCiudades::CiudadMejorConectada() const {
	int mejor_conectada = -1;
	int num_conexiones = 0;
	int mayor_num_conexiones = 0;
	for ( int i = 0; i < num_ciudades; i++ ) {
		num_conexiones = 0;
		for ( int j = 0; j < num_ciudades; j++ )
			if ( distancia[i][j] > 0 )
				num_conexiones++;
		if ( num_conexiones > mayor_num_conexiones ) {
			mayor_num_conexiones = num_conexiones;
			mejor_conectada = i;
		}
	}
	return mejor_conectada;
}
~~~

### **Ejercicio 5:** aplicación

#### Implementación del alumno

~~~
int main(int argc, char* argv[]) {
	if ( argc < 2 ) {
		cerr << "Número de argumentos incorrecto" << endl;
		return 1;
	}
	RedCiudades red;
	red.LeerRedCiudades(argv[1]);

	int ciudad_intermedia;

	for ( int i = 0; i < ; i++ )
		for ( int j = i+1; j < ; j++ )
			if ( red.Distancia(i,j) == 0 && i!=j ) { // IMPORTANTE COMPROBAR SI i!=j
				ciudad_intermedia = MejorEscalaEntre(i,j);
				cout << "Escala intermedia entre ciudades " << i << " y " << j << ": ";
				if ( ciudad_intermedia == -1 )
					cout << "no existe" << endl;
				else
					cout << "ciudad " << ciudad_intermedia << endl;
			}
}
~~~