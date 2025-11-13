#include "Student.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

Student::Student() {
    ID = 0;
    CGPA = 0;
}

void Student::setProfile() {
    cin.ignore(80, '\n');
    cout << "\nEnter student name: ";
    getline(cin, name);

    cout << "Enter registration number: ";
    getline(cin, reg);

    cout << "Enter CGPA: ";
    cin >> CGPA;
    ID++; // Increment ID for each object (simple auto ID)
    cin.ignore(80, '\n');
}

void Student::displayProfile() const {
    cout << setw(5) << ID 
         << setw(20) << name 
         << setw(10) << reg 
         << setw(5) << CGPA << endl;
}

int Student::getID() const {
    return ID;
}

void Student::setCGPA(float newCGPA) {
    CGPA = newCGPA;
}

void modifyData(int id) {
    fstream file("student.txt", ios::binary | ios::in | ios::out);
    if (!file) {
        cout << "File not found!\n";
        return;
    }

    Student s;
    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        long pos = file.tellg();
        if (s.getID() == id) {
            cout << "\nEnter new CGPA for student ID " << id << ": ";
            float newGPA;
            cin >> newGPA;
            s.setCGPA(newGPA);

            file.seekp(pos - sizeof(s));
            file.write(reinterpret_cast<char*>(&s), sizeof(s));
            cout << "\nRecord updated!\n";
            break;
        }
    }

    file.close();
}
