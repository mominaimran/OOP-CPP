#include <iostream>
using namespace std;

// Overriding ≠ Polymorphism
// Virtual + Base pointer = Polymorphism

class Shape{
    public:
    virtual void draw(){
        cout << "Draw a shape" << endl;
    }
};
class Circle : public Shape{
    public:
    void draw(){
        cout << "Draw a circle" << endl;
    }
};
class Square : public Shape{
    public:
    void draw(){
        cout << "Draw a square" << endl;
    }
};

int main() {
    Shape *s;//👉 Same pointer, different behavior
    Circle c1;
    Square s1;
   
    s=&s1;//last assignment matter
    s->draw();

    s=&c1;
    s->draw();

    return 0;
}

//is code mein run-time polymorphism achieve hua hai. Base class pointer different derived class objects ko point kar raha hai, aur virtual function ki wajah se function call run time pe object ke type ke basis pe decide ho rahi hai.

// Abstract class wo class hoti hai jismein kam az kam aik pure virtual function hota hai aur iska object nahi banaya ja sakta.