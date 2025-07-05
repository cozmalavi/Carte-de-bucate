#ifndef CUCARNE_H
#define CUCARNE_H
#include "FelPrincipal.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class CuCarne : public FelPrincipal
{
public:
    using FelPrincipal::FelPrincipal;

    void afisare() const override;
    void salveazaInFisier(ofstream&) const override;
};

#endif // CUCARNE_H
