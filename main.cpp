#include <iostream>
#include "Company.h"

int main() {
    //Tworzenie managera
    Manager *managerObj = new Manager("Piotr","Nowak",5500);
    if(managerObj == nullptr){
        std::cout<<"Bład alokacji pamieci ";
        return 1;
    }
    managerObj->whoAmI();

    //Tworzenie firmy
    Company *companyObj = managerObj->startCompany("Firma LOOK");
    if(companyObj == nullptr){
        std::cout<<"Bład alokacji pamieci ";
        delete managerObj;
        return 1;
    }

    std::cout<<"Firma pracuje: "<<std::boolalpha<<companyObj->getStatus()<<std::endl;
    std::cout<<"Nazwa firmy: "<<companyObj->getNameCompany()  <<std::endl;
    std::cout<<"Ilu managerow pracuje: "<<companyObj->getHowManyManager()<<std::endl;


    //Tworzenie pracownikow
    Tester *testerObj = new Tester("Marek","Jurek",3300);
    if(testerObj == nullptr){
        std::cout<<"Bład alokacji pamieci ";
        managerObj->closeCompany(companyObj);
        delete managerObj;
        return 1;
    }
    Programmer *programmerObj = new Programmer("Adam","Kowalski",6700);
    if(programmerObj== nullptr){
        std::cout<<"Bład alokacji pamieci ";
        delete testerObj;
        managerObj->closeCompany(companyObj);
        delete managerObj;
        return 1;
    }

    //Przedstawienie pracownikow
    testerObj->whoAmI();
    programmerObj->whoAmI();
    std::cout<<"Programista pracuje: "<<std::boolalpha<<programmerObj->getInWork()<<std::endl;
    std::cout<<"Tester pracuje: "<<std::boolalpha<<testerObj->getInWork()<<std::endl;
    std::cout<<std::endl;

    //Stan firmy
    std::cout<<"Ilosc manager: "<<std::boolalpha<<companyObj->getHowManyManager()<<std::endl;
    std::cout<<"Ilosc testerow: "<<std::boolalpha<<companyObj->getHowManyTester()<<std::endl;
    std::cout<<"Ilosc programmer: "<<std::boolalpha<<companyObj->getHowManyProgrammer()<<std::endl;
    std::cout<<std::endl;

    //Pracownicy ida do pracy
    int metAnswer;
    metAnswer = managerObj->addEmlpoyeeInComp(programmerObj,companyObj);
    managerObj->showError(metAnswer,"add");

    metAnswer = managerObj->addEmlpoyeeInComp(testerObj,companyObj);
    managerObj->showError(metAnswer,"add");

    //Sprawdzenie statusu po zmianie
    std::cout<<"Programista pracuje: "<<std::boolalpha<<programmerObj->getInWork()<<std::endl;
    std::cout<<"Tester pracuje: "<<std::boolalpha<<testerObj->getInWork()<<std::endl;
    std::cout<<std::endl;

    //Stan firmy
    std::cout<<"Ilosc manager: "<<std::boolalpha<<companyObj->getHowManyManager()<<std::endl;
    std::cout<<"Ilosc testerow: "<<std::boolalpha<<companyObj->getHowManyTester()<<std::endl;
    std::cout<<"Ilosc programmer: "<<std::boolalpha<<companyObj->getHowManyProgrammer()<<std::endl;
    std::cout<<std::endl;

    //Próba zamkniecia firmy
    if(!managerObj->closeCompany(companyObj))
        std::cout<<"Nie mozna zamknac firmy.Nadal znajduja sie w niej pracownicy!"<<std::endl;
    std::cout<<std::endl;

    //Wyjscie pracownikow z pracy
    metAnswer = managerObj->delEmployeeInComp(programmerObj,companyObj);
    managerObj->showError(metAnswer,"del");

    metAnswer = managerObj->delEmployeeInComp(testerObj,companyObj);
    managerObj->showError(metAnswer,"del");

    std::cout<<std::endl;

    //Stan firmy
    std::cout<<"Ilosc manager: "<<std::boolalpha<<companyObj->getHowManyManager()<<std::endl;
    std::cout<<"Ilosc testerow: "<<std::boolalpha<<companyObj->getHowManyTester()<<std::endl;
    std::cout<<"Ilosc programistow: "<<std::boolalpha<<companyObj->getHowManyProgrammer()<<"\n"<<std::endl;

    delete testerObj;
    delete programmerObj;
    delete companyObj;
    delete managerObj;
    return 0;
}
