//Clase

#include<bits/stdc++.h>

using namespace std;

// ----------------------------------------------------------------
// Clase abstracta
class TrabajadorAbstracto{
    virtual void recibirPago()=0; // Funcion miembro pura (virtual pura)
};

// -------------- CLASES PADRES (E HIJAS DE LA ABSTRACTA) ----------
// Clase Padre y a su vez clase hija de la abstracta
class Empleado:TrabajadorAbstracto{  // Empleado hereda de TrabajadorAbstracto y su vez es clase padre de otras clases.
protected:
    string nombre;  // Pasamos Nombre a protected para que sus clases hijas puedan acceder a ellas.

private:    // Estan encapsuladas. Son privadas y nadie fuera de la clase pueda accesar a ellas.
    string compania;
    char categoria;
    int edad;
    int antiguedad;


public:
    // Metodo
    void presentarse(){
        cout << "Nombre: " << nombre << endl;
        cout << "Compania: " << compania << endl;
        cout << "Edad: " << edad << endl;
    }

    // Constuctor por default
    // Empleado(){};

    // (otro) Constructor por default. Solo puede haber uno.
    Empleado(){
        nombre = "No definido";
        compania = "No definida";
        categoria = 'A';
        edad = 0;
        antiguedad = 0;
    };

    Empleado(string nombre, string compania, char categoria, int edad, int antiguedad){
        this->nombre = nombre;
        this->compania = compania;
        this->categoria = categoria;
        this->edad = edad;
        this->antiguedad = antiguedad;
    }

    ~Empleado(){
        cout << "Destruyendo objeto...(Clase Empleado)" << endl;
    }

    // Getters y Setters
    void setNombre(string nombre){
        this->nombre = nombre;
    }

    string getNombre(){
        return nombre;
    }

    void setCompania(string compania){
        this->compania = compania;
    }

    string getCompania(){
        return compania;
    }

    void setCategoria(char categoria){
        this->categoria = categoria;
    }

    char getCategoria(){
        return categoria;
    }

    void setEdad(int edad){
        this->edad = edad;
    }

    int getEdad(){
        return edad;
    }

    void setAntiguedad(){
        this->antiguedad = antiguedad;
    }

    int getAntigued(){
        return antiguedad;
    }

    // Implementacion del metodo de la clase abstracta
    void recibirPago(){
        cout << "Recibira su sueldo a su cuenta bancaria cada quincena\n";
    }

    // Nueva funcion
    virtual void trabajar(){ // Al hacerla virtual, obligamos a que las hijas hagan una implementacion del metodo trabajar() para aplicar polimorfismo,
                    // De lo contrario, se usa la implementacion del padre.
        cout << "Trabajando... Atendiendo pendientes, revisando agenda..." << endl;
    }

    void checarSalida(){
        cout << "El trabajador " << nombre << " acaba de checar su salida" << endl;
    }
};

// Otra clase Padre y a su vez clas hija de la abstracta
class Profesionista:TrabajadorAbstracto{
protected:
    string nombre;

private:
    string rfc;
    string profesion;
    int edad;
    int id;

    static int cont;


public:
    // Constructor por defecto
    Profesionista(){};

    // Constructor parametrizado
    Profesionista(string nombre, string profesion, string rfc, int edad, int id){
        this->nombre = nombre;
        this->profesion = profesion;
        this->rfc = rfc;
        this->edad = edad;
        this->id = id;
        contadorDeInstancias();
    }

    // getters y setters
    string getNombre(){
        return nombre;
    }

    void setNombre(string nombre) {
        nombre = nombre;
    }

    string getRfc(){
        return rfc;
    }

    void setRfc(string rfc) {
        this->rfc = rfc;
    }

    int getId(){
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    void recibirPago(){
        cout << "Recibira pago por honorarios" << endl;
    }

    void declararAlSAT(){
        cout << "El profesionista presentara su declaracion al SAT " << endl;
    }

    void mostrarRFC(){
        cout << "El RFC de " << nombre << " es: " << getRfc() << endl;
    }

    // Metodo estatico: Le pertenece a la clase.
    static int contadorDeInstancias(){
        cont++;
        return cont;
    }
};

// Nueva clase padre (solo para probar herencia multiple)
class Cientifico{
protected:
    string academia;
    string grado;

public:
    Cientifico(string academia, string grado){
        this->academia = academia;
        this->grado = grado;
    }

    ~Cientifico(){
        cout << "Destruyendo objeto... (Clase Cientifico)" << endl;
    }

    void realizarExperimento(){
        cout << "Realizando experimento en el laboratorio" << endl;
    }

    void presentarse(){
        cout << "Grado: " << grado << endl << "Academia de: " << academia << endl;
    }
};

// --------------- CLASES HIJAS ------------------------------------
// Clase Hija de Empleado
class IngenieroMecatronico: public Empleado{
public:
    string lenguajeFavorito;
    string controladorFavorito;

