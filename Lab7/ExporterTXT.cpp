#include "ExporterTXT.h"
#include <fstream>
#include <iostream>

using namespace std;

void ExporterTXT::wykonajExport(IEksportowalny* obj, string nazwaPliku) {
    ofstream plik(nazwaPliku);
    
    if (plik.is_open()) {
        // pobieramy mape z obiektu
        map<string, string> dane = obj->eksportuj();
        
        map<string, string>::iterator it;
        
        for (it = dane.begin(); it != dane.end(); ++it) {
            // it->first to nazwa danych it->second to wartosc
            plik << it->first << ":" << it->second << "\n";
        }
        
        plik.close();
        cout << "Wyeksportowano do TXT: " << nazwaPliku << "\n";
    } else {
        cout << "Blad otwarcia pliku TXT\n";
    }
}