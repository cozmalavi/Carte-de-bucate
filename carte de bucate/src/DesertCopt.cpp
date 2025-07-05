#include "DesertCopt.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void DesertCopt::afisare() const
{
    cout << *this;
}

void DesertCopt::salveazaInFisier(ofstream& f) const
{
    f << nume << "," << ingrediente << "," << modPreparare << ","
      << calorii << "," << dataPublicare
      << ",DESERT_COPT\n";
}
