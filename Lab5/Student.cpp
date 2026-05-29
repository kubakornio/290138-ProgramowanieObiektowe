#include "Student.h"

using namespace std;

Student::Student() {
    nr_indeksu = 0;
}

void Student::setNrIndeksu(int w) {
    if (w >= 100000 && w <= 999999) nr_indeksu = w;
}

int Student::getNrIndeksu() { return nr_indeksu; }

string Student::serialize() {
    return "STUDENT: " + imie + " " + nazwisko + " | Indeks: " + to_string(nr_indeksu) + " | ur: " + data_urodzenia + " | " + to_string(wzrost) + "cm";
}