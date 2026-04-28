#ifndef LISTAOBECNOSCI_H
#define LISTAOBECNOSCI_H
#include "Osoba.h"

class ListaObecnosci {
private:
    Osoba* tabOsob[10];      // Tablica wskaznikow do bazy
    bool tabObecnosci[10];   // Obecnosc na tej konkretnej liscie
    int licznik;

public:
    ListaObecnosci();
    void dodajOsobeDoListy(Osoba* os);
    void usunZListy(int index);
    void przelaczObecnosc(int index);
    void drukuj();
    int getLicznik();
};
#endif