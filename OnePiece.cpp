using namespace std;
#include <iostream>
#include <string>

// Clase Padre para representar un personaje de One Piece
class OnePieceCharacter {
protected:
    string name;
    int powerLevel;

public:
    OnePieceCharacter(const string& name, int powerLevel)
        : name(name), powerLevel(powerLevel) {}

    void greet() const {
        cout << "I am " << name << endl;
    }

    void showPower() const {
        cout << "Power level: " << powerLevel << endl;
    }
};

// Clase hija para representar un pirata
class Pirate : public OnePieceCharacter {
private:
    string nickname;

public:
    Pirate(const string& name, int powerLevel, const string& nickname)
        : OnePieceCharacter(name, powerLevel), nickname(nickname) {}

    void introduce() const {
        greet();
        cout << "I am known as '" << nickname << "'." << endl;
        showPower();
    }
};

// Clase derivada para representar un marine
class Marine : public OnePieceCharacter {
private:
    string rank;

public:
    Marine(const string& name, int powerLevel, const string& rank)
        : OnePieceCharacter(name, powerLevel), rank(rank) {}

    void report() const {
        greet();
        cout << "I am a Marine with the rank of '" << rank << "'." << endl;
        showPower();
    }
};

int main() {
    Pirate luffy("Monkey D. Luffy", 900, "Luffy");
    Marine smoker("Smoker", 800, "Captain");

    cout << "\n** Presentation of Pirate **\n";
    luffy.introduce();

    cout << "\n** Marine Report **\n";
    smoker.report();

    return 0;
}
