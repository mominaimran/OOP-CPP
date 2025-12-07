#ifndef DOCTOR_H
#define DOCTOR_H
#include <string>
using namespace std;

class Doctor {
protected:
    string name;
    int age;
public:
    Doctor();
    string getName();
    int getAge();
    void getData();
    void showData();
};

#endif
