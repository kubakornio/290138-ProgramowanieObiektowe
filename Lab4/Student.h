#ifndef STUDENT_H
#define STUDENT_H
#include "Osoba.h"

class Student : public Osoba {
private:
    int nr_indeksu;
public:
    Student();
    void setNrIndeksu(int wartosc);
    int getNrIndeksu();
    
    void drukuj(); 
};
#endif