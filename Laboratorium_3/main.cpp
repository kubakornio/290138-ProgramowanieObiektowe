#include "InterfejsUzytkownika.h"

int main() {
    // Te dwie tablice zostaly teraz "obudowane" w Interfejs i Listy
    Osoba bazaOsob[10];
    ListaObecnosci tablicaList[2];

    InterfejsUzytkownika ui(bazaOsob, 10, tablicaList, 2);
    ui.petla();

    return 0;
}