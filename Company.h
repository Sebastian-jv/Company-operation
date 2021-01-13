
#ifndef ZADANIE_FIRMA_COMPANY_H
#define ZADANIE_FIRMA_COMPANY_H
#include <iostream>
using std::string;

class Employee{
protected:
    string name;
    string surName;
    string position;
    double salary;
    bool inWork;
public:
    virtual void whoAmI() = 0;
};


class Tester :protected Employee{
public:
    Tester(string n="imie Testera" ,string s="nazwisko Testera",double sal=2300,bool inWork=false);
    void whoAmI() override;
    void setInWork(bool status);
    bool getInWork();
    ~Tester();
};

class Programmer: protected Employee{
public:
    Programmer(string n="imie programisty" ,string s="nazwisko programisty",
               double sal=3500,bool inWork=false);
    void whoAmI() override;
    void setInWork(bool status);
    bool getInWork();
    ~Programmer();
};

class Company;

class Manager: protected Employee{

public:
    Manager(string n="imie managera" ,string s="nazwisko managera",double sal=5000,bool inWork=false);
    void whoAmI() override;
    void setInWork(bool status);
    bool getInWork();
    Company* startCompany(string nameComp="nazwa firmy");

    //add;return (-1)-brak wsk pracownika/firma,0-poprawnie,1-brak miejsca w firmie,2-niepoprwany manager,
    int addEmlpoyeeInComp(Programmer *objProgrammer,Company *obj);
    int addEmlpoyeeInComp(Tester *objTester,Company *obj);

    //del;return (-1)-brak wsk pracownika/firma,0-poprawnie,1-brak takiego pracownika,2-niepoprwany manager,
    int delEmployeeInComp(Tester *objTester,Company *obj);
    int delEmployeeInComp(Programmer *objProgrammer,Company *obj);
    bool closeCompany(Company *obj);

    void showError(int x,string typeMet);
    ~Manager();
};

class Company {
    friend class Manager;
private:
    string nameCompany;
    bool companyON = false;
    int howManyTester=0;
    int howManyProgrammer=0;
    int howManyManager=0;

    Tester* objTester;
    Programmer* objProgrammer;
    Manager* objManager;

protected:
    int addEmployee(Tester *objTester);
    int addEmployee(Programmer *objProgrammer);
    int delEmployee(Tester *objTester);
    int delEmployee(Programmer *objProgrammer);

public:
    Company(string nameC = "domyslna nazwa", Manager *obj= nullptr);
    string getNameCompany();
    bool getStatus();
    int getHowManyTester();
    int getHowManyManager();
    int getHowManyProgrammer();

    ~Company();

};





#endif //ZADANIE_FIRMA_COMPANY_H
