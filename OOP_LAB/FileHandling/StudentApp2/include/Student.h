#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
private:
    string name;
    string reg;
    float CGPA;
    int ID;

public:
    Student();
    void setProfile();
    void displayProfile() const;
    int getID() const;
    void setCGPA(float newCGPA);

    friend void modifyData(int id); // friend function to access private members
};
void modifyData(int id);

#endif
