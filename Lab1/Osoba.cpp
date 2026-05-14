#include "Osoba.h"
#include <iostream>

using namespace std;

// tak tworzymy domyslna osobe
Osoba::Osoba() {
    imie = "";
    nazwisko = "";
    indeks = 0;
    obecnosc = false;
}

// tak tworzymy osobe z konkretnymi danymi zdefiniowanymi podczas tworzenia
Osoba::Osoba(string i, string n, int ind) {
    imie = i;
    nazwisko = n;
    indeks = ind;
    obecnosc = false; // na start brak obecnosci
}

// pobiera prywatne nazwisko - sluzy do wyszukiwania (nasz klucz)
string Osoba::getNazwisko() {
    return nazwisko;
}

// zmienia obecnosc
void Osoba::ustawObecnosc(bool ob) {
    obecnosc = ob;
}

// podmienia stare dane na nowe
void Osoba::edytujDane(string n, string i, int ind) {
    nazwisko = n;
    imie = i;
    indeks = ind;
}

// drukuje pojedynczego studenta
void Osoba::drukujOsobe() {
    cout << indeks << " | " << imie << " " << nazwisko << " | obecnosc: " << obecnosc << endl;
}