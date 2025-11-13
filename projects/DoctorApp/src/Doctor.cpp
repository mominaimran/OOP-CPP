#include "Doctor.h"
#include <iostream>
#include <limits>
using namespace std;

Doctor::Doctor() {
    name = "N/A";
    age = 0;
}

void Doctor::getData() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover newline
    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void Doctor::showData() {
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}

string Doctor::getName() { return name; }
int Doctor::getAge() { return age; }


