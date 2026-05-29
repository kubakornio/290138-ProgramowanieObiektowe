#ifndef INTERFEJSUZYTKOWNIKA_H
#define INTERFEJSUZYTKOWNIKA_H
#include "Osoba.h"
#include "ListaObecnosci.h"
#include "ISerializable.h"

class InterfejsUzytkownika {
private:
    Osoba** tabOsob; 
    ListaObecnosci* tablicaList;
    int maxOsob;
    int maxList;
    int iloscOsob;
    int iloscList;

    void dodajOsobe();
    void przypiszOsobeDoListy();
    void ustawObecnoscNaLiscie();
    void usunOsobe();
    void zmienDaneOsoby();

public:
    InterfejsUzytkownika(Osoba** tabO, int mOsob, ListaObecnosci* tabL, int mList);
    void petla();
};
#endif