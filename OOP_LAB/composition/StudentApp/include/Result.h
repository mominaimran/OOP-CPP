#ifndef RES_H
#define RES_H

#include <iostream>
using namespace std;

class Result{
    private:
        int CGPA;
        char grade;
    public:
        Result(int c = 0, char g = 'F');
        void displayResult();
};

#endif