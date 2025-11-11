#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Student.h"
#include "Instructor.h"
using namespace std;

class Course {
private:
    string courseCode;
    string courseName;
    int maxStudents;
    Student* students;
    int currentStudents;
    Instructor instructor;
public:
    Course();
    Course(string code, string name, int max, Instructor inst);
    ~Course();

    void setCourseCode(string code);
    void setCourseName(string name);
    void setMaxStudents(int max);
    void setInstructor(Instructor inst);

    string getCourseCode();
    string getCourseName();
    int getMaxStudents();
    int getCurrentStudents();

    void addStudent(const Student& s);
    void displayCourseInfo();
};

#endif
