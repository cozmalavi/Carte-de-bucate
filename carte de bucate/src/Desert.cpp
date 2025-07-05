#include "Desert.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

Desert::Desert(const char* n, const char* i, const char* m, Data d, int c)
    : Reteta(n, i, m, d, c) {}

void Desert::afisare() const
{
    cout << *this;
}

void Desert::salveazaInFisier(ofstream& f) const
{
    f << nume << "," << ingrediente << "," << modPreparare << ","
      << calorii << "," << dataPublicare<< ",DESERT\n";
}
