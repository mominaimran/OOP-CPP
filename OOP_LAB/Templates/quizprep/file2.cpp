#include <iostream>
#include <string>
using namespace std;

template <typename T>
class myClass{
    T name;
public:
    void setName(T n){
        name = n;
    }
    T getName(){
        return name;
    }
};

int main(){
    myClass<string> n1;
    n1.setName("Momina");
    cout << n1.getName() << endl;

    return 0;
}
