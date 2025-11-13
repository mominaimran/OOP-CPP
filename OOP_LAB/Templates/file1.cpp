#include <iostream>
using namespace std;

template <typename Tx, typename Ty>
void add(Tx a, Ty b){
    cout << a+b << endl;
}

int main() {
    add(2, 2.2);
    add(2.5, 2);

    return 0;
}