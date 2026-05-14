#include "InterfejsUzytkownika.h"
#include <iostream>

using namespace std;

InterfejsUzytkownika::InterfejsUzytkownika(Osoba* tabO, int mOsob, ListaObecnosci* tabL, int mList) {
    tabOsob = tabO;
    maxOsob = mOsob;
    tablicaList = tabL;
    maxList = mList;
    iloscOsob = 0;
    iloscList = 2; // statycznie
}

void InterfejsUzytkownika::dodajOsobe() {
    if (iloscOsob >= maxOsob) { cout << "brak miejsca w bazie\n"; return; }
    
    string imie, nazwisko, data; int ind, wzr;
    cout << "imie: "; cin >> imie;
    cout << "nazwisko: "; cin >> nazwisko;
    cout << "indeks (6 cyfr): "; cin >> ind;
    cout << "wzrost: "; cin >> wzr;
    cout << "data ur: "; cin >> data;

    tabOsob[iloscOsob].setImie(imie);
    tabOsob[iloscOsob].setNazwisko(nazwisko);
    tabOsob[iloscOsob].setNrIndeksu(ind);
    tabOsob[iloscOsob].setWzrost(wzr);
    tabOsob[iloscOsob].setDataUrodzenia(data);
    
    iloscOsob++;
    cout << "dodano do bazy.\n";
}

void InterfejsUzytkownika::przypiszOsobeDoListy() {
    string nazwisko; int nrListy;
    cout << "nazwisko osoby do przypisania: "; cin >> nazwisko;
    cout << "do ktorej listy (1 lub 2): "; cin >> nrListy;
    
    if (nrListy < 1 || nrListy > maxList) { cout << "zly numer listy!\n"; return; }

    for (int i = 0; i < iloscOsob; i++) {
        if (tabOsob[i].getNazwisko() == nazwisko) {
            tablicaList[nrListy-1].przypiszOsobe(&tabOsob[i]);
            cout << "przypisano do listy.\n";
            return;
        }
    }
    cout << "brak takiej osoby w glownej bazie.\n";
}

void InterfejsUzytkownika::ustawObecnoscNaLiscie() {
    string nazwisko; int nrListy, ob;
    cout << "nazwisko: "; cin >> nazwisko;
    cout << "ktora lista (1 czy 2): "; cin >> nrListy;
    cout << "obecny (1 - tak, 0 - nie): "; cin >> ob;
    
    if (nrListy >= 1 && nrListy <= maxList) {
        if (tablicaList[nrListy-1].ustawObecnosc(nazwisko, ob)) {
            cout << "ustawiono.\n";
        } else {
            cout << "brak osoby na liscie.\n";
        }
    }
}

void InterfejsUzytkownika::usunOsobe() {
    string nazwisko;
    cout << "podaj nazwisko do usuniecia z list: "; cin >> nazwisko;
    for (int i = 0; i < maxList; i++) {
        tablicaList[i].usunOsobe(nazwisko);
    }
    cout << "procedura usuwania zakonczona.\n";
}

void InterfejsUzytkownika::zmienDaneOsoby() {
    string stare, noweN, noweI;
    cout << "kogo edytowac (stare nazwisko): "; cin >> stare;
    cout << "nowe imie: "; cin >> noweI;
    cout << "nowe nazwisko: "; cin >> noweN;
    
    for (int i = 0; i < iloscOsob; i++) {
        if (tabOsob[i].getNazwisko() == stare) {
            tabOsob[i].setNazwisko(noweN);
            tabOsob[i].setImie(noweI);
            cout << "zaktualizowano w bazie (na listach tez).\n";
            return;
        }
    }
    cout << "nie znaleziono osoby.\n";
}

void InterfejsUzytkownika::petla() {
    char wybor;
    do {
        cout << "\n--- menu ---\n";
        cout << "0. dodaj osobe do glownej bazy\n";
        cout << "1. przypisz osobe do listy\n";
        cout << "2. drukuj liste\n";
        cout << "3. ustaw obecnosc na liscie\n";
        cout << "4. usun osobe z list\n";
        cout << "5. edytuj dane\n";
        cout << "q. wyjscie\n";
        cout << "wybor: ";
        cin >> wybor;

        switch (wybor) {
            case '0': dodajOsobe(); break;
            case '1': przypiszOsobeDoListy(); break;
            case '2': 
                int nr; cout << "lista (1-2): "; cin >> nr;
                if (nr >= 1 && nr <= maxList) tablicaList[nr-1].drukujListe(nr);
                break;
            case '3': ustawObecnoscNaLiscie(); break;
            case '4': usunOsobe(); break;
            case '5': zmienDaneOsoby(); break;
        }
    } while (wybor != 'q');
}
