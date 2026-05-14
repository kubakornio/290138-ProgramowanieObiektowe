#ifndef LISTAOBECNOSCI_H
#define LISTAOBECNOSCI_H
#include "Osoba.h"
#include <string>

using namespace std;

class ListaObecnosci {
private:
    // to byly wczesniej luzne tablice w mainie teraz sa ukryte tutaj -----------kompozycja
    Osoba* tabOsob[10];
    bool tabObecnosc[10];
    int iloscZapisanych;

public:
    ListaObecnosci();
    
    // metody do zarzadzania ta konkretna lista
    bool przypiszOsobe(Osoba* os);
    bool ustawObecnosc(string nazwisko, bool czyObecny);
    void drukujListe(int numerListy);
    bool usunOsobe(string nazwisko);
};

#endif