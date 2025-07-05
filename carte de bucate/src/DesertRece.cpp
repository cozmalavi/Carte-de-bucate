#include "DesertRece.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void DesertRece::afisare() const
{
    cout << *this;
}

void DesertRece::salveazaInFisier(ofstream& f) const
{
    f << nume << "," << ingrediente << "," << modPreparare << ","
      << calorii << "," << dataPublicare
      << ",DESERT RECE\n";
}
