using namespace std;
#include <iostream>
#include <string>

// Base class
class Animal {
public:
    Animal(const string& name) : name_(name) {}

    void eat() const {
        cout << name_ << " is eating." << endl;
    }

    void sleep() const {
        cout << name_ << " is sleeping." << endl;
    }

private:
    string name_;
};

// Derived class
class Dog : public Animal {
public:
    Dog(const string& name, const string& breed) : Animal(name), breed_(breed) {}

    void bark() const {
        cout << "Woof! I'm a " << breed_ << " dog." << endl;
    }

private:
    string breed_;
};

int main() {
    // Creating an object of the base class
    Animal animal("Animal");

    // Using functions from the base class
    animal.eat();
    animal.sleep();

    cout << "---------------------" << endl;

    // Creating an object of the derived class
    Dog myDog("Buddy", "Labrador");

    // Using functions from both classes (inheritance)
    myDog.eat();
    myDog.sleep();
    myDog.bark();

    return 0;
}
