#include "Osoba.h"
#include "ListaObecnosci.h"
#include "InterfejsUzytkownika.h"

int main() {
    // tworzymy pojemniki na dane
    Osoba tablicaOsob[10];
    ListaObecnosci tablicaList[2];
    
    // worzymy serce programu i dajemy mu dostep do pojemnikow
    InterfejsUzytkownika ui(tablicaOsob, 10, tablicaList, 2);
    
    // odpalamy glowna petle programu
    ui.petla();
    
    return 0;
}