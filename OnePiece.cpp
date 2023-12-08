
using namespace std;
#include <iostream>
#include <string>

// Clase base para representar un personaje de One Piece
class PersonajeOnePiece {
protected:
    string nombre;
    int nivelPoder;

public:
    PersonajeOnePiece(const string& nombre, int nivelPoder)
        : nombre(nombre), nivelPoder(nivelPoder) {}

    void saludar() const {
        cout << "¡Soy " << nombre << " de One Piece!" << endl;
    }

    void mostrarPoder() const {
        cout << "Nivel de poder: " << nivelPoder << endl;
    }
};

// Clase derivada para representar un pirata
class Pirata : public PersonajeOnePiece {
private:
    string apodo;

public:
    Pirata(const string& nombre, int nivelPoder, const string& apodo)
        : PersonajeOnePiece(nombre, nivelPoder), apodo(apodo) {}

    void presentarse() const {
        saludar();
        cout << "Me conocen como '" << apodo << "'." << endl;
        mostrarPoder();
    }
};

// Clase derivada para representar un marine
class Marine : public PersonajeOnePiece {
private:
    string rango;

public:
    Marine(const string& nombre, int nivelPoder, const string& rango)
        : PersonajeOnePiece(nombre, nivelPoder), rango(rango) {}

    void informar() const {
        saludar();
        cout << "Soy un marine con rango de '" << rango << "'." << endl;
        mostrarPoder();
    }
};

int main() {
    Pirata luffy("Monkey D. Luffy", 900, "Luffy");
    Marine smoker("Smoker", 800, "Capitán");

    cout << "\n** Presentación de Pirata **\n";
    luffy.presentarse();

    cout << "\n** Informe de Marine **\n";
    smoker.informar();

    return 0;
}