    // Constructor de la clase hija
    IngenieroMecatronico(string nombre, string compania, char categoria, int edad, int antiguedad, string lenguajeFavorito, string controladorFavorito)
        :Empleado(nombre, compania, categoria, edad, antiguedad){  // Aprovecha el constructor del padre.
            this->lenguajeFavorito = lenguajeFavorito;
            this->controladorFavorito = controladorFavorito;
        }
    
    // Getters y setters
    string getLenguajeFavorito(){
        return lenguajeFavorito;
    }

    void setLenguajeFavorito(string lenguajeFavorito){
        this->lenguajeFavorito = lenguajeFavorito;
    }

    string getControladorFavorito(){
        return controladorFavorito;
    }

    void setControladorFavorito(string controladorFavorito){
        this->controladorFavorito = controladorFavorito;
    }

    // metodo propio de la clase hija
    void programarMicros(){
        cout << "El Ingeniero " << nombre << " programa micros en " << lenguajeFavorito << endl;
    }

    // segundo metodo propio de la clase hija
    void construirPrototipos(){
        cout << "El Ingeniero " << nombre << " esta realizando un prototipo para un controlador " << controladorFavorito << endl;
    }

    // Polimorfismo (Definicion informal): Un metodo o clase puede tener formas distintas
    // Diferente implementacion del metodo trabajar() heredado del padre.
    void trabajar(){
        cout << "El Ingeniero " << nombre << " esta trabajando con PLC" << endl;
    }
};

// Otra clase hija de Empleado
class IngenieroBioelectronico: public Empleado{
public:
    string disenoFavorito;
    string microFavorito;

    // Constructor de la clase hija
    IngenieroBioelectronico(string nombre, string compania, char categoria, int edad, int antiguedad, string disenoFavorito, string microFavorito)
        :Empleado(nombre, compania, categoria, edad, antiguedad){  // Aprovecha el constructor del padre.
            this->disenoFavorito = disenoFavorito;    // Solo define los atributos propios
            this->microFavorito = microFavorito;
        }
    
    // Getters y setters
    string getDisenoFavorito() { 
        return disenoFavorito; 
    }

    void setDisenoFavorito(string disenoFavorito) {
        this->disenoFavorito = disenoFavorito;
    }

    string getMicroFavorito(){
        return microFavorito;
    }

    void setMicroFavorito(string microFavorito) {
        this->microFavorito = microFavorito;
    }

    // metodo propio de la clase hija
    void disenar(){
        cout << "El Ingeniero " << nombre << " disena en " << disenoFavorito << endl;
    }

    // Otro metodo propio de la clase hija
    void quemarMicroFavorito(){
        cout << "El Ingeniero " << nombre << " quemo su microcontrolador " << microFavorito << endl;
    }

    // Otro ejemplo de polimorfismo
    void trabajar(){
        cout << "El Ingeniero " << nombre << " esta disenando circuitos de bioinstrumentacion" << endl;
    }
};

// Clase hija de Profesionista
class Profesor: public Profesionista{
public:
    string materia;
    string grado;

    // Constructor
    Profesor(string nombre, string profesion, string rfc, int edad, int id, string materia, string grado)
    : Profesionista(nombre, profesion, rfc, edad, id){
        this->materia = materia;
        this->grado = grado;
    }

    // Getters y setters
    string getMateria(){
        return materia;
    }

    void setMateria(string materia){
        this->materia = materia;
    }

    string getGrado(){
        return grado;
    }

    void setGrado(string grado){
        this->grado = grado;
    }

    // Metodos propios
    void prepararClase(){
        cout << "El " << grado << " " << nombre << " esta preparando la clase de " << materia << endl;
    }

    void darClase(){
        cout << "El " << grado << " " << nombre << " imparte su clase de " << materia << endl;
    } 
};

class Medico: public Profesionista{
public:
    string especialidad;
    string hospital;

    // Constructor
    Medico(string nombre, string profesion, string rfc, int edad, int id, string especialidad, string hospital)
    : Profesionista(nombre, profesion, rfc, edad, id){
        this->especialidad = especialidad;
        this->hospital = hospital;
    }

    // Getters y Setters
    string getEspecialidad() { 
        return this->especialidad; 
    }

    void setEspecialidad(string especialidad) {
        this->especialidad = especialidad;
    }

    string getHospital(){
        return hospital;
    }

    void setHospital(string hospital) {
        this->hospital = hospital;
    }

    // Metodos propios de la clase
    void consultar(){
        cout << "El Dr. " << nombre << " reviso a su paciente y le receto antibioticos" << endl;
    }

