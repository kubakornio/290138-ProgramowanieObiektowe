#include "ExporterCSV.h"
#include <fstream>
#include <iostream>

using namespace std;

void ExporterCSV::wykonajExport(IEksportowalny* obj, string nazwaPliku) {
    ofstream plik(nazwaPliku);
    
    if (plik.is_open()) {
        map<string, string> dane = obj->eksportuj();
        map<string, string>::iterator it;
        
        bool pierwszy = true;
        for (it = dane.begin(); it != dane.end(); ++it) {
            if (!pierwszy) plik << ",";
            plik << it->first;
            pierwszy = false;
        }
        plik << "\n";
        
        pierwszy = true;
        for (it = dane.begin(); it != dane.end(); ++it) {
            if (!pierwszy) plik << ",";
            plik << it->second;
            pierwszy = false;
        }
        plik << "\n";
        
        plik.close();
        cout << "Wyeksportowano do CSV: " << nazwaPliku << "\n";
    } else {
        cout << "Blad otwarcia pliku CSV\n";
    }
}