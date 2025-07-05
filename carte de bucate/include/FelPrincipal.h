#ifndef FELPRINCIPAL_H
#define FELPRINCIPAL_H
#include "Reteta.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class FelPrincipal : public Reteta
{
public:
    FelPrincipal(const char* n = "", const char* i = "", const char* m = "", Data d = Data(), int c = 0);

    void afisare() const override;
    void salveazaInFisier(ofstream&) const override;
};

#endif // FELPRINCIPAL_H
