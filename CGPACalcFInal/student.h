#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include "course.h"
using namespace std;

class Student {
private:
    string name;
    vector<Course> courses;
public:
    Student(string studentName);
    void addCourse(string courseName, int creditHours, char grade);
    void displayCourses() const;
    string getName() const;
    double calculateGPA() const;
};


#endif // STUDENT_H
