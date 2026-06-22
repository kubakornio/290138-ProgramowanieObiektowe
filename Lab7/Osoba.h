#ifndef OSOBA_H
#define OSOBA_H
#include <string>
#include "ISerializable.h"
#include "IEksportowalny.h"

using namespace std;

class Osoba : public ISerializable, public IEksportowalny {
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
    virtual map<string, string> eksportuj() override;
};
#endif