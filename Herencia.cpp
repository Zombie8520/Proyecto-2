using namespace std;
#include <iostream>
#include <string>

// Clase base
class Animal {
public:
    Animal(const string& nombre) : nombre_(nombre) {}

    void comer() const {
        cout << nombre_ << " está comiendo." << endl;
    }

    void dormir() const {
        cout << nombre_ << " está durmiendo." << endl;
    }

private:
    string nombre_;
};

// Clase derivada
class Perro : public Animal {
public:
    Perro(const string& nombre, const string& raza) : Animal(nombre), raza_(raza) {}

    void ladrar() const {
        cout << "¡Guau! Soy un perro de raza " << raza_ << "." << endl;
    }

private:
    string raza_;
};

int main() {
    // Crear un objeto de la clase base
    Animal animal("Animal");

    // Usar funciones de la clase base
    animal.comer();
    animal.dormir();

    cout << "---------------------" << endl;

    // Crear un objeto de la clase derivada
    Perro miPerro("Buddy", "Labrador");

    // Usar funciones de ambas clases (herencia)
    miPerro.comer();
    miPerro.dormir();
    miPerro.ladrar();

    return 0;
}