#include "FelPrincipal.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

FelPrincipal::FelPrincipal(const char* n, const char* i, const char* m, Data d, int c)
    : Reteta(n, i, m, d, c) {}

void FelPrincipal::afisare() const
{
    cout << *this;
}

void FelPrincipal::salveazaInFisier(ofstream& f) const
{
    f << nume << "," << ingrediente << "," << modPreparare << ","
      << calorii << "," << dataPublicare
      << ",FEL PRINCIPAL\n";
}
