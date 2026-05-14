#include <iostream>
#include <string>
#include "Osoba.h"

using namespace std;

// 1. funkcje pomocnicze

bool dodajOsobeMenu(Osoba tabOsoba[], Osoba* tabOs1[], bool tabObecnosc1[], Osoba* tabOs2[], bool tabObecnosc2[], int &ileOsob, string imie, string nazwisko, int indeks, int wzrost, string data_ur) {
    if (ileOsob >= 10) return false;
    tabOsoba[ileOsob].setImie(imie);
    tabOsoba[ileOsob].setNazwisko(nazwisko);
    tabOsoba[ileOsob].setNrIndeksu(indeks);
    tabOsoba[ileOsob].setWzrost(wzrost);
    tabOsoba[ileOsob].setDataUrodzenia(data_ur);
    tabOs1[ileOsob] = &tabOsoba[ileOsob];
    tabObecnosc1[ileOsob] = false;
    tabOs2[ileOsob] = &tabOsoba[ileOsob];
    tabObecnosc2[ileOsob] = false;
    ileOsob++;
    return true;
}

bool ustawObecnoscMenu(Osoba* tabOs[], bool tabObecnosc[], int ileOsob, string nazwisko, bool czyObecny) {
    for (int i = 0; i < ileOsob; i++) {
        if (tabOs[i]->getNazwisko() == nazwisko) { 
            tabObecnosc[i] = czyObecny;
            return true;
        }
    }
    return false;
}

void drukujListeMenu(Osoba* tabOs[], bool tabObecnosc[], int ileOsob, int nrLabow) {
    cout << "\n--- lista obecnosci: laby " << nrLabow << " ---\n";
    for (int i = 0; i < ileOsob; i++) {
        tabOs[i]->drukujOsobe();
        cout << " | obecnosc: " << tabObecnosc[i] << endl;
    }
}

bool usunOsobeMenu(Osoba tabOsoba[], Osoba* tabOs1[], bool tabObecnosc1[], Osoba* tabOs2[], bool tabObecnosc2[], int &ileOsob, string nazwisko) {
    for (int i = 0; i < ileOsob; i++) {
        if (tabOsoba[i].getNazwisko() == nazwisko) {
            for (int j = i; j < ileOsob - 1; j++) {
                tabOsoba[j] = tabOsoba[j + 1];
                tabOs1[j] = &tabOsoba[j];
                tabOs2[j] = &tabOsoba[j];
                tabObecnosc1[j] = tabObecnosc1[j + 1];
                tabObecnosc2[j] = tabObecnosc2[j + 1];
            }
            ileOsob--;
            return true;
        }
    }
    return false;
}

bool edytujOsobeMenu(Osoba tabOsoba[], int ileOsob, string stareNazwisko, string noweNazwisko, string noweImie) {
    for (int i = 0; i < ileOsob; i++) {
        if (tabOsoba[i].getNazwisko() == stareNazwisko) {
            tabOsoba[i].setNazwisko(noweNazwisko);
            tabOsoba[i].setImie(noweImie);
            return true;
        }
    }
    return false;
}

// 2. glowna funkcja programu
int main() {
    Osoba tabOsoba[10];
    Osoba* tabOs1[10];
    bool tabObecnosc1[10];
    Osoba* tabOs2[10];
    bool tabObecnosc2[10];
    int ileOsob = 0;
    int wybor;

    do {
        cout << "\n--- menu laby 2 ---\n";
        cout << "1. dodaj osobe\n2. ustaw obecnosc\n3. drukuj liste\n4. usun osobe\n5. edytuj osobe\n0. koniec\n";
        cout << "wybor: ";
        cin >> wybor;

        if (wybor == 1) {
            string imie, nazwisko, data; int ind, wzr;
            cout << "imie: "; cin >> imie;
            cout << "nazwisko: "; cin >> nazwisko;
            cout << "indeks: "; cin >> ind;
            cout << "wzrost: "; cin >> wzr;
            cout << "data: "; cin >> data;
            dodajOsobeMenu(tabOsoba, tabOs1, tabObecnosc1, tabOs2, tabObecnosc2, ileOsob, imie, nazwisko, ind, wzr, data);
        } 
        else if (wybor == 2) {
            string nazwisko; int lab, ob;
            cout << "nazwisko: "; cin >> nazwisko;
            cout << "ktory lab (1/2): "; cin >> lab;
            cout << "obecny (1/0): "; cin >> ob;
            if (lab == 1) ustawObecnoscMenu(tabOs1, tabObecnosc1, ileOsob, nazwisko, ob);
            else if (lab == 2) ustawObecnoscMenu(tabOs2, tabObecnosc2, ileOsob, nazwisko, ob);
        }
        else if (wybor == 3) {
            int lab; cout << "lista (1/2): "; cin >> lab;
            if (lab == 1) drukujListeMenu(tabOs1, tabObecnosc1, ileOsob, 1);
            else if (lab == 2) drukujListeMenu(tabOs2, tabObecnosc2, ileOsob, 2);
        }
        else if (wybor == 4) {
            string nazwisko; cout << "nazwisko do usuniecia: "; cin >> nazwisko;
            usunOsobeMenu(tabOsoba, tabOs1, tabObecnosc1, tabOs2, tabObecnosc2, ileOsob, nazwisko);
        }
        else if (wybor == 5) {
            string stare, noweN, noweI;
            cout << "stare nazwisko: "; cin >> stare;
            cout << "nowe imie: "; cin >> noweI;
            cout << "nowe nazwisko: "; cin >> noweN;
            edytujOsobeMenu(tabOsoba, ileOsob, stare, noweN, noweI);
        }
    } while (wybor != 0);

    return 0;
}