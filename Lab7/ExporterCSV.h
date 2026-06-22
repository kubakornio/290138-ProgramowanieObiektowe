#ifndef EXPORTERCSV_H
#define EXPORTERCSV_H
#include "IExporter.h"
#include <string>

using namespace std;

class ExporterCSV : public IExporter {
public:
    void wykonajExport(IEksportowalny* obj, string nazwaPliku) override;
};
#endif