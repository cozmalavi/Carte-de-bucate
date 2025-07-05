#ifndef DESERT_H
#define DESERT_H
#include "Reteta.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Desert : public Reteta
{
public:
    Desert(const char* n = "", const char* i = "", const char* m = "", Data d = Data(), int c = 0);
    void afisare() const override;
    void salveazaInFisier(ofstream&) const override;
};

#endif // DESERT_H
