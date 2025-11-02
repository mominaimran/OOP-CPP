#include "Student.h"
#include "Result.h"

Student::Student(string n, int r, Result res) : name(n), regNo(r), result(res) {}

void Student::displayStudent(){
    cout << "Name: " << name << ", Reg No: " << regNo << endl;
    result.displayResult();
}