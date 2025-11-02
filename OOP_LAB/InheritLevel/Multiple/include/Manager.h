#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"
#include "Student.h"
#include <string>
using namespace std;

class Manager : public Employee, public Student {
    string department;
public:
    Manager(int id=0, int s=0, int r=0, float c=0.0, string d="N/A");
    void getData();
    void showData();
};

#endif
