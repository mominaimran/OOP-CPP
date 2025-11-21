#ifndef SURGEON_H
#define SURGEON_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
class Surgeon {
private:
    int id;
    char name[50];
    int age;
    char specialization[50];
    int salary;
public:
    Surgeon();
    int getId() const;
    string getName() const;
    int getAge() const;
    string getSpec() const;
    int getSalary() const;

    void getData(int newId);
    void showData() const;
    void modifyData();
};

int getLastID();
void addSurgeon();
void displayAll();
void modifyRecord();
void copyFile();
#endif
