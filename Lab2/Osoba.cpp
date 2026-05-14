#include "Osoba.h"
#include <iostream>

using namespace std;

Osoba::Osoba() {
    imie = "brak";
    nazwisko = "brak";
    nr_indeksu = 0;
    wzrost = 0;
    data_urodzenia = "brak";
}

// setery z walidacja danych z tablicy
void Osoba::setImie(string wartosc) {
    if (wartosc.length() > 1) { 
        imie = wartosc;
    } else {
        cout << "blad: imie za krotkie\n";
    }
}

void Osoba::setNazwisko(string wartosc) {
    if (wartosc.length() > 1) {
        nazwisko = wartosc;
    } else {
        cout << "blad: nazwisko za krotkie\n";
    }
}

void Osoba::setNrIndeksu(int wartosc) {
    // nr indeksu sklada sie z 6 cyfr
    if (wartosc >= 100000 && wartosc <= 999999) { 
        nr_indeksu = wartosc;
    } else {
        cout << "blad: indeks musi miec 6 cyfr\n";
    }
}

void Osoba::setWzrost(int wartosc) {
    if (wartosc > 0) {
        wzrost = wartosc;
    }
}

void Osoba::setDataUrodzenia(string wartosc) {
    data_urodzenia = wartosc;
}

// gettery
string Osoba::getImie() { return imie; }
string Osoba::getNazwisko() { return nazwisko; }
int Osoba::getNrIndeksu() { return nr_indeksu; }
int Osoba::getWzrost() { return wzrost; }
string Osoba::getDataUrodzenia() { return data_urodzenia; }

void Osoba::drukujOsobe() {
    cout << nr_indeksu << " | " << imie << " " << nazwisko 
         << " | " << data_urodzenia << " | " << wzrost << "cm";
}