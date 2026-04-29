#include "ListaObecnosci.h"
#include <iostream>
using namespace std;

ListaObecnosci::ListaObecnosci() {
    licznik = 0;
    for(int i=0; i<10; i++) tabOsob[i] = nullptr;
}

void ListaObecnosci::dodajOsobeDoListy(Osoba* os) {
    if (licznik < 10) {
        tabOsob[licznik] = os;
        tabObecnosci[licznik] = false;
        licznik++;
        cout << "Dodano osobe do listy." << endl;
    }
}

void ListaObecnosci::usunZListy(int index) {
    if (index >= 0 && index < licznik) {
        for (int j = index; j < licznik - 1; j++) {
            tabOsob[j] = tabOsob[j+1];
            tabObecnosci[j] = tabObecnosci[j+1];
        }
        licznik--;
        cout << "Usunieto z listy." << endl;
    }
}

void ListaObecnosci::przelaczObecnosc(int index) {
    if (index >= 0 && index < licznik) {
        tabObecnosci[index] = !tabObecnosci[index];
        cout << "Zmieniono status obecnosci." << endl;
    }
}

void ListaObecnosci::drukuj() {
    cout << "\n--- LISTA OBECNOSCI ---" << endl;
    if (licznik == 0) cout << "Pusta." << endl;
    for (int i = 0; i < licznik; i++) {
        cout << i << ". ";
        tabOsob[i]->wyswietl(); // -> bo to wskaznik
        cout << " [" << (tabObecnosci[i] ? "1" : "0") << "]" << endl;
    }
}

int ListaObecnosci::getLicznik() { return licznik; }
