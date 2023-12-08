#include<bits/stdc++.h>

using namespace std;

// ----------------------------------------------------------------
// Abstract class
class AbstractWorker {
    virtual void receivePayment() = 0; // Pure virtual member function
};

// -------------- PARENT CLASSES (AND CHILDREN OF THE ABSTRACT CLASS) ----------
// Parent Class, also a child class of the abstract class
class Employee : public AbstractWorker {
protected:
    string name;

private:
    string company;
    char category;
    int age;
    int seniority;

public:
    void introduce() {
        cout << "Name: " << name << endl;
        cout << "Company: " << company << endl;
        cout << "Age: " << age << endl;
    }

    Employee() {
        name = "Undefined";
        company = "Undefined";
        category = 'A';
        age = 0;
        seniority = 0;
    };

    Employee(string name, string company, char category, int age, int seniority) {
        this->name = name;
        this->company = company;
        this->category = category;
        this->age = age;
        this->seniority = seniority;
    }

    ~Employee() {
        cout << "Destroying object...(Employee Class)" << endl;
    }

    void setName(string name) {
        this->name = name;
    }

    string getName() {
        return name;
    }

    void setCompany(string company) {
        this->company = company;
    }

    string getCompany() {
        return company;
    }

    void setCategory(char category) {
        this->category = category;
    }

    char getCategory() {
        return category;
    }

    void setAge(int age) {
        this->age = age;
    }

    int getAge() {
        return age;
    }

    void setSeniority() {
        this->seniority = seniority;
    }

    int getSeniority() {
        return seniority;
    }

    void receivePayment() {
        cout << "Will receive salary in the bank account every two weeks\n";
    }

    virtual void work() {
        cout << "Working... Attending tasks, checking schedule..." << endl;
    }

    void checkOut() {
        cout << name << " just checked out" << endl;
    }
};

// Another Parent Class, also a child of the abstract class
class Professional : public AbstractWorker {
protected:
    string name;

private:
    string rfc;
    string profession;
    int age;
    int id;

    static int count;

public:
    Professional() {};

    Professional(string name, string profession, string rfc, int age, int id) {
        this->name = name;
        this->profession = profession;
        this->rfc = rfc;
        this->age = age;
        this->id = id;
        instanceCounter();
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        name = name;
    }

    string getRfc() {
        return rfc;
    }

    void setRfc(string rfc) {
        this->rfc = rfc;
    }

    int getId() {
        return id;
    }

    void setId(int id) {
        this->id = id;
    }

    void receivePayment() {
        cout << "Will receive payment for fees" << endl;
    }

    void reportToSAT() {
        cout << "The professional will file taxes to the IRS" << endl;
    }

    void showRfc() {
        cout << "The RFC of " << name << " is: " << getRfc() << endl;
    }

    static int instanceCounter() {
        count++;
        return count;
    }
};

// New Parent Class (just for multiple inheritance demonstration)
class Scientist {
protected:
    string academy;
    string degree;

public:
    Scientist(string academy, string degree) {
        this->academy = academy;
        this->degree = degree;
    }

    ~Scientist() {
        cout << "Destroying object... (Scientist Class)" << endl;
    }

    void conductExperiment() {
        cout << "Conducting experiment in the laboratory" << endl;
    }

    void introduce() {
        cout << "Degree: " << degree << endl << "Academy: " << academy << endl;
    }
};

// --------------- CHILD CLASSES ------------------------------------
// Child Class of Employee
class MechatronicsEngineer : public Employee {
public:
    string favoriteLanguage;
    string favoriteController;

    MechatronicsEngineer(string name, string company, char category, int age, int seniority, string favoriteLanguage, string favoriteController)
        : Employee(name, company, category, age, seniority) {
        this->favoriteLanguage = favoriteLanguage;
        this->favoriteController = favoriteController;
    }

    string getFavoriteLanguage() {
        return favoriteLanguage;
    }

    void setFavoriteLanguage(string favoriteLanguage) {
        this->favoriteLanguage = favoriteLanguage;
    }

    string getFavoriteController() {
        return favoriteController;
    }

    void setFavoriteController(string favoriteController) {
        this->favoriteController = favoriteController;
    }

    void programMicros() {
        cout << name << " engineers micros in " << favoriteLanguage << endl;
    }

    void buildPrototypes() {
        cout << name << " is creating a prototype for a " << favoriteController << " controller" << endl;
    }

    void work() {
        cout << name << " is working with PLC" << endl;
    }
};

// Another Child Class of Employee
class BioelectronicsEngineer : public Employee {
public:
    string favoriteDesign;
    string favoriteMicro;

    BioelectronicsEngineer(string name, string company, char category, int age, int seniority, string favoriteDesign, string favoriteMicro)
        : Employee(name, company, category, age, seniority) {
        this->favoriteDesign = favoriteDesign;
        this->favoriteMicro = favoriteMicro;
    }

    string getFavoriteDesign() {
        return favoriteDesign;
    }

    void setFavoriteDesign(string favoriteDesign) {
        this->favoriteDesign = favoriteDesign;
    }

    string getFavoriteMicro() {
        return favoriteMicro;
    }

    void setFavoriteMicro(string favoriteMicro) {
        this->favoriteMicro = favoriteMicro;
    }

    void design() {
        cout << name << " designs in " << favoriteDesign << endl;
    }

    void burnFavoriteMicro() {
        cout << name << " burned the microcontroller " << favoriteMicro << endl;
    }

    void work() {
        cout << name << " is designing bioinstrumentation circuits" << endl;
    }
};

// Child Class of Professional
class Teacher : public Professional {
public:
    string subject;
    string degree;

    Teacher(string name, string profession, string rfc, int age, int id, string subject, string degree)
        : Professional(name, profession, rfc, age, id) {
        this->subject = subject;
        this->degree = degree;
    }

    string getSubject() {
        return subject;
    }

    void setSubject(string subject) {
        this->subject = subject;
    }

    string getDegree() {
        return degree;
    }

    void setDegree(string degree) {
        this->
