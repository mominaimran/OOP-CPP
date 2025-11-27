#include <iostream>
using namespace std;

int power(int a, int b){
    //base case
    if(b==0)
    return 1;
    //recursion case
    return a*power(a, b-1);
}

int main() {
    int a, b;
    cout << "Enter base: ";
    cin >> a;
    cout << "Enter exponent: ";
    cin >> b;

    cout << a << " raised to the power " << b << " is " << power(a, b) << endl;

    return 0;
}