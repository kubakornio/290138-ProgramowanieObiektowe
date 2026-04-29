#include "InterfejsUzytkownika.h"
#include <iostream>
using namespace std;

InterfejsUzytkownika::InterfejsUzytkownika(Osoba* tO, int mO, ListaObecnosci* tL, int mL) {
    bazaOsob = tO; maxOsob = mO; bazyList = tL; maxList = mL; aktOsob = 0;
}

void InterfejsUzytkownika::petla() {
    int wybor;
    while (true) {
        cout << "\n=== MENU GLOWNE ===" << endl;
        cout << "0. Dodaj osobe do bazy danych" << endl;
        cout << "1. Przypisz osobe z bazy do listy" << endl;
        cout << "2. Wyswietl wybrana liste" << endl;
        cout << "3. Ustaw obecnosc studenta na liscie" << endl;
        cout << "4. Usun osobe z listy (bez dziur)" << endl;
        cout << "5. Zmien dane osoby w bazie" << endl;
        cout << "9. Koniec programu" << endl;
        cout << "Wybor: "; cin >> wybor;

        if (wybor == 9) break;
        switch (wybor) {
            case 0: menuDodajOsobe(); break;
            case 1: menuPrzypiszDoListy(); break;
            case 2: menuWyswietlListe(); break;
            case 3: menuUstawObecnosc(); break;
            case 4: menuUsunZListy(); break;
            case 5: menuZmienDaneOsoby(); break;
            default: cout << "Bledna opcja" << endl;
        }
    }
}

void InterfejsUzytkownika::menuDodajOsobe() {
    if (aktOsob < maxOsob) {
        int nr; string im, naz;
        cout << "--- NOWA OSOBA ---" << endl;
        cout << "Indeks: "; cin >> nr;
        cout << "Imie: "; cin >> im;
        cout << "Nazwisko: "; cin >> naz;
        bazaOsob[aktOsob] = Osoba(nr, im, naz);
        aktOsob++;
        cout << "Dodano do bazy (pozycja: " << aktOsob - 1 << ")" << endl;
    } else cout << "Baza osob pelna" << endl;
}

void InterfejsUzytkownika::menuPrzypiszDoListy() {
    int oIdx, lIdx;
    cout << "Nr osoby w bazie (0-" << aktOsob-1 << "): "; cin >> oIdx;
    cout << "Nr listy (0-" << maxList-1 << "): "; cin >> lIdx;
    if (oIdx >= 0 && oIdx < aktOsob && lIdx >= 0 && lIdx < maxList) {
        bazyList[lIdx].dodajOsobeDoListy(&bazaOsob[oIdx]); // przekazujemy ADRES
    }
}

void InterfejsUzytkownika::menuWyswietlListe() {
    int lIdx;
    cout << "Nr listy do wyswietlenia: "; cin >> lIdx;
    if (lIdx >= 0 && lIdx < maxList) bazyList[lIdx].drukuj();
}

void InterfejsUzytkownika::menuUstawObecnosc() {
    int lIdx, oIdx;
    cout << "Nr listy: "; cin >> lIdx;
    cout << "Nr osoby na TEJ liscie: "; cin >> oIdx;
    if (lIdx >= 0 && lIdx < maxList) bazyList[lIdx].przelaczObecnosc(oIdx);
}

void InterfejsUzytkownika::menuUsunZListy() {
    int lIdx, oIdx;
    cout << "Nr listy: "; cin >> lIdx;
    cout << "Nr osoby na liscie do usuniecia: "; cin >> oIdx;
    if (lIdx >= 0 && lIdx < maxList) bazyList[lIdx].usunZListy(oIdx);
}

void InterfejsUzytkownika::menuZmienDaneOsoby() {
    int oIdx;
    cout << "Nr osoby w bazie do edycji (0-" << aktOsob-1 << "): "; cin >> oIdx;
    if (oIdx >= 0 && oIdx < aktOsob) {
        string im, naz;
        cout << "Nowe imie: "; cin >> im;
        cout << "Nowe nazwisko: "; cin >> naz;
        bazaOsob[oIdx].setImie(im);
        bazaOsob[oIdx].setNazwisko(naz);
        cout << "Dane zaktualizowane w bazie i na wszystkich listach" << endl;
    }
}
