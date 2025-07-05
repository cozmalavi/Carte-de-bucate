#ifndef APERITIV_H
#define APERITIV_H


class Aperitiv : public Reteta
{
private:
    char* tipPreparat;
public:
    Aperitiv(char* _tipPreparat, char* _nume, char* _ingrediente, char* _modPreparare);
    virtual ~Aperitiv();
    void afisare();
};


#endif // APERITIV_H