    void hacerGuardia(){
        cout << "El Dr. " << nombre << " debe hacer guardia en el hospital " << hospital << endl;
    }
};

class Investigador: public Empleado, public Cientifico{
    string areaInvestigacion;

public:
    // Constructor
    Investigador(string nombre, string compania, char categoria, int edad, int antiguedad, string academia, string grado, string areaInvestigacion)
                :Empleado(nombre, compania, categoria, edad, antiguedad), Cientifico(academia, grado){
                    this->areaInvestigacion = areaInvestigacion;
                }

    void hacerPresentacion(){
        Empleado::presentarse();
        Cientifico::presentarse();
    }

};

// ---------------- METODOS NO MIEMBROS DE NINGUNA CLASE ---------------
void aumentarEdad(Empleado &empleado){ // Se esta pasando un objeto como parametro de la funcion (Como referencia para que se apliquen los cambios en el objeto original)
    int nuevaEdad = empleado.getEdad() + 1;
    cout << "Nueva Edad: " << nuevaEdad << endl;
    empleado.setEdad(nuevaEdad);
}

// Que sucede aqui? Mismo nombre, diferentes parametros? - Sobrecarga de funciones.
void aumentarEdad(Empleado *p_empleado){ // Se esta pasando un puntero de tipo del objeto como parametro de la funcion (Se aplican los cambios en el objeto original)
    int nuevaEdad = p_empleado->getEdad() + 1;
    cout << "Nueva Edad: " << nuevaEdad << endl;
    p_empleado->setEdad(nuevaEdad);
}

// Uso de la variable estatica de la clase Profesionista (Inicializacion)
int Profesionista::cont = 0;
// --------------- MAIN ---------------------------------------------
int main(){

    Empleado empleado1 = Empleado("Eduardo", "UP", 'A', 27, 3);
    empleado1.presentarse();

    cout << empleado1.getNombre() << " tiene " << empleado1.getEdad() << " y trabaja en " << empleado1.getCompania() << endl;
    cout << endl;

    // Creando un nuevo objeto de la clase IngenieroMecatronico
    IngenieroMecatronico mec = IngenieroMecatronico("Emmanuel", "Bonaterra", 'B', 30, 4, "C", "PID");
    mec.programarMicros();
    cout << endl;

    // Creando un nuevo objeto de la clase IngenieroBioelectronico
    IngenieroBioelectronico bio = IngenieroBioelectronico("Daniel", "Hospital", 'A', 31, 3, "SolidWorks", "ATMega-328P");
    bio.disenar();
    cout << endl;

    Empleado empleadoNuevo; // Exiten dos constructores, el default y el parametrizado.
    empleadoNuevo.presentarse(); // El objeto empleadoNuevo no tiene informacion brindada por el usuario, sino cadenas vacias y un numero aleatorio.
    cout << endl;

    // Uso de la funcion no miembro
    aumentarEdad(&empleado1);
    empleado1.presentarse(); // Llamada solo para aprovechar que en este metodo se imprime la edad
    cout << endl;

    aumentarEdad(bio);
    bio.presentarse();
    cout << endl;

    /* Polimorfismo (Aproximacion formal):
    El uso mas comun del polimorfismo es cuando una referencia a una clase padre es usada para referir a un objeto de una clase hija
    */

    // Punteros hacia las clases
    Empleado* e1 = &mec;
    Empleado* e2 = &bio;

    // Al llamar a los metodos de las clases hijas a traves de los punteros, se ejecutara para ambos casos el de la clase padre, a menos que esta sea virtual.
    // Si alguna clase hija no implemento el metodo al cual trata de acceder, por defecto utilizara el de su clase padre.
    e1->trabajar();
    e2->trabajar();
    cout << endl;

    // Creando objetos con las nuevas clases
    Profesionista p1; // Se inicializa con el constructor por defecto.
    cout << "ID del profesionista: " << p1.getId() << endl;
    cout << endl;

    Profesor prof1 = Profesor("Emmanuel", "Ing. Biomedico", "ROLE123", 27, 1234, "Programacion Avanzada", "MCC");
    prof1.darClase();
    prof1.declararAlSAT();

    Medico dr = Medico("Gregorio Casas", "Lic. Medico cirujano", "GCC1234", 35, 1234, "Medico diagnosta", "Princeton");
    dr.consultar();
    dr.hacerGuardia();
    cout << endl;

    // Uso de metodo estatico
    cout << "Se han realizado " << Profesionista::contadorDeInstancias() << " instancias de la clase Profesionista" << endl;

    // Ejemplo de objeto con herencia multiple
    Investigador inv = Investigador("Mario", "UCI", 'A', 45, 20, "Quimica", "Dr", "Quimica molecular");
    inv.realizarExperimento(); // Es heredado de clase Cientifico
    inv.hacerPresentacion(); // Invocacion al metodo de la clase Investigador que a su vez llama a ambos metodos presentarse()

    return 0;
}