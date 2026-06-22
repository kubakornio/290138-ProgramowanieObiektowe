#include "Pracownik.h"

using namespace std;

Pracownik::Pracownik() {
    id_pracownika = 0;
}

void Pracownik::setId(int w) { id_pracownika = w; }

int Pracownik::getId() { return id_pracownika; }

string Pracownik::serialize() {
    return "PRACOWNIK: " + imie + " " + nazwisko + " | ID: " + to_string(id_pracownika) + " | ur: " + data_urodzenia + " | " + to_string(wzrost) + "cm";
}

map<string, string> Pracownik::eksportuj() {
    map<string, string> dane = Osoba::eksportuj();
    dane["typ"] = "Pracownik";
    dane["id_pracownika"] = to_string(id_pracownika);
    return dane;
}