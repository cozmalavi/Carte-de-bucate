#include "Reteta.h"
#include "Exceptie.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int Reteta::nrRetete = 0;

Reteta::Reteta(const char* n, const char* i, const char* m, Data d, int c)
    : dataPublicare(d), calorii(c)
{
    if(n==nullptr||strlen(n)==0)
    {
        throw Exceptie("Nume","invalid");
    }

    nume = new char[strlen(n) + 1];
    strcpy(nume, n);
    if(i==nullptr||strlen(i)==0)
    {
        throw Exceptie("Nume","invalid");
    }
    ingrediente = new char[strlen(i) + 1];
    strcpy(ingrediente, i);
    if(m==nullptr||strlen(m)==0)
    {
        throw Exceptie("Nume","invalid");
    }
    modPreparare = new char[strlen(m) + 1];
    strcpy(modPreparare, m);
    nrRetete++;
}

Reteta::~Reteta()
{
    delete[] nume;
    delete[] ingrediente;
    delete[] modPreparare;
    nrRetete--;
}

int Reteta::getNrRetete()
{
    return nrRetete;
}

const char* Reteta::getNume() const
{
    return nume;
}

ostream& operator<<(ostream& out, const Reteta& r)
{
    out << "Reteta: " << r.nume
        << "\nData publicarii: " << r.dataPublicare
        << "\nCalorii: " << r.calorii << " kcal"
        << "\nIngrediente:\n";

    char* temp = new char[strlen(r.ingrediente) + 1];
    strcpy(temp, r.ingrediente);
    char* tok = strtok(temp, ",");
    while (tok)
    {
        out << "  - " << tok << "\n";
        tok = strtok(nullptr, ",");
    }
    delete[] temp;

    out << "Mod de preparare:\n  " << r.modPreparare << "\n";
    return out;
}

Reteta& Reteta::operator+(int extra)
{
    calorii += extra;
    return *this;
}

bool Reteta::operator==(const Reteta& o) const
{
    return strcmp(nume, o.nume) == 0;
}

bool Reteta::operator<(const Reteta& o) const
{
    return calorii < o.calorii;
}

bool Reteta::operator!=(const Reteta& o) const
{
    return !(*this == o);
}
