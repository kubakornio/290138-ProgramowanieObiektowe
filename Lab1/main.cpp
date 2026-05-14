#include <iostream>
#include <string>
#include "Osoba.h" // musimy podlaczyc nasz wlasny plik

using namespace std;

// funkcja dodaje nowy obiekt klasy Osoba do tablicy obiektow
bool dodajOsobeMenu(Osoba tablica[], int &ileOsob, string imie, string nazwisko, int indeks) {
    if (ileOsob >= 10) return false; // brak miejsca

    // tworzymy nowy obiekt i wrzucamy do tablicy
    tablica[ileOsob] = Osoba(imie, nazwisko, indeks);
    ileOsob++;
    return true;
}

// funkcja szuka osoby po nazwisku (klucz) i ustawia obecnosc na konkretnym obiekcie
bool ustawObecnoscMenu(Osoba tablica[], int ileOsob, string nazwisko, bool ob) {
    for (int i = 0; i < ileOsob; i++) {
        if (tablica[i].getNazwisko() == nazwisko) {
            tablica[i].ustawObecnosc(ob); // wywolanie metody z klasy
            return true;
        }
    }
    return false;
}

// drukuje wszystkie obiekty z tablicy
void drukujListeMenu(Osoba tablica[], int ileOsob) {
    cout << "\n--- lista studentow ---\n";
    for (int i = 0; i < ileOsob; i++) {
        tablica[i].drukujOsobe();
    }
}

// usuniecie obiektu i przesuniecie pozostalych zeby zlikwidowac dziure
bool usunOsobeMenu(Osoba tablica[], int &ileOsob, string nazwisko) {
    for (int i = 0; i < ileOsob; i++) {
        if (tablica[i].getNazwisko() == nazwisko) {
            // przesuwamy z prawej do lewej
            for (int j = i; j < ileOsob - 1; j++) {
                tablica[j] = tablica[j + 1];
            }
            ileOsob--;
            return true;
        }
    }
    return false;
}

// edytuje konkretny obiekt
bool edytujOsobeMenu(Osoba tablica[], int ileOsob, string stareNazwisko, string noweNazwisko, string noweImie, int nowyIndeks) {
    for (int i = 0; i < ileOsob; i++) {
        if (tablica[i].getNazwisko() == stareNazwisko) {
            tablica[i].edytujDane(noweNazwisko, noweImie, nowyIndeks);
            return true;
        }
    }
    return false;
}

int main() {
    // to jest to, co najwazniejsze - JEDNA tablica 10 obiektow zamiast 4 tablic danych!
    Osoba listaStudentow[10];
    int ileOsob = 0;
    int wybor;

    do {
        cout << "\n--- menu ---\n";
        cout << "1. dodaj osobe\n";
        cout << "2. ustaw obecnosc\n";
        cout << "3. drukuj liste\n";
        cout << "4. usun osobe\n";
        cout << "5. edytuj osobe\n";
        cout << "0. zakoncz\n";
        cout << "twoj wybor: ";
        cin >> wybor;

        if (wybor == 1) {
            string imie, nazwisko;
            int indeks;
            cout << "podaj imie: ";
            cin >> imie;
            cout << "podaj nazwisko: ";
            cin >> nazwisko;
            cout << "podaj nr indeksu: ";
            cin >> indeks;
            
            if (dodajOsobeMenu(listaStudentow, ileOsob, imie, nazwisko, indeks)) {
                cout << "dodano.\n";
            } else {
                cout << "brak miejsca.\n";
            }
        } 
        else if (wybor == 2) {
            string nazwisko;
            bool obecnosc;
            cout << "kto (nazwisko): ";
            cin >> nazwisko;
            cout << "obecnosc (1/0): ";
            cin >> obecnosc;
            
            if (ustawObecnoscMenu(listaStudentow, ileOsob, nazwisko, obecnosc)) {
                cout << "zmieniono.\n";
            } else {
                cout << "nie znaleziono.\n";
            }
        }
        else if (wybor == 3) {
            drukujListeMenu(listaStudentow, ileOsob);
        }
        else if (wybor == 4) {
            string nazwisko;
            cout << "podaj nazwisko do usuniecia: ";
            cin >> nazwisko;
            
            if (usunOsobeMenu(listaStudentow, ileOsob, nazwisko)) {
                cout << "usunieto bez dziur.\n";
            } else {
                cout << "nie znaleziono.\n";
            }
        }
        else if (wybor == 5) {
            string stare, noweN, noweI;
            int nowyIndeks;
            cout << "podaj nazwisko osoby do edycji: ";
            cin >> stare;
            cout << "podaj nowe imie: ";
            cin >> noweI;
            cout << "podaj nowe nazwisko: ";
            cin >> noweN;
            cout << "podaj nowy indeks: ";
            cin >> nowyIndeks;
            
            if (edytujOsobeMenu(listaStudentow, ileOsob, stare, noweN, noweI, nowyIndeks)) {
                cout << "zaktualizowano.\n";
            } else {
                cout << "nie ma takiego studenta.\n";
            }
        }

    } while (wybor != 0);

    return 0;
}