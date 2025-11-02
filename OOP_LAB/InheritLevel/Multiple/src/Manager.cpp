#include "Manager.h"

Manager::Manager(int id, int s, int r, float c, string d): Employee(id, s), Student(r, c) {
    department = d;
}

void Manager::getData() {
    getEmployeeData();
    getStudentData();
    cout << "Enter Department: ";
    cin >> department;
}

void Manager::showData() {
    cout << "\n--- Manager Details ---" << endl;
    showEmployeeData();
    showStudentData();
    cout << "Department: " << department << endl;
}
