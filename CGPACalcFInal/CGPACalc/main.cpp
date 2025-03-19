#include <iostream>
#include "student.h"
#include "course.h"

using namespace std;

int main() {
    string studentName;
    int numCourses;

    // Въвеждаме името на студента
    cout << "Enter student name: ";
    getline(cin, studentName);

    // Създаване на обект на студент
    Student student(studentName);

    // Въвеждаме броя на курсовете
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    // Въвеждаме данни за всеки курс
    for (int i = 0; i < numCourses; i++) {
        string courseName;
        int creditHours;
        char grade;

        cout << "\nEnter details for Course " << i + 1 << ":\n";
        cout << "Course Name: ";
        cin.ignore(); // Изчистваме буфера
        getline(cin, courseName);
        cout << "Credit Hours: ";
        cin >> creditHours;
        cout << "Letter Grade (A, B, C, etc.): ";
        cin >> grade;

        student.addCourse(courseName, creditHours, grade);
    }

    // Извеждаме информация за курсовете
    cout << "\nCourses for " << student.getName() << ":\n";
    student.displayCourses();

    // Изчисляваме и извеждаме GPA
    cout << "\nSemester GPA: " << student.calculateGPA() << endl;

    return 0;
}

