#include "Aperitiv.h"

Aperitiv::Aperitiv(char* _tipPreparat, char* _nume, char* _ingrediente, char* _modPreparare): Reteta(_nume, _ingrediente, _modPreparare)
{
    if (strlen(_tipPreparat) <= 0)
        throw Exceptie("Aperitiv", "Tip invalid");
    tipPreparat = new char[strlen(_tipPreparat) + 1];
    strcpy(tipPreparat, _tipPreparat);
}

Aperitiv::~Aperitiv()
{
    delete[] tipPreparat;
}

void Aperitiv::afisare()
{
    cout << "Preparat: " << tipPreparat << " ";
    Reteta::afisare();
}
