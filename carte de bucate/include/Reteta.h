#ifndef RETETA_H
#define RETETA_H
#include "Data.h"
#include "Exceptie.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Reteta {
protected:
    char* nume;
    char* ingrediente;
    char* modPreparare;
    Data dataPublicare;
    int calorii;
    static int nrRetete;

public:
    Reteta(const char* n = "", const char* i = "", const char* m = "", Data d = Data(), int c = 0);
    virtual ~Reteta();

    virtual void afisare() const = 0;
    virtual void salveazaInFisier(ofstream&) const = 0;

    static int getNrRetete();
    const char* getNume() const;

    friend ostream& operator<<(ostream&, const Reteta&);
    Reteta& operator+(int extra);
    bool operator==(const Reteta&) const;
    bool operator<(const Reteta& o) const;
    bool operator!=(const Reteta& o) const;
};

#endif
