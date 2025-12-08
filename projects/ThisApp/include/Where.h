#ifndef WHERE_H
#define WHERE_H
#include <iostream>
using namespace std;

class Where{
    private:
        string name;
        int alpha;
    public:
    void tester();
    void reveal();

    Where& operator=(Where& w);
};

#endif