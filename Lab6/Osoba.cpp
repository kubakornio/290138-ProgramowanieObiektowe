#include "Osoba.h"

using namespace std;

Osoba::Osoba() {
    imie = "brak"; nazwisko = "brak"; wzrost = 0; data_urodzenia = "brak";
}

void Osoba::setImie(string w) { if (w.length() > 1) imie = w; }
void Osoba::setNazwisko(string w) { if (w.length() > 1) nazwisko = w; }
void Osoba::setWzrost(int w) { if (w > 0) wzrost = w; }
void Osoba::setDataUrodzenia(string w) { data_urodzenia = w; }

string Osoba::getImie() { return imie; }
string Osoba::getNazwisko() { return nazwisko; }

string Osoba::serialize() {
    return "OSOBA: " + imie + " " + nazwisko + " | ur: " + data_urodzenia + " | " + to_string(wzrost) + "cm";
}