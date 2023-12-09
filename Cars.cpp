
using namespace std;
#include <iostream>
#include <string>

// Clase base para representar un auto
class Auto {
protected:
    string marca;
    string modelo;
    int año;

public:
    Auto(const string& marca, const string& modelo, int año)
        : marca(marca), modelo(modelo), año(año) {}

    void mostrarInfo() const {
        cout << "Marca: " << marca << ", Modelo: " << modelo << ", Año: " << año << endl;
    }

    virtual void arrancar() const {
        cout << "El auto está arrancando." << endl;
    }
};

// Clase derivada para representar un auto deportivo
class AutoDeportivo : public Auto {
private:
    int potencia;

public:
    AutoDeportivo(const string& marca, const string& modelo, int año, int potencia)
        : Auto(marca, modelo, año), potencia(potencia) {}

    void acelerar() const {
        cout << "Acelerando el auto deportivo. ¡Vroom, vroom!" << endl;
    }

    void arrancar() const override {
        cout << "Arrancando el auto deportivo. ¡Vroom!" << endl;
    }
};

// Clase derivada para representar un SUV
class SUV : public Auto {
private:
    bool traccionTotal;

public:
    SUV(const string& marca, const string& modelo, int año, bool traccionTotal)
        : Auto(marca, modelo, año), traccionTotal(traccionTotal) {}

    void conducirTodoTerreno() const {
        if (traccionTotal) {
            cout << "Conduciendo en terreno todo terreno con tracción en las cuatro ruedas." << endl;
        } else {
            cout << "Conduciendo en terreno todo terreno." << endl;
        }
    }
};

int main() {
    Auto sedan("Toyota", "Camry", 2022);
    AutoDeportivo deportivo("Ferrari", "LaFerrari", 2023, 950);
    SUV suv("Jeep", "Wrangler", 2022, true);

    cout << "** Información del Sedán **" << endl;
    sedan.mostrarInfo();
    sedan.arrancar();
    cout << endl;

    cout << "** Información del Auto Deportivo **" << endl;
    deportivo.mostrarInfo();
    deportivo.arrancar();
    deportivo.acelerar();
    cout << endl;

    cout << "** Información del SUV **" << endl;
    suv.mostrarInfo();
    suv.arrancar();
    suv.conducirTodoTerreno();

    return 0;
}