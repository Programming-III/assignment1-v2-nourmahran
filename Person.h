#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;
#include <iostream>

class Person {
private:
    string name;
    int id;
public:
    Person();
    Person(string n, int i);
    ~Person();

    void setName(string n);
    void setId(int i);
    string getName();
    int getId();

    virtual void display();
};

#endif














