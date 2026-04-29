#include "InterfejsUzytkownika.h"

int main() {
    // te dwie tablice zostaly teraz "obudowane" w interfejs i listy
    Osoba bazaOsob[10];
    ListaObecnosci tablicaList[2];

    InterfejsUzytkownika ui(bazaOsob, 10, tablicaList, 2);
    ui.petla();

    return 0;
}
