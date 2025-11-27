#include <iostream>
using namespace std;

int factorial(int n) {
    int result = 1;              // Start from 1 because 0! = 1
    for (int i = 1; i <= n; i++) {
        result *= i;             // Multiply result by i for each i
    }
    return result;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if(n < 0) {
        cout << "Factorial not defined for negative numbers." << endl;
    } else {
        cout << "Factorial of " << n << " is " << factorial(n) << endl;
    }

    return 0;
}
