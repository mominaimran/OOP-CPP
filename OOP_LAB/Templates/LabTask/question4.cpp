#include <iostream>
using namespace std;
template <typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;
public:
    void setPair(T1 a, T2 b) {
        first = a;
        second = b;
    }
    T1 getFirst() { return first; }
    T2 getSecond() { return second; }
};
int main() {
    Pair<int, string> p1;
    p1.setPair(4, "Four");
    cout << "Pair values: " << p1.getFirst() << ", " << p1.getSecond() << endl;
    Pair<char, float> p2;
    p2.setPair('P', 3.14);
    cout << "Pair values: " << p2.getFirst() << ", " << p2.getSecond() << endl;
    return 0;
}
