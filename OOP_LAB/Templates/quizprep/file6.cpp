#include <iostream>
using namespace std;

template <typename T, typename U>
void myFunc(T x, U y){
    cout << x << " " << y << endl;
} 

int main() {
    myFunc("Momina", 5889);

    return 0;
}