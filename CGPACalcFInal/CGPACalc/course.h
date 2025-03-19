#ifndef COURSE_H
#define COURSE_H

#include <string>
using namespace std;

class Course {
private:
    string name;
    int creditHours;
    char grade;

public:
    Course(string courseName, int credits, char courseGrade);
    string getName() const;
    int getCreditHours() const;
    char getGrade() const;
    double getGradePoint() const;
};


#endif // COURSE_H
