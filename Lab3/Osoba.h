#ifndef OSOBA_H
#define OSOBA_H

#include <string>

using namespace std;

class Osoba {
private:
    string imie;
    string nazwisko;
    int nr_indeksu;
    int wzrost;
    string data_urodzenia;

public:
    Osoba();

    // setery
    void setImie(string wartosc);
    void setNazwisko(string wartosc);
    void setNrIndeksu(int wartosc);
    void setWzrost(int wartosc);
    void setDataUrodzenia(string wartosc);

    // gettery
    string getImie();
    string getNazwisko();
    int getNrIndeksu();
    int getWzrost();
    string getDataUrodzenia();

    void drukujOsobe();
};

#endif