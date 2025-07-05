#include "Exceptie.h"
#include <iostream>
#include<cstring>
using namespace std;


Exceptie::Exceptie(char _catEx[], char _tipEx[])
{
    strcpy(catEx, _catEx );
    strcpy(tipEx, _tipEx );

}
void Exceptie::Print()
{
    cerr<<"Exceptie ["<<catEx<<"] - "<<tipEx<<endl;
}
