#include "Osoba.h"
#include <iostream>

using namespace std;

Osoba::Osoba() {
    nr_indeksu = 0;
    obecnosc = false;
}

Osoba::Osoba(int nr, string im, string naz, bool ob) {
    setNrIndeksu(nr);
    setImie(im);
    setNazwisko(naz);
    setObecnosc(ob);
}

void Osoba::setImie(string wartosc) {
    if (wartosc.length() >= 3) {
        imie = wartosc;
    } else {
        cout << "Imie za krotkie!" << endl;
        imie = "Brak";
    }
}

void Osoba::setNazwisko(string wartosc) {
    if (wartosc.length() >= 3) {
        nazwisko = wartosc;
    } else {
        cout << "Nazwisko za krotkie!" << endl;
        nazwisko = "Brak";
    }
}

void Osoba::setNrIndeksu(int nr) {
    if (nr >= 100000 && nr <= 999999) {
        nr_indeksu = nr;
    } else {
        nr_indeksu = 0;
    }
}

void Osoba::setObecnosc(bool ob) { obecnosc = ob; }

// Gettery
string Osoba::getImie() { return imie; }
string Osoba::getNazwisko() { return nazwisko; }
int Osoba::getNrIndeksu() { return nr_indeksu; }
bool Osoba::getObecnosc() { return obecnosc; }

void Osoba::wyswietl() {
    cout << nr_indeksu << " \t " << imie << " \t " << nazwisko 
         << " \t [" << (obecnosc ? "1" : "0") << "]" << endl;
}