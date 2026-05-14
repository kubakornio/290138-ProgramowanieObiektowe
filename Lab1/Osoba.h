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
    // domyslny konstruktor
    Osoba();
    // konstruktor z parametrami
    Osoba(string i, string n, int ind);

    // metoda do pobrania nazwiska
    string getNazwisko();

    // metody do dzialania na danych
    void ustawObecnosc(bool ob);
    void edytujDane(string n, string i, int ind);
    void drukujOsobe();
};

#endif
