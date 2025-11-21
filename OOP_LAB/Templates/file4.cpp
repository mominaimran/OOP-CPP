#include <iostream>
using namespace std;

template <class T1, class T2>
class A{
    T1 a;
    T2 b;
public:
A(T1 x, T2 y){
    a=x;
    b=y;
}
void display(){
    cout << "Values of a and b: " << a << ", " << b << endl;
}
};

int main() {
    A<int, float> d(5, 6.5);
    d.display();
    return 0;
}

// A class template is like a normal class, but it has a placeholder type (T) that you can replace with any real data type (int, float, string, etc.) when you create an object