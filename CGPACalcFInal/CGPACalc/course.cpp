#include "course.h"

Course::Course(string courseName, int credits, char courseGrade) {
    name = courseName;
    creditHours = credits;
    grade = courseGrade;
}

string Course::getName() const { return name; }
int Course::getCreditHours() const { return creditHours; }
char Course::getGrade() const { return grade; }

double Course::getGradePoint() const {
    switch (grade) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return 0.0;
    }
}
