#ifndef CLOCKTYPE_H
#define CLOCKTYPE_H
#include <iostream>
using namespace std;

class clockType{
    protected:
        int hr, min, sec;
    public:
        void setHr(int h);
        int getHr();
        clockType(int h=0, int m=0, int s=0);
        void setTime(int h, int m, int s);
        void printTime()const;
};

#endif