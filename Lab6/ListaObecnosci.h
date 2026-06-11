#ifndef LISTAOBECNOSCI_H
#define LISTAOBECNOSCI_H
#include "Osoba.h"
#include "ISerializable.h"
#include <string>

using namespace std;

class ListaObecnosci : public ISerializable {
private:
    Osoba* tabOsob[10];
    bool tabObecnosc[10];
    int iloscZapisanych;

public:
    ListaObecnosci();
    bool przypiszOsobe(Osoba* os);
    bool ustawObecnosc(string nazwisko, bool czyObecny);
    bool usunOsobe(string nazwisko);
    
    virtual string serialize() override;
};
#endif