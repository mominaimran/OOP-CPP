#include <iostream>
using namespace std;
// Function template
template <typename T>
T findLargest(T a, T b) {
    return (a > b) ? a : b;
}
int main() {
    // Testing with int
    int i1 = 10, i2 = 20;
    cout << "Largest integer: " << findLargest(i1, i2) << endl;
    // Testing with float
    float f1 = 4.5, f2 = 9.7;
    cout << "Largest float: " << findLargest(f1, f2) << endl;
    // Testing with char
    char c1 = 'a', c2 = 'z';
    cout << "Largest character: " << findLargest(c1, c2) << endl;
    return 0;
}
