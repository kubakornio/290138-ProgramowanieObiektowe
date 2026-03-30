#include "Osoba.h"
#include <iostream>

using namespace std;

Osoba::Osoba() {
    nrIndeksu = 0;
    obecnosc = false;
}

Osoba::Osoba(int id, string im, string naz, bool ob) {
    nrIndeksu = id;
    imie = im;
    nazwisko = naz;
    obecnosc = ob; 
}

void Osoba::wyswietl() {
    cout << nrIndeksu << " \t " << imie << " \t " << nazwisko 
         << " \t [" << (obecnosc ? "1" : "0") << "]" << endl;
}