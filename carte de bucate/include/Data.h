#ifndef DATA_H
#define DATA_H
#include <iostream>
#include "Exceptie.h"
using namespace std;

struct Data
{
    int zi, luna, an;

    Data(int _zi = 1, int _luna = 1, int _an = 2000)
    {
        if (_zi < 1 || _zi > 31 || _luna < 1 || _luna > 12 || _an < 1900 || _an > 2100)
            throw Exceptie((char*)"Data", (char*)"Data calendaristica invalida");
        zi = _zi;
        luna = _luna;
        an = _an;
    }

    friend ostream& operator<<(ostream& out, const Data& d)
    {
        out  << d.zi << "/"<<d.luna << "/"<< d.an;
        return out;
    }

    int getZi() const
    {
        return zi;
    }
    int getLuna() const
    {
        return luna;
    }
    int getAn() const
    {
        return an;
    }
};

#endif
