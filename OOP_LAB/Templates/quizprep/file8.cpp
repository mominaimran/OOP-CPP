#include <iostream>
#include <string>
using namespace std;

// General template
template <typename T>
void show(T x) {
    cout << "General template: " << x << endl;
}

// Specialization for string
template <>
void show<string>(string x) {
    cout << "Specialized template for string: " << x << endl;
}

int main() {
    show(10);          // General template
    show(3.14);        // General template
    show("Hello");     // Specialized template
    show(string("Momina")); // Specialized template

    return 0;
}
