#ifndef INTERFEJSUZYTKOWNIKA_H
#define INTERFEJSUZYTKOWNIKA_H

#include "Osoba.h"
#include "ListaObecnosci.h"
#include <string>

using namespace std;

class InterfejsUzytkownika {
private:
    // wskazniki na zewnetrzne bazy danych
    Osoba* tabOsob;
    ListaObecnosci* tablicaList;
    int maxOsob;
    int maxList;
    int iloscOsob;
    int iloscList;

    // metody prywatne
    void dodajOsobe();
    void przypiszOsobeDoListy();
    void ustawObecnoscNaLiscie();
    void usunOsobe();
    void zmienDaneOsoby();

public:
    // konstruktor przyjmuje gotowe tablice z maina
    InterfejsUzytkownika(Osoba* tabO, int mOsob, ListaObecnosci* tabL, int mList);
    
    // jedyna publiczna metoda ktora odpala program
    void petla();
};

#endif