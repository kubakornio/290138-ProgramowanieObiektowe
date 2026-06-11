#include "InterfejsUzytkownika.h"
#include "Student.h"
#include "Pracownik.h"
#include "ISerializable.h"
#include <iostream>
#include <fstream>

using namespace std;

InterfejsUzytkownika::InterfejsUzytkownika(Osoba** tabO, int mOsob, ListaObecnosci* tabL, int mList) {
    tabOsob = tabO;
    maxOsob = mOsob;
    tablicaList = tabL;
    maxList = mList;
    iloscOsob = 0;
    iloscList = mList;
}

void InterfejsUzytkownika::dodajOsobe() {
    if (iloscOsob >= maxOsob) { cout << "brak miejsca w bazie\n"; return; }
    
    char wybor;
    cout << "Kogo chcesz dodac? (s - student, p - pracownik): ";
    cin >> wybor;

    string imie, nazwisko, data; int wzr;
    cout << "imie: "; cin >> imie;
    cout << "nazwisko: "; cin >> nazwisko;
    cout << "wzrost: "; cin >> wzr;
    cout << "data ur: "; cin >> data;

    if (wybor == 's') {
        int indeks;
        cout << "podaj indeks (6 cyfr): "; cin >> indeks;
        
        Student* s = new Student();
        s->setImie(imie);
        s->setNazwisko(nazwisko);
        s->setWzrost(wzr);
        s->setDataUrodzenia(data);
        s->setNrIndeksu(indeks);
        
        tabOsob[iloscOsob] = s;
        cout << "dodano studenta do bazy\n";
    } 
    else if (wybor == 'p') {
        int id;
        cout << "podaj id pracownika: "; cin >> id;
        
        Pracownik* p = new Pracownik();
        p->setImie(imie);
        p->setNazwisko(nazwisko);
        p->setWzrost(wzr);
        p->setDataUrodzenia(data);
        p->setId(id);
        
        tabOsob[iloscOsob] = p;
        cout << "dodano pracownika do bazy\n";
    } else {
        cout << "nieznany wybor\n";
        return;
    }
    iloscOsob++;
}

void InterfejsUzytkownika::przypiszOsobeDoListy() {
    string nazwisko; int nrListy;
    cout << "nazwisko osoby do przypisania: "; cin >> nazwisko;
    cout << "do ktorej listy (1 lub 2): "; cin >> nrListy;
    
    if (nrListy < 1 || nrListy > maxList) { cout << "zly numer listy!\n"; return; }

    for (int i = 0; i < iloscOsob; i++) {
        if (tabOsob[i]->getNazwisko() == nazwisko) {
            tablicaList[nrListy-1].przypiszOsobe(tabOsob[i]);
            cout << "przypisano do listy\n";
            return;
        }
    }
    cout << "brak takiej osoby w glownej bazie\n";
}

void InterfejsUzytkownika::ustawObecnoscNaLiscie() {
    string nazwisko; int nrListy, ob;
    cout << "nazwisko: "; cin >> nazwisko;
    cout << "ktora lista (1 czy 2): "; cin >> nrListy;
    cout << "obecny (1 - tak, 0 - nie): "; cin >> ob;
    
    if (nrListy >= 1 && nrListy <= maxList) {
        if (tablicaList[nrListy-1].ustawObecnosc(nazwisko, ob)) {
            cout << "ustawiono\n";
        } else {
            cout << "brak osoby na liscie\n";
        }
    }
}

void InterfejsUzytkownika::usunOsobe() {
    string nazwisko;
    cout << "podaj nazwisko do usuniecia z list: "; cin >> nazwisko;
    for (int i = 0; i < maxList; i++) {
        tablicaList[i].usunOsobe(nazwisko);
    }
    cout << "procedura usuwania zakonczona\n";
}

void InterfejsUzytkownika::zmienDaneOsoby() {
    string stare, noweN, noweI;
    cout << "kogo edytowac (stare nazwisko): "; cin >> stare;
    cout << "nowe imie: "; cin >> noweI;
    cout << "nowe nazwisko: "; cin >> noweN;
    
    for (int i = 0; i < iloscOsob; i++) {
        if (tabOsob[i]->getNazwisko() == stare) {
            tabOsob[i]->setNazwisko(noweN);
            tabOsob[i]->setImie(noweI);
            cout << "zaktualizowano w bazie (na listach tez)\n";
            return;
        }
    }
    cout << "nie znaleziono osoby.\n";
}

void InterfejsUzytkownika::zapiszDoPliku(ISerializable* obj, string nazwaPliku) {
    ofstream plik;
    plik.open(nazwaPliku, ios::app); //ios::app zeby dopisywac dane bez kasowania poprzednich
    if (plik.is_open()) {
        plik << obj->serialize() << "\n";
        plik.close();
        cout << "Zapisano do pliku: " << nazwaPliku << "\n";
    } else {
        cout << "Blad otwarcia pliku!\n";
    }
}

void InterfejsUzytkownika::menuZapiszDoPliku() {
    int coZapisac;
    cout << "Co zapisac do pliku .txt? (1 - cala liste, 2 - wybrana osobe): ";
    cin >> coZapisac;
    
    if (coZapisac == 1 || coZapisac == 2) {
        string nazwa;
        cout << "Podaj nazwe pliku (np. dane.txt): ";
        cin >> nazwa;
        
        if (coZapisac == 1) {
            int nr;
            cout << "Ktora liste zapisac (1-" << maxList << "): ";
            cin >> nr;
            if (nr >= 1 && nr <= maxList) {
                // przekazuje adres listy lista implementuje ISerializable
                zapiszDoPliku(&tablicaList[nr-1], nazwa); 
            } else {
                cout << "Zly numer listy.\n";
            }
        } 
        else if (coZapisac == 2) {
            string nazwisko;
            cout << "Podaj nazwisko osoby do zapisania: ";
            cin >> nazwisko;
            bool znaleziono = false;
            for (int i = 0; i < iloscOsob; i++) {
                if (tabOsob[i]->getNazwisko() == nazwisko) {
                    // przekazuje adres osoby  osoba (i student/pracownik) implementuje ISerializable
                    zapiszDoPliku(tabOsob[i], nazwa);
                    znaleziono = true;
                    break;
                }
            }
            if (!znaleziono) cout << "Nie znaleziono takiej osoby w bazie.\n";
        }
    } else {
        cout << "Zly wybor.\n";
    }
}

void InterfejsUzytkownika::petla() {
    char wybor;
    do {
        cout << "\n--- menu v6 (ZAPIS DO PLIKU) ---\n";
        cout << "0. dodaj osobe\n1. przypisz do listy\n2. drukuj liste\n";
        cout << "3. ustaw obecnosc\n4. usun z list\n5. edytuj dane\n";
        cout << "6. zapisz do pliku txt\n";
        cout << "q. wyjscie\nwybor: ";
        cin >> wybor;

        switch (wybor) {
            case '0': dodajOsobe(); break;
            case '1': przypiszOsobeDoListy(); break;
            case '2': {
                int nr; cout << "lista (1-" << maxList << "): "; cin >> nr;
                if (nr >= 1 && nr <= maxList) {
                    drukuj(&tablicaList[nr-1]);
                }
                break;
            }
            case '3': ustawObecnoscNaLiscie(); break;
            case '4': usunOsobe(); break;
            case '5': zmienDaneOsoby(); break;
            case '6': menuZapiszDoPliku(); break; // zapis
        }
    } while (wybor != 'q');
}