#include <iostream>
#include <string>
#include "Osoba.h"

using namespace std;

int main() {
    Osoba lista[10];
    int liczbaOsob = 0;
    int wybor;

    do {
        cout << "\n--- LISTA ---" << endl;
        cout << "1. Dodaj osobe" << endl;
        cout << "2. Przelacz obecnosc" << endl;
        cout << "3. Drukuj liste" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybor: ";
        cin >> wybor;

        if (wybor == 1) {
            if (liczbaOsob < 10) {
                int nr; string im, naz; bool ob;
                cout << "Indeks: "; cin >> nr;
                cout << "Imie: "; cin >> im;
                cout << "Nazwisko: "; cin >> naz;
                cout << "Obecnosc (1/0): "; cin >> ob;
                
                lista[liczbaOsob] = Osoba(nr, im, naz, ob);
                liczbaOsob++;
            }
        } 
        else if (wybor == 2) {
            string szukane;
            cout << "Podaj nazwisko: "; cin >> szukane;
            for (int i = 0; i < liczbaOsob; i++) {
                if (lista[i].getNazwisko() == szukane) {
                    lista[i].setObecnosc(!lista[i].getObecnosc());
                }
            }
        }
        else if (wybor == 3) {
            for (int i = 0; i < liczbaOsob; i++) lista[i].wyswietl();
        }

    } while (wybor != 0);

    return 0;
}