#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Osoba {
public:
    int nrIndeksu;
    std::string imie;
    std::string nazwisko;
    bool obecnosc;

    Osoba();
    Osoba(int id, std::string im, std::string naz, bool ob); 
    void wyswietl();
};

#endif