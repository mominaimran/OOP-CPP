#include <iostream>
using namespace std;

template <typename T>
T compare(T a, T b, T c) {
    if (a >= b && a >= c) return a;
    else if (b >= a && b >= c) return b;
    else return c;
}

int main() {
    int ans = compare(2, 10, 6);
    cout << "Largest: " << ans << endl;

    double ans2 = compare(2.5, 3.7, 1.2);
    cout << "Largest: " << ans2 << endl;

    char ans3 = compare('A', 'X', 'M');
    cout << "Largest: " << ans3 << endl;

    return 0;
}
