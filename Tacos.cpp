using namespace std;
#include <iostream>
#include <string>

// Base class to represent a taco
class Taco {
protected:
    string type;
    double price;

public:
    Taco(const string& type, double price)
        : type(type), price(price) {}

    void showInfo() const {
        cout << "Taco type: " << type << ", Price: $" << price << endl;
    }

    virtual void prepare() const {
        cout << "Preparing the " << type << " taco." << endl;
    }
};

// Derived class to represent a carne asada taco
class TacoCarneAsada : public Taco {
private:
    bool withGreenSauce;

public:
    TacoCarneAsada(double price, bool withGreenSauce)
        : Taco("Carne Asada", price), withGreenSauce(withGreenSauce) {}

    void addGreenSauce() const {
        if (withGreenSauce) {
            cout << "Adding green sauce to the carne asada taco." << endl;
        } else {
            cout << "Preparing the carne asada taco without green sauce." << endl;
        }
    }

    void prepare() const override {
        cout << "Grilling the meat for the carne asada taco." << endl;
        addGreenSauce();
    }
};

// Derived class to represent a fish taco
class TacoPescado : public Taco {
private:
    string fishType;

public:
    TacoPescado(double price, const string& fishType)
        : Taco("Pescado", price), fishType(fishType) {}

    void prepare() const override {
        cout << "Preparing the fish taco with " << fishType << "." << endl;
    }
};

int main() {
    Taco simple("Carnitas", 2.5);
    TacoCarneAsada grilledWithSauce(3.0, true);
    TacoPescado specialFish(4.5, "tuna");

    cout << "** Information about the Simple Taco **" << endl;
    simple.showInfo();
    simple.prepare();
    cout << endl;

    cout << "** Information about the Carne Asada Taco **" << endl;
    grilledWithSauce.showInfo();
    grilledWithSauce.prepare();
    cout << endl;

    cout << "** Information about the Special Fish Taco **" << endl;
    specialFish.showInfo();
    specialFish.prepare();

    return 0;
}
