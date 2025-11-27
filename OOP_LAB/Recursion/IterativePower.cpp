#include <iostream>
using namespace std;

int power(int a, int b) {
    int result = 1; 
    for (int i = 1; i <= b; i++) {
        result *= a;          
    }
    return result;
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

// Iterative = fast, memory-efficient, straightforward
// Recursive = elegant, simple to model, closer to problem logic, sometimes unavoidable (trees, graphs, DFS, combinatorics)