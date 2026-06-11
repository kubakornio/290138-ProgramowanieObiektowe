#ifndef INTERFEJSUZYTKOWNIKA_H
#define INTERFEJSUZYTKOWNIKA_H
#include "Osoba.h"
#include "ListaObecnosci.h"
#include "ISerializable.h"
#include <string>

using namespace std;

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
    
    void menuZapiszDoPliku();
    void zapiszDoPliku(ISerializable* obj, string nazwaPliku);

public:
    InterfejsUzytkownika(Osoba** tabO, int mOsob, ListaObecnosci* tabL, int mList);
    void petla();
};
#endif