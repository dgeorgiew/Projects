#include "student.h"
#include <iostream>

Student::Student(string studentName) {
    name = studentName;
}

void Student::addCourse(string courseName, int creditHours, char grade) {
    Course newCourse(courseName, creditHours, grade);
    courses.push_back(newCourse);
}

void Student::displayCourses() const {
    cout << "Student: " << name << "\nCourses:\n";
    for (const Course& course : courses) {
        cout << course.getName() << " (" << course.getCreditHours()
             << " credits) - Grade: " << course.getGrade() << endl;
    }
}

string Student::getName() const {
    return name;
}

double Student::calculateGPA() const {
    double totalGradePoints = 0.0;
    int totalCredits = 0;

    for (const Course& course : courses) {
        totalGradePoints += course.getGradePoint() * course.getCreditHours();
        totalCredits += course.getCreditHours();
    }

    if (totalCredits == 0) return 0.0;

    return totalGradePoints / totalCredits;
}
