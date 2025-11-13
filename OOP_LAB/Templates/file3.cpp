#include <iostream>
#include <cctype>
using namespace std;

template <typename T>
T toUpperCase(T character){
    T upper = toupper(character);
    return upper;
}

int main() {
    char c;
    cout << "Enter a character: ";
    cin >> c;

    cout << toUpperCase(c) << endl;

    return 0;
}