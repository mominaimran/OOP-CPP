#include "Student.h"
#include "Teacher.h"
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    Student s1;
    Teacher t1("Dr.Aasma", 40, 123456, "OOP", 100000);
    
    s1.setStudent("Momina", 22, 123456, 5889, 4);
    
    cout << "Student Details:\n";
    s1.showDetails();
    cout << "---------------------" << endl;
    cout << "Teacher Details:\n";
    t1.showDetails();

    // Writing to file (binary)
    ofstream outFile("Student.dat", ios::binary);
    if (!outFile) {
        cout << "Error opening file for writing!\n";
        return 1;
    }
    outFile.write(reinterpret_cast<char*>(&s1), sizeof(s1));
    outFile.close();
    cout << "Data written to file successfully!" << endl;

    // Reading from file (binary)
    ifstream inFile("Student.dat", ios::binary);
    if (!inFile) {
        cout << "Error opening file for reading!\n";
        return 1;
    }

    Student temp;
    while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(temp))) {
        cout << "\nData read from file:\n";
        temp.showDetails();
    }

    inFile.close();
    cout << "Data read from file successfully!" << endl;

    return 0;
}
