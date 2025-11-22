#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    try{
        if(b==0){
            throw "cannot divide by zero...";
        }
        cout << "a/b = " << a/b << endl;
    }catch(const char* msg){
        cout << "Error: " << msg << endl;
    }

    return 0;
}