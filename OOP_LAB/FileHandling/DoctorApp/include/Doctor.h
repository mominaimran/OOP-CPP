#ifndef DOCTOR_H
#define DOCTOR_H

#include <string>
#include <iostream>
using namespace std;

class Doctor {
private:
    int id;
    string name;

public:
    Doctor(int i = 0, string n = "unknown");
    int getId();
    void setData();
    void showData();
};

#endif
