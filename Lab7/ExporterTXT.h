#ifndef EXPORTERTXT_H
#define EXPORTERTXT_H
#include "IExporter.h"
#include <string>

using namespace std;

class ExporterTXT : public IExporter {
public:
    void wykonajExport(IEksportowalny* obj, string nazwaPliku) override;
};
#endif