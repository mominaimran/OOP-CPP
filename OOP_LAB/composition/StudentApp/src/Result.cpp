#include "Result.h"

Result::Result(int c, char g){
    CGPA = c;
    grade = g;
}

void Result::displayResult(){
    cout << "CGPA: " << CGPA << ", Grade: " << grade << endl;
}