#include <iostream>
using namespace std;

void show(int a){
    cout << a << endl;
}
template <typename T, typename U>
void show(T a, U b){
    cout << a << b << endl;
}

int main() {
    show(1);
    show("Momina", 04);

    return 0;
}