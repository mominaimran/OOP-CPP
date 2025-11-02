#ifndef COUNTER_H
#define COUNTER_H
#include <iostream>
using namespace std;

class Counter {
private:
    static int count;   // static variable — common for all objects
    int id;

public:
    Counter();          // constructor
    void show() const;  // normal member function
    static void showCount(); // static function
};

#endif
