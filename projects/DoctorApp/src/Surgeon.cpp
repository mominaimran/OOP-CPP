#include "Surgeon.h"
#include "ColorUtils.h"
#include <limits>
#include <cstring>
// ✅ Constructor
Surgeon::Surgeon() {
    id = 0;
    age = 0;
    salary = 0;
    memset(name, 0, sizeof(name));
    memset(specialization, 0, sizeof(specialization));
}
// ✅ Getters
int Surgeon::getId() const { return id; }
string Surgeon::getName() const { return name; }
int Surgeon::getAge() const { return age; }
string Surgeon::getSpec() const { return specialization; }
int Surgeon::getSalary() const { return salary; }
// ✅ Get data from user
void Surgeon::getData(int newId) {
    id = newId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear buffer
    cout << "\nEnter name: ";
    cin.getline(name, 50);
    cout << YELLOW << "Enter age: " << RESET;
    cin >> age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << YELLOW << "Enter specialization: " << RESET;
    cin.getline(specialization, 50);
    cout << "Enter salary: ";
    cin >> salary;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
// ✅ Display record
void Surgeon::showData() const {
    cout << left << setw(5) << id
         << setw(20) << name
         << setw(10) << age
         << setw(20) << specialization
         << setw(10) << salary << endl;
}
// ✅ Modify only salary
void Surgeon::modifyData() {
    cout << "Enter new salary: ";
    cin >> salary;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
// ✅ Get last used ID
int getLastID() {
    ifstream fin("surgeons.dat", ios::binary);
    if (!fin) return 0;
    Surgeon s;
    int lastId = 0;
    while (fin.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        lastId = s.getId();
    }
    fin.close();
    return lastId;
}
// ✅ Add surgeon
void addSurgeon() {
    ofstream fout("surgeons.dat", ios::binary | ios::app);
    if (!fout) {
        cout << "Error opening file.\n";
        return;
    }
    Surgeon s;
    int idCounter = getLastID() + 1;
    char choice;
    do {
        s.getData(idCounter++);
        fout.write(reinterpret_cast<char*>(&s), sizeof(s));
        cout << "\nDo you want to enter another surgeon's data? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    fout.close();
}
// ✅ Display all surgeons
void displayAll() {
    ifstream fin("surgeons.dat", ios::binary);
    if (!fin) {
        cout << "No records found.\n";
        return;
    }
    Surgeon s;
    cout << CYAN << "\n\n" << left
         << setw(5) << "ID"
         << setw(20) << "Name"
         << setw(10) << "Age"
         << setw(20) << "Specialization"
         << setw(10) << "Salary" << endl;
    cout << "--------------------------------------------------------------\n" << RESET;
    while (fin.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        s.showData();
    }

    fin.close();
}
// ✅ Modify surgeon record
void modifyRecord() {
    fstream file("surgeons.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        cout << "File not found.\n";
        return;
    }
    int targetId;
    cout << GREEN << "\nEnter the ID of surgeon you want to modify: " << RESET;
    cin >> targetId;
    Surgeon s;
    bool found = false;
    while (file.read(reinterpret_cast<char*>(&s), sizeof(s))) {
        if (s.getId() == targetId) {
            cout << "\nOld record:\n";
            s.showData();

            cout << "\nEnter new details:\n";
            s.modifyData();

            file.seekp(-static_cast<int>(sizeof(s)), ios::cur);
            file.write(reinterpret_cast<char*>(&s), sizeof(s));

            cout << BLUE << "\nRecord updated successfully!\n" << RESET;
            found = true;
            break;
        }
    }
    if (!found)
        cout << RED << "\nRecord not found!\n" << RESET;

    file.close();
}
// ✅ Copy file
void copyFile() {
    ifstream source("surgeons.dat", ios::binary);
    if (!source) {
        cout << "Source file not found!\n";
        return;
    }
    string newFileName;
    cout << "\nEnter name for new file (without extension): ";
    cin >> newFileName;
    newFileName += ".dat";
    ofstream dest(newFileName, ios::binary);
    if (!dest) {
        cout << "Error creating new file!\n";
        return;
    }
    dest << source.rdbuf();
    cout << BLUE << "\nFile copied successfully into '" << newFileName << "'\n" << RESET;
    source.close();
    dest.close();
}
