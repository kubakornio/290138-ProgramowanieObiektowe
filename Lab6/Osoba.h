#ifndef OSOBA_H
#define OSOBA_H
#include <string>
#include "ISerializable.h"

using namespace std;

class Osoba : public ISerializable {
protected:
    string imie;
    string nazwisko;
    int wzrost;
    string data_urodzenia;

public:
    Osoba();
    virtual ~Osoba() {}
    
    void setImie(string wartosc);
    void setNazwisko(string wartosc);
    void setWzrost(int wartosc);
    void setDataUrodzenia(string wartosc);

    string getImie();
    string getNazwisko();
    
    virtual string serialize() override; 
};
#endif