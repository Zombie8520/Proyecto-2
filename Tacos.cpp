
using namespace std;
#include <iostream>
#include <string>

// Clase base para representar un taco
class Taco {
protected:
    string tipo;
    double precio;

public:
    Taco(const string& tipo, double precio)
        : tipo(tipo), precio(precio) {}

    void mostrarInfo() const {
        cout << "Tipo de taco: " << tipo << ", Precio: $" << precio << endl;
    }

    virtual void preparar() const {
        cout << "Preparando el taco de " << tipo << "." << endl;
    }
};

// Clase derivada para representar un taco de carne asada
class TacoCarneAsada : public Taco {
private:
    bool conSalsaVerde;

public:
    TacoCarneAsada(double precio, bool conSalsaVerde)
        : Taco("Carne Asada", precio), conSalsaVerde(conSalsaVerde) {}

    void agregarSalsaVerde() const {
        if (conSalsaVerde) {
            cout << "Añadiendo salsa verde al taco de carne asada." << endl;
        } else {
            cout << "Preparando el taco de carne asada sin salsa verde." << endl;
        }
    }

    void preparar() const override {
        cout << "Asando la carne para el taco de carne asada." << endl;
        agregarSalsaVerde();
    }
};

// Clase derivada para representar un taco de pescado
class TacoPescado : public Taco {
private:
    string tipoPescado;

public:
    TacoPescado(double precio, const string& tipoPescado)
        : Taco("Pescado", precio), tipoPescado(tipoPescado) {}

    void preparar() const override {
        cout << "Preparando el taco de pescado con " << tipoPescado << "." << endl;
    }
};

int main() {
    Taco simple("Carnitas", 2.5);
    TacoCarneAsada asadaConSalsa(3.0, true);
    TacoPescado pescadoEspecial(4.5, "atún");

    cout << "** Información del Taco Simple **" << endl;
    simple.mostrarInfo();
    simple.preparar();
    cout << endl;

    cout << "** Información del Taco de Carne Asada **" << endl;
    asadaConSalsa.mostrarInfo();
    asadaConSalsa.preparar();
    cout << endl;

    cout << "** Información del Taco de Pescado Especial **" << endl;
    pescadoEspecial.mostrarInfo();
    pescadoEspecial.preparar();

   