#ifndef DESERTCOPT_H
#define DESERTCOPT_H
#include "Desert.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class DesertCopt : public Desert
{
public:
    using Desert::Desert;

    void afisare() const override;
    void salveazaInFisier(ofstream&) const override;
};

#endif // DESERTCOPT_H
