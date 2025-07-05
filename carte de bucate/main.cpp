#include <iostream>
#include <cstring>
#include "DesertCopt.h"
#include "DesertRece.h"
#include "Vegetarian.h"
#include "CuCarne.h"
#include "FelPrincipal.h"
#include "Exceptie.h"

using namespace std;

bool autentificare() {
    string utilizator_corect = "lavinia";
    string parola_corecta = "1234";
    string utilizator, parola;
    int incercari = 3;

    while (incercari > 0) {
        cout << "Introduceti utilizatorul: ";
        cin >> utilizator;
        cout << "Introduceti parola: ";
        cin >> parola;

        if (utilizator == utilizator_corect && parola == parola_corecta)
            return true;

        incercari--;
        cout << "Autentificare esuata! Mai ai " << incercari << " incercari.\n";
    }
    return false;
}

void adaugaReteta(Reteta* retete[], int& nrRetete);

int main() {
    if (!autentificare()) {
        cout << "\nAcces refuzat la cartea de bucate!\n";
        return 1;
    }

    Reteta* retete[100];
    int nrRetete = 5;

    retete[0] = new DesertCopt("Cheesecake", "Branza,zahar,oua", "Se coace la cuptor", Data(1, 6, 2025), 480);
    retete[1] = new DesertRece("Tiramisu", "Mascarpone,cafea,piscoturi", "Se raceste in frigider", Data(2, 6, 2025), 520);
    retete[2] = new CuCarne("Sarmale", "Carne,varza,orez", "Se fierb", Data(3, 6, 2025), 650);
    retete[3] = new Vegetarian("Ciorba de legume", "Cartofi,morcovi,ceapa", "Se fierb toate ingredientele", Data(4, 6, 2025), 300);
    retete[4] = new FelPrincipal("Paste Carbonara", "Paste,oua,branza", "Se amesteca si se servesc", Data(5, 6, 2025), 580);

    int optiune;
    do {
        cout << "\n===== CARTE DE BUCATE =====\n";
        cout << "1. Afisare toate retetele\n";
        cout << "2. Cautare reteta dupa nume\n";
        cout << "3. Adauga calorii unei retete\n";
        cout << "4. Adauga o reteta noua\n";
        cout << "5. Comparare intre doua retete (calorii)\n";
        cout << "6. Verifica daca doua retete au nume diferite\n";
        cout << "0. Iesire\n";
        cout << "Alege o optiune: ";
        cin >> optiune;

        switch (optiune) {
        case 1:
            cout << "\nNumar total de retete: " << Reteta::getNrRetete() << "\n\n";
            for (int i = 0; i < nrRetete; i++) {
                cout << "------------------------------\n";
                retete[i]->afisare();
            }
            break;

        case 2: {
            char numeCautat[100];
            cout << "Introduceti numele retetei cautate: ";
            cin.ignore();
            cin.getline(numeCautat, 100);
            bool gasit = false;
            for (int i = 0; i < nrRetete; i++) {
                if (strcmp(retete[i]->getNume(), numeCautat) == 0) {
                    cout << "Reteta gasita:\n";
                    retete[i]->afisare();
                    gasit = true;
                    break;
                }
            }
            if (!gasit)
                cout << "Reteta \"" << numeCautat << "\" nu a fost gasita.\n";
            break;
        }

        case 3: {
            int index, extra;
            cout << "Introdu indexul retetei (0 - " << nrRetete - 1 << "): ";
            cin >> index;
            if (index < 0 || index >= nrRetete) {
                cout << "Index invalid.\n";
                break;
            }
            cout << "Calorii de adaugat: ";
            cin >> extra;
            *retete[index] + extra;
            cout << "Reteta actualizata:\n";
            retete[index]->afisare();
            break;
        }

        case 4:
            adaugaReteta(retete, nrRetete);
            break;

        case 5: {
            int i1, i2;
            cout << "Index reteta 1: ";
            cin >> i1;
            cout << "Index reteta 2: ";
            cin >> i2;
            if (i1 >= 0 && i1 < nrRetete && i2 >= 0 && i2 < nrRetete) {
                if (*retete[i1] < *retete[i2])
                    cout << retete[i1]->getNume() << " are mai putine calorii decat " << retete[i2]->getNume() << ".\n";
                else
                    cout << retete[i1]->getNume() << " NU are mai putine calorii decat " << retete[i2]->getNume() << ".\n";
            } else {
                cout << "Indexuri invalide!\n";
            }
            break;
        }

        case 6: {
            int i1, i2;
            cout << "Index reteta 1: ";
            cin >> i1;
            cout << "Index reteta 2: ";
            cin >> i2;
            if (i1 >= 0 && i1 < nrRetete && i2 >= 0 && i2 < nrRetete) {
                if (*retete[i1] != *retete[i2])
                    cout << "Retetele au nume diferite.\n";
                else
                    cout << "Retetele au acelasi nume.\n";
            } else {
                cout << "Indexuri invalide!\n";
            }
            break;
        }

        case 0:
            cout << "Iesire din program...\n";
            break;

        default:
            cout << "Optiune invalida!\n";
        }
    } while (optiune != 0);

    for (int i = 0; i < nrRetete; i++)
        delete retete[i];
    return 0;
}

void adaugaReteta(Reteta* retete[], int& nrRetete) {
    if (nrRetete >= 100) {
        cout << "Nu mai poti adauga retete.\n";
        return;
    }

    char nume[100], ingrediente[250], mod[250];
    int zi, luna, an, cal, tipOpt;

    cout << "\nAlege tipul retetei:\n";
    cout << "1. Desert Copt\n";
    cout << "2. Desert Rece\n";
    cout << "3. Fel Principal Vegetarian\n";
    cout << "4. Fel Principal cu Carne\n";
    cout << "5. Fel Principal Simplu\n";
    cout << "Optiune: ";
    cin >> tipOpt;

    cin.ignore();
    cout << "Nume reteta: ";
    cin.getline(nume, 100);
    cout << "Ingrediente (separate prin virgula): ";
    cin.getline(ingrediente, 250);
    cout << "Mod de preparare: ";
    cin.getline(mod, 250);
    cout << "Data publicarii (zi luna an): ";
    cin >> zi >> luna >> an;
    cout << "Numar calorii: ";
    cin >> cal;

    try {
        Data d(zi, luna, an);
        Reteta* noua = nullptr;
        switch (tipOpt) {
            case 1: noua = new DesertCopt(nume, ingrediente, mod, d, cal); break;
            case 2: noua = new DesertRece(nume, ingrediente, mod, d, cal); break;
            case 3: noua = new Vegetarian(nume, ingrediente, mod, d, cal); break;
            case 4: noua = new CuCarne(nume, ingrediente, mod, d, cal); break;
            case 5: noua = new FelPrincipal(nume, ingrediente, mod, d, cal); break;
            default:
                throw Exceptie((char*)"Reteta", (char*)"Tip invalid!");
        }

        retete[nrRetete++] = noua;
        cout << "Reteta a fost adaugata cu succes!\n";

    } catch (Exceptie& e) {
        e.Print();
    }
}
