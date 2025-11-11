#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "Person.h"
using namespace std;

class Instructor : public Person {
private:
    string department;
    int experienceYears;
public:
    Instructor();
    Instructor(string n, int i, string d, int e);
    ~Instructor();

    void setDepartment(string d);
    void setExperienceYears(int e);
    string getDepartment();
    int getExperienceYears();

    void display() override;
};

#endif











#endif
