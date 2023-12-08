
#include <iostream>
#include <string>

// Base class to represent a car
class Car {
protected:
    std::string brand;
    std::string model;
    int year;

public:
    Car(const std::string& brand, const std::string& model, int year)
        : brand(brand), model(model), year(year) {}

    void showInfo() const {
        std::cout << "Brand: " << brand << ", Model: " << model << ", Year: " << year << std::endl;
    }

    virtual void start() const {
        std::cout << "The car is starting." << std::endl;
    }
};

// Derived class to represent a sports car
class SportsCar : public Car {
private:
    int power;

public:
    SportsCar(const std::string& brand, const std::string& model, int year, int power)
        : Car(brand, model, year), power(power) {}

    void accelerate() const {
        std::cout << "Accelerating the sports car. Vroom, vroom!" << std::endl;
    }

    void start() const override {
        std::cout << "Starting the sports car. Vroom!" << std::endl;
    }
};

// Derived class to represent an SUV
class SUV : public Car {
private:
    bool allWheelDrive;

public:
    SUV(const std::string& brand, const std::string& model, int year, bool allWheelDrive)
        : Car(brand, model, year), allWheelDrive(allWheelDrive) {}

    void driveOffRoad() const {
        if (allWheelDrive) {
            std::cout << "Driving on all-terrain with all-wheel drive." << std::endl;
        } else {
            std::cout << "Driving on all-terrain." << std::endl;
        }
    }
};

int main() {
    Car sedan("Toyota", "Camry", 2022);
    SportsCar sportsCar("Ferrari", "LaFerrari", 2023, 950);
    SUV suv("Jeep", "Wrangler", 2022, true);

    std::cout << "** Sedan Information **" << std::endl;
    sedan.showInfo();
    sedan.start();
    std::cout << std::endl;

    std::cout << "** Sports Car Information **" << std::endl;
    sportsCar.showInfo();
    sportsCar.start();
    sportsCar.accelerate();
    std::cout << std::endl;

    std::cout << "** SUV Information **" << std::endl;
    suv.showInfo();
    suv.start();
    suv.driveOffRoad();

    return 0;
}
