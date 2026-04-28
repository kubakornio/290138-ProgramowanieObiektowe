#include "Osoba.h"
#include <iostream>
using namespace std;

Osoba::Osoba() { nr_indeksu = 0; imie = "---"; nazwisko = "---"; }
Osoba::Osoba(int nr, string im, string naz) { setNrIndeksu(nr); setImie(im); setNazwisko(naz); }

void Osoba::setImie(string wartosc) { if (wartosc.length() >= 3) imie = wartosc; }
void Osoba::setNazwisko(string wartosc) { if (wartosc.length() >= 3) nazwisko = wartosc; }
void Osoba::setNrIndeksu(int nr) { if (nr >= 100000 && nr <= 999999) nr_indeksu = nr; }

string Osoba::getImie() { return imie; }
string Osoba::getNazwisko() { return nazwisko; }
int Osoba::getNrIndeksu() { return nr_indeksu; }

void Osoba::wyswietl() {
    cout << nr_indeksu << " | " << imie << " " << nazwisko;
}