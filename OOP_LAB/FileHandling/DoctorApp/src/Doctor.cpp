#include "Doctor.h"

Doctor::Doctor(int i, string n) {
    id = i;
    name = n;
}

int Doctor::getId() {
    return id;
}

void Doctor::setData() {
    cout << "Enter Id: ";
    cin >> id;
    cin.ignore();
    cout << "Enter name: ";
    getline(cin, name);
}

void Doctor::showData() {
    cout << "ID: " << id << ", Name: " << name << endl;
}
