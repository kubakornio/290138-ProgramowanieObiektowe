#include "Pracownik.h"
#include <iostream>

using namespace std;

Pracownik::Pracownik() {
    id_pracownika = 0;
}

void Pracownik::setId(int w) { id_pracownika = w; }

int Pracownik::getId() { return id_pracownika; }

void Pracownik::drukuj() {
    cout << "PRACOWNIK: " << imie << " " << nazwisko << " | ID: " << id_pracownika << " | ur: " << data_urodzenia << " | " << wzrost << "cm";
}