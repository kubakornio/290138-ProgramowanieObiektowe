#include "Osoba.h"
#include "ListaObecnosci.h"
#include "InterfejsUzytkownika.h"

int main() {
    // glowna baza
    Osoba* tablicaOsob[10];
    ListaObecnosci tablicaList[2];
    
    InterfejsUzytkownika ui(tablicaOsob, 10, tablicaList, 2);
    ui.petla();
    
    return 0;
}