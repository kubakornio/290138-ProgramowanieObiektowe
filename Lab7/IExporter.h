#ifndef IEXPORTER_H
#define IEXPORTER_H
#include "IEksportowalny.h"
#include <string>

using namespace std;

class IExporter {
public:
    virtual void wykonajExport(IEksportowalny* obj, string nazwaPliku) = 0;
    virtual ~IExporter() {}
};
#endif