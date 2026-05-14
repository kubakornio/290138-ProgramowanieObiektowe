#ifndef OSOBA_H
#define OSOBA_H
#include <string>

using namespace std;

class Osoba {
protected:
    string imie;
    string nazwisko;
    int wzrost;
    string data_urodzenia;

public:
    Osoba();
    void setImie(string wartosc);
    void setNazwisko(string wartosc);
    void setWzrost(int wartosc);
    void setDataUrodzenia(string wartosc);

    string getImie();
    string getNazwisko();
    
    void drukuj(); 
};
#endif