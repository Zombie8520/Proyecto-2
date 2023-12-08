
using namespace std;
#include <iostream>
#include <string>

// Parent class to represent a character from One Piece
class PersonajeOnePiece {
protected:
    string nombre;
    int nivelPoder;

public:
    PersonajeOnePiece(const string& nombre, int nivelPoder)
        : nombre(nombre), nivelPoder(nivelPoder) {}

    void saludar() const {
        cout << "I am " << nombre << endl;
    }

    void mostrarPoder() const {
        cout << "Power level: " << nivelPoder << endl;
    }
};

// Daughter class to represent a pirate
class Pirata : public PersonajeOnePiece {
private:
    string apodo;

public:
    Pirata(const string& nombre, int nivelPoder, const string& apodo)
        : PersonajeOnePiece(nombre, nivelPoder), apodo(apodo) {}

    void presentarse() const {
        saludar();
        cout << "I am known as '" << apodo << "'." << endl;
        mostrarPoder();
    }
};

// Derived class to represent a marine
class Marine : public PersonajeOnePiece {
private:
    string rango;

public:
    Marine(const string& nombre, int nivelPoder, const string& rango)
        : PersonajeOnePiece(nombre, nivelPoder), rango(rango) {}

    void informar() const {
        saludar();
        cout << "I am a Marine with the rank of '" << rango << "'." << endl;
        mostrarPoder();
    }
};

int main() {
    Pirata luffy("Monkey D. Luffy", 900, "Luffy");
    Marine smoker("Smoker", 800, "Captain");

    cout << "\n** Presentation of Pirate **\n";
    luffy.presentarse();

    cout << "\n** Marine Report **\n";
    smoker.informar();

    return 0;
}