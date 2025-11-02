#include "Doctor.h"
#include "Surgeon.h"
#include <iostream>
using namespace std;

Surgeon::Surgeon(string n, int a, string s, int sal):Doctor(n,a){
    spec = s;
    salary = sal;
}

// input (extraction)
istream& operator>>(istream& in, Surgeon& s) {
    // call Doctor's version first
    in >> static_cast<Doctor&>(s);
    in.ignore();
    cout << "Enter specialization: ";
    getline(in, s.spec);
    cout << "Enter salary: ";
    in >> s.salary;
    in.ignore();
    return in;
}

// output (insertion)
ostream& operator<<(ostream& out, const Surgeon& s) {
    // call Doctor's version using static_cast
    out << static_cast<const Doctor&>(s);
    out << "Specialization: " << s.spec << endl;
    out << "Salary: " << s.salary << endl;
    return out;
}