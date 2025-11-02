#ifndef STU_H
#define STU_H

#include "Result.h"
#include <iostream>
#include <string>
using namespace std;

class Student{
    private:
        string name;
        int regNo;
        Result result;
    public:
        Student(string n, int r, Result res);
        void displayStudent();
};

#endif