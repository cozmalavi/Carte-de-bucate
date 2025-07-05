#include "CuCarne.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void CuCarne::afisare() const
{
    cout << *this;
}

void CuCarne::salveazaInFisier(ofstream& f) const
{
    f << nume << "," << ingrediente << "," << modPreparare << ","
      << calorii << "," << dataPublicare
      << ",CU CARNE\n";
}
