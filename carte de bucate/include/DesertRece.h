#ifndef DESERTRECE_H
#define DESERTRECE_H
#include "Desert.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class DesertRece : public Desert
{
public:
    using Desert::Desert;

    void afisare() const override;
    void salveazaInFisier(ofstream&) const override;
};
#endif // DESERTRECE_H
