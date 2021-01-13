#include "Company.h"

// ********* Company ***************
string Company::getNameCompany() {
    return nameCompany;
}

Company::Company(string nameC, Manager *obj) {
    nameCompany = nameC;
    companyON = true;
    howManyManager=1;
    objManager = obj;
    objManager->setInWork(true);
}

bool Company::getStatus() {
    return companyON;
}

int Company::getHowManyTester() {
    return howManyTester;
}

int Company::getHowManyManager() {
    return howManyManager;
}

int Company::getHowManyProgrammer() {
    return howManyTester;
}

int Company::addEmployee(Tester *objTester) {
    if(objTester == nullptr)
        return -1;
    else if(howManyTester == 0){
        this->objTester = objTester;
        this->objTester->setInWork(true);
        howManyTester=1;
        return 0;
    }
    else
        return 1;
}

int Company::addEmployee(Programmer *objProgrammer) {
    if(objProgrammer == nullptr)
        return -1;
    if(howManyProgrammer == 0){
        this->objProgrammer = objProgrammer;
        this->objProgrammer->setInWork(true);
        howManyProgrammer=1;
        return 0;
    }
    else
        return 1;
}

int Company::delEmployee(Tester *objTester) {
    if(objTester == nullptr)
        return -1;
    if(this->objTester == objTester){
        howManyTester=0;
        return 0;
    }
    else
        return 1;   //jezeli nie wystepuje taki pracownik
}

int Company::delEmployee(Programmer *objProgrammer) {
    if(objProgrammer == nullptr)
        return -1;
    if(this->objProgrammer == objProgrammer){
        howManyProgrammer=0;
        return 0;
    }
    else
        return 1;       //jezeli nie wystepuje taki pracownik
}


Company::~Company() {
    std::cout<<"Firma \'"<< getNameCompany()<<"\' zamknieta."<<std::endl;
}


// ******** Tester **************
Tester::Tester(string n, string s, double sal, bool inWork) {
    name =  n;
    surName = s;
    position = "Tester";
    salary = sal;
    this->inWork = inWork;

}

void Tester::whoAmI() {
    std::cout<<position<<": "<< name<<", nazwisko: "<<surName<<std::endl;
    std::cout<<"Zarobki:"<< salary<<"zł "<<std::endl;
    std::cout<<"Zawod:"<<position<<std::endl;
    std::cout<<"\n";
}

Tester::~Tester() {
    std::cout<<"Tester "<< name<<" konczy prace."<<std::endl;
}

bool Tester::getInWork() {
    return inWork;
}

void Tester::setInWork(bool status) {
    inWork = status;
}

//********** Programista **************
Programmer::Programmer(string n, string s, double sal, bool inWork) {
    name =  n;
    surName = s;
    position = "Programista";
    salary = sal;
    this->inWork = inWork;
}

void Programmer::whoAmI() {
    std::cout<<position<<": "<< name<<", nazwisko: "<<surName<<std::endl;
    std::cout<<"Zarobki:"<< salary<<"zł "<<std::endl;
    std::cout<<"Zawod:"<<position<<std::endl;
    std::cout<<"\n";
}

bool Programmer::getInWork() {
    return inWork;
}

void Programmer::setInWork(bool status) {
    inWork = status;
}

Programmer::~Programmer() {
    std::cout<<"Programista "<< name<<" konczy prace."<<std::endl;
}


//*********** Manager ***********
Manager::Manager(string n, string s, double sal, bool inWork) {
    name =  n;
    surName = s;
    position = "Manager";
    salary = sal;
    this->inWork = inWork;
}

void Manager::whoAmI() {
    std::cout<<position<<": "<< name<<", nazwisko: "<<surName<<std::endl;
    std::cout<<"Zawod:"<<position<<std::endl;
    std::cout<<"\n";
}

void Manager::setInWork(bool status) {
    inWork = status;
}

bool Manager::getInWork() {
    return inWork;
}

Company* Manager::startCompany(string nameComp) {
    Company *objComp = new Company(nameComp,this);
    return objComp;
}

bool Manager::closeCompany(Company *obj) {
    if((obj->getHowManyTester()!=0) | (obj->getHowManyProgrammer()!=0))
        return false;
    else
        delete obj;
    return true;
}

int Manager::addEmlpoyeeInComp(Tester *objTester, Company *obj) {
    if(obj->objManager != this)
        return 2;
    else if(obj == nullptr)
        return -1;
    int answer = obj->addEmployee(objTester);
    return answer;
}

int Manager::addEmlpoyeeInComp(Programmer *objProgrammer, Company *obj) {
    if(obj->objManager != this)
        return 2;
    else if(obj == nullptr)
        return -1;
    bool answer = obj->addEmployee(objProgrammer);
    return answer;
}

int Manager::delEmployeeInComp(Tester *objTester, Company *obj) {
    if(obj->objManager != this)
        return 2;
    else if(obj == nullptr)
        return -1;
    int answer = obj->delEmployee(objTester);
    return answer;
}

int Manager::delEmployeeInComp(Programmer *objProgrammer, Company *obj) {
    if(obj->objManager != this)
        return 2;
    else if(obj == nullptr)
        return -1;
    int answer = obj->delEmployee(objProgrammer);
    return answer;
}

Manager::~Manager() {
    std::cout<<"Manager "<< name<<" konczy prace."<<std::endl;
}

void Manager::showError(int x, string typeMet) {
    switch(x){
        case -1:
            std::cout<<"Brak firmy/managera"<<std::endl;
            break;
        case 0:
            return;
        case 1:
            if(typeMet == "del")
                std::cout<<"Brak takiego pracownika w firmie"<<std::endl;
            else if(typeMet == "add")
                std::cout<<"Brak miejsca w firmie na danym stanowisku"<<std::endl;
            break;
        case 2:
            std::cout<<"Ten manager nie jest zarzadca firmy"<<std::endl;
            break;
    }
}
