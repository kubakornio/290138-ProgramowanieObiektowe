#include "ListaObecnosci.h"

using namespace std;

ListaObecnosci::ListaObecnosci() {
    iloscZapisanych = 0;
}

bool ListaObecnosci::przypiszOsobe(Osoba* os) {
    if (iloscZapisanych >= 10) return false;
    
    tabOsob[iloscZapisanych] = os;
    tabObecnosc[iloscZapisanych] = false;
    iloscZapisanych++;
    return true;
}

bool ListaObecnosci::ustawObecnosc(string nazwisko, bool czyObecny) {
    for (int i = 0; i < iloscZapisanych; i++) {
        if (tabOsob[i]->getNazwisko() == nazwisko) {
            tabObecnosc[i] = czyObecny;
            return true;
        }
    }
    return false;
}

bool ListaObecnosci::usunOsobe(string nazwisko) {
    for (int i = 0; i < iloscZapisanych; i++) {
        if (tabOsob[i]->getNazwisko() == nazwisko) {
            for (int j = i; j < iloscZapisanych - 1; j++) {
                tabOsob[j] = tabOsob[j + 1];
                tabObecnosc[j] = tabObecnosc[j + 1];
            }
            iloscZapisanych--;
            return true;
        }
    }
    return false;
}

string ListaObecnosci::serialize() {
    string wynik = "--- LISTA OBECNOSCI ---\n";
    for (int i = 0; i < iloscZapisanych; i++) {
        wynik += tabOsob[i]->serialize() + " | obecnosc: " + (tabObecnosc[i] ? "1" : "0") + "\n";
    }
    return wynik;
}

map<string, string> ListaObecnosci::eksportuj() {
    map<string, string> dane;
    dane["ilosc_zapisanych"] = to_string(iloscZapisanych);
    
    for (int i = 0; i < iloscZapisanych; i++) {
        map<string, string> mapaOsoby = tabOsob[i]->eksportuj();
        string prefiks = "osoba_" + to_string(i + 1) + "_";
        
        for (auto const& [klucz, wartosc] : mapaOsoby) {
            dane[prefiks + klucz] = wartosc;
        }
        dane[prefiks + "obecnosc"] = tabObecnosc[i] ? "1" : "0";
    }
    return dane;
}