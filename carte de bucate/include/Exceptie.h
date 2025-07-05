#ifndef EXCEPTIE_H
#define EXCEPTIE_H
#include <iostream>
#include<cstring>
using namespace std;

class Exceptie
{
    char catEx[50], tipEx[50];
public:
    Exceptie(char _catEx[], char _tipEx[]);
    void Print();
};


#endif // EXCEPTIE_H
