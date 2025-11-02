#include <iostream>
#include "Student.h"
#include "Result.h"
using namespace std;

int main() {
    Student s1("Momina", 123, 3.8, 'A');  // Result ka parameterized constructor call hoga
    s1.displayStudent();

    Result r2(3.5, 'A');
    Student s2("Zoon", 456, r2);  // CGPA=0, Grade='F' (defaults)
    s2.displayStudent();

    return 0;
}