#include "Vegetarian.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void Vegetarian::afisare() const
{
    cout << *this;
}

void Vegetarian::salveazaInFisier(ofstream& f) const
{
    f << nume << "," << ingrediente << "," << modPreparare << ","
      << calorii << "," << dataPublicare
      << ",VEGETARIAN\n";
}
