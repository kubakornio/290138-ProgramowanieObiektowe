#ifndef OSOBA_H
#define OSOBA_H

#include <string>

using namespace std;

class Osoba {
private:
    // cechy schowane przed swiatem zewnetrznym
    string imie;
    string nazwisko;
    int indeks;
    bool obecnosc;

public:
    // domyslny konstruktor (tworzy pustego studenta)
    Osoba();
    // konstruktor z parametrami (do szybkiego tworzenia gotowej osoby)
    Osoba(string i, string n, int ind);

    // metoda do pobrania nazwiska (bo nazwisko jest prywatne, a potrzebujemy klucza)
    string getNazwisko();

    // metody do dzialania na danych
    void ustawObecnosc(bool ob);
    void edytujDane(string n, string i, int ind);
    void drukujOsobe();
};

#endif