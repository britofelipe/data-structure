#include <iostream>
#include<string.h>

using namespace std;

class Animal{
    public:
        int id;
        char name[50];
};

class Person{
    public:
        int id;
        char name[50];
        Animal* pet;
        Person* mother;
};

int main(){
    Person person;

    person.id = 70;
    strcpy(person.name, "John Smith");

    cout << "Id: " << person.id << endl;
    cout << "Name: " << person.name << endl;
    cout << "Address of 'person': " << &person << endl;

    Person* gen;
    gen = &person;

    cout << "Id: " << (*gen).id << endl;
    cout << "Name: " << (*gen).name << endl;
    cout << "Address of 'person': " << gen << endl;

    cout << "Id: " << gen->id << endl;
    cout << "Name: " << gen->name << endl;
    cout << "Address of 'person': " << gen << endl;

    person.pet = new Animal; //note that person.pet is a pointer
    (*person.pet).id = 10;
    cout << "Pet id: " << (*person.pet).id << endl;

    (person.pet)->id = 11;
    cout << "Pet id: " << (person.pet)->id << endl;

    person.mother = new Person;
    (person.mother)->mother = new Person;


}