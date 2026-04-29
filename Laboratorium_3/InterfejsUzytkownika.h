#ifndef INTERFEJSUZYTKOWNIKA_H
#define INTERFEJSUZYTKOWNIKA_H
#include "Osoba.h"
#include "ListaObecnosci.h"

class InterfejsUzytkownika {
private:
    Osoba* bazaOsob;
    ListaObecnosci* bazyList;
    int maxOsob, maxList;
    int aktOsob;

    // metody prywatne
    void menuDodajOsobe();       // 0
    void menuPrzypiszDoListy();  // 1
    void menuUstawObecnosc();    // 3
    void menuUsunZListy();       // 4
    void menuZmienDaneOsoby();   // 5
    void menuWyswietlListe();    // Wyswietlanie

public:
    InterfejsUzytkownika(Osoba* tO, int mO, ListaObecnosci* tL, int mL);
    void petla();
};
#endif
