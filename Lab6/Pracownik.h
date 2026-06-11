#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include "Osoba.h"

class Pracownik : public Osoba {
private:
    int id_pracownika;
public:
    Pracownik();
    void setId(int wartosc);
    int getId();
    
    virtual string serialize() override;
};
#endif