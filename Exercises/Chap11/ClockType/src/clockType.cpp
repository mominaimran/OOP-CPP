#include "clockType.h"

void clockType::setHr(int h){
    hr = h;
}

int clockType::getHr(){
    return hr;
}

clockType::clockType(int h, int m, int s)
{
    hr = h;
    min = m;
    sec = s;
}

void clockType::setTime(int h, int m, int s)
{
    if (0 <= h && h < 24)
        hr = h;
    else
        hr = 0;
    if (0 <= m && m < 60)
        min = m;
    else
        min = 0;
    if (0 <= s && s < 60)
        sec = s;
    else
        sec = 0;
}

void clockType::printTime() const
{
    cout << (hr < 10 ? "0" : "") << hr << ":"
         << (min < 10 ? "0" : "") << min << ":"
         << (sec < 10 ? "0" : "") << sec;
}