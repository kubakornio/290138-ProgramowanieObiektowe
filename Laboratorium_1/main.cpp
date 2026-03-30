#include <iostream>
#include <string>
#include "Osoba.h"

using namespace std;

int main() {
    Osoba lista[10];
    int liczbaOsob = 0;
    int wybor;

    do {
        cout << "\n--- SYSTEM OBECNOSCI ---" << endl;
        cout << "1. Dodaj osobe (z obecnoscia)" << endl;
        cout << "2. Przelacz obecnosc (po nazwisku)" << endl;
        cout << "3. Drukuj liste" << endl;
        cout << "4. Usun osobe" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybor: ";
        cin >> wybor;

        if (wybor == 1) {
            if (liczbaOsob < 10) {
                int id; string im, naz; bool ob;
                
                cout << "Podaj nr indeksu: "; cin >> id;
                cout << "Podaj imie: "; cin >> im;
                cout << "Podaj nazwisko: "; cin >> naz;
                cout << "Podaj obecnosc (1 - obecny, 0 - nieobecny): "; cin >> ob;
                
                lista[liczbaOsob] = Osoba(id, im, naz, ob);
                liczbaOsob++;
                cout << "Dodano studenta ze statusem: " << (ob ? "Obecny" : "Nieobecny") << endl;
            } else {
                cout << "Brak miejsca!" << endl;
            }
        } 
        else if (wybor == 2) {
            string szukane;
            cout << "Podaj nazwisko studenta: "; cin >> szukane;
            for (int i = 0; i < liczbaOsob; i++) {
                if (lista[i].nazwisko == szukane) {
                    lista[i].obecnosc = !lista[i].obecnosc;
                    cout << "Zmieniono status!" << endl;
                }
            }
        }
        else if (wybor == 3) {
            cout << "\nINDEKS \t IMIE \t NAZWISKO \t OBECNOSC" << endl;
            for (int i = 0; i < liczbaOsob; i++) lista[i].wyswietl();
        }
        else if (wybor == 4) {
            string doUsuniecia;
            cout << "Podaj nazwisko do usuniecia: "; cin >> doUsuniecia;
            for (int i = 0; i < liczbaOsob; i++) {
                if (lista[i].nazwisko == doUsuniecia) {
                    for (int j = i; j < liczbaOsob - 1; j++) lista[j] = lista[j+1];
                    liczbaOsob--;
                    cout << "Usunieto." << endl;
                    break;
                }
            }
        }

    } while (wybor != 0);

    return 0;
}