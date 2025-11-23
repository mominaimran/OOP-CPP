#include <iostream>
using namespace std;

template <typename T>
void largest(T a, T b){
    T large = a>b?a:b;
    cout << "Largest: " << large << endl;
}

int main() {
    largest(2,4);
    return 0;
}