#ifndef OSOBA_H
#define OSOBA_H
#include <string>

class Osoba {
private:
    int nr_indeksu;
    std::string imie;
    std::string nazwisko;

public:
    Osoba();
    Osoba(int nr, std::string im, std::string naz);

    void setImie(std::string wartosc);
    std::string getImie();
    void setNazwisko(std::string wartosc);
    std::string getNazwisko();
    void setNrIndeksu(int nr);
    int getNrIndeksu();

    void wyswietl();
};
#endif