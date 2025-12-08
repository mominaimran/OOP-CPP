#include "Where.h"

void Where::reveal(){
    cout << "My object's address is " << this << endl;
}

void Where::tester(){
    this->alpha = 11;
    cout << this->alpha << endl;
}

Where& Where::operator=(Where& w){
    alpha = w.alpha;
    return *this;
}