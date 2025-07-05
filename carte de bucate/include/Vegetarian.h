#ifndef VEGETARIAN_H
#define VEGETARIAN_H
#include "FelPrincipal.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Vegetarian : public FelPrincipal {
public:
    using FelPrincipal::FelPrincipal;

    void afisare() const override;
    void salveazaInFisier(ofstream&) const override;
};

#endif // VEGETARIAN_H
