#include "ListaObecnosci.h"
#include <iostream>

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

void ListaObecnosci::drukujListe(int numerListy) {
    cout << "\n--- lista obecnosci nr " << numerListy << " ---\n";
    for (int i = 0; i < iloscZapisanych; i++) {
        tabOsob[i]->drukuj(); // celowe "niewlasciwe wyswietlanie" wg tablicy
        cout << " | obecnosc: " << tabObecnosc[i] << endl;
    }
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