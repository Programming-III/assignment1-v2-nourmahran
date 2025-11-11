#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Instructor.h"
#include "Course.h"
using namespace std;

Person::Person() {}
Person::Person(string n, int i) { name = n; id = i; }
Person::~Person() {}
void Person::setName(string n) { name = n; }
void Person::setId(int i) { id = i; }
string Person::getName() { return name; }
int Person::getId() { return id; }
void Person::display() { cout << "Name: " << name << " (ID: " << id << ")" << endl; }

Student::Student() {}
Student::Student(string n, int i, int y, string m) : Person(n, i) { yearLevel = y; major = m; }
Student::~Student() {}
void Student::setYearLevel(int y) { yearLevel = y; }
void Student::setMajor(string m) { major = m; }
int Student::getYearLevel() { return yearLevel; }
string Student::getMajor() { return major; }
void Student::display() {
    cout << "Student Info:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Year: " << yearLevel << endl;
    cout << "Major: " << major << endl;
}

Instructor::Instructor() {}
Instructor::Instructor(string n, int i, string d, int e) : Person(n, i) {
    department = d;
    experienceYears = e;
}
Instructor::~Instructor() {}
void Instructor::setDepartment(string d) { department = d; }
void Instructor::setExperienceYears(int e) { experienceYears = e; }
string Instructor::getDepartment() { return department; }
int Instructor::getExperienceYears() { return experienceYears; }
void Instructor::display() {
    cout << "Instructor Info:" << endl;
    cout << "Name: " << getName() << endl;
    cout << "Department: " << department << endl;
    cout << "Experience: " << experienceYears << " years" << endl;
}

Course::Course() {
    students = nullptr;
    maxStudents = 0;
    currentStudents = 0;
}
Course::Course(string code, string name, int max, Instructor inst) {
    courseCode = code;
    courseName = name;
    maxStudents = max;
    instructor = inst;
    currentStudents = 0;
    students = new Student[maxStudents];
}
Course::~Course() { delete[] students; }
void Course::setCourseCode(string code) { courseCode = code; }
void Course::setCourseName(string name) { courseName = name; }
void Course::setMaxStudents(int max) { maxStudents = max; }
void Course::setInstructor(Instructor inst) { instructor = inst; }
string Course::getCourseCode() { return courseCode; }
string Course::getCourseName() { return courseName; }
int Course::getMaxStudents() { return maxStudents; }
int Course::getCurrentStudents() { return currentStudents; }
void Course::addStudent(const Student& s) {
    if (currentStudents < maxStudents) {
        students[currentStudents] = s;
        currentStudents++;
    } else {
        cout << "Course is full!" << endl;
    }
}
void Course::displayCourseInfo() {
    cout << "Course: " << courseCode << " - " << courseName << endl;
    cout << "Max Students: " << maxStudents << endl;
    cout << "Currently Enrolled: ";
    for (int i = 0; i < currentStudents; i++) {
        cout << students[i].getName() << " (ID: " << students[i].getId() << ")";
        if (i != currentStudents - 1) cout << ", ";
    }
    cout << endl << endl;
    instructor.display();
    cout << endl;
    for (int i = 0; i < currentStudents; i++) {
        students[i].display();
        cout << endl;
    }
}

int main() {
    Instructor inst("Dr. Lina Khaled", 1001, "Computer Science", 5);
    Student s1("Omar Nabil", 2202, 2, "Informatics");
    Course c("CS101", "Introduction to Programming", 3, inst);
    c.addStudent(s1);
    c.displayCourseInfo();
    return 0;
}
