#include <iostream>
#include "Person.h"
#include "Teacher.h"
using namespace std;
int main()
{
    cout<<endl<<"Obiekty klasy Person"<<endl;

    Person o1("Grazyna","Nowak",45);
    o1.showInfoPerson();
    cout<<"Czy pelnoletnia?: "<<o1.is_18()<<endl;
    o1.setAge(16);

    cout<<endl<<"Obiekty klasy Teacher"<<endl;
    Teacher n1("Barbara","Kowalska",56,30,"Phd");
    n1.showInfoTeacher();
    cout<<"Czy ma Phd?: "<<n1.is_Phd()<<endl;
    n1.setAge(34);


    Person p1[3]; // Statyczna tablica statycznych obiektów
    Person* p2; // Wskaźnik do dynamicznej tablicy statycznych obiektów (po alokacji)
    Person* p3[3]; // Statyczna tablica wskaźników do dynamicznych obiektów (obiekty muszą być utworzone)
    Person** p4; // Wskaźnik do dynamicznej tablicy dynamicznych obiektów (po alokacji)


    //statyczna tablica statycznych obiektów. W momencie deklaracji
    //tablicy został wywołany konstrukt bezargumentowy, więc dla tych obiektów
    //wywoływana jest metoda init;
    for(int i=0; i<3; i++)
    {
        p1[i].init("Anna","Nowak",20+i);
        p1[i].showInfoPerson();
    }

    //dynamiczna tablica statycznych obiektów. Długość tablicy
    //określona za pomocą operatora new. W momencie przydzielenia pamięci wywołał
    //się konstruktor bezargumentowy, więc dla tych obiektów wywoływana została
    //metoda init;
    p2=new Person[3];
    for(int i=0; i<3; i++)
    {
        p2[i].init("Ola","Adamek",20+i);
        p2[i].showInfoPerson();
    }

    //statyczna tablica dynamicznych obiektów. Obiekt tworzony jest za
    //pomocą operatora new i w tym momencie wywoływany jest konstruktor
    //parametrowy;
    for(int i=0; i<3; i++)
    {
        p3[i]=new Person("Kasia","Kowalska",20+i);
        p3[i]->showInfoPerson();
    }

    //dynamiczna tablica dynamicznych obiektów. Długość tablicy jest
    //określona za pomocą operatora new. Obiekt tworzony jest za pomocą operatora new
    //i w tym momencie wywoływany jest konstruktor parametrowy
    p4=new Person*[3];
    for(int i=0; i<3; i++)
    {
        p4[i]=new Person("Pawel","Wojcik",20+i);
        p4[i]->showInfoPerson();
    }

    //----------------

    //zwolnienie pamięci przydzielonej dla każdego obiektu;

    for(int i=0;i<3;i++){
        delete p3[i];
    }

    // zwolnienie pamięci przydzielonej dla każdego obiektu a następnie
    //dla tablicy.
    for(int i=0;i<3;i++){
        delete p4[i];
    }
    delete [] p4;

    return 0;
}
