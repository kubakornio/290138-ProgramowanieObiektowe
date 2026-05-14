#include "Student.h"
#include <iostream>

using namespace std;

Student::Student() {
    nr_indeksu = 0;
}

void Student::setNrIndeksu(int w) {
    if (w >= 100000 && w <= 999999) nr_indeksu = w;
}

int Student::getNrIndeksu() { return nr_indeksu; }

void Student::drukuj() {
    cout << "STUDENT: " << imie << " " << nazwisko << " | Indeks: " << nr_indeksu << " | ur: " << data_urodzenia << " | " << wzrost << "cm";
}