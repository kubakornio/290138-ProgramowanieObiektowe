#ifndef IEKSPORTOWALNY_H
#define IEKSPORTOWALNY_H
#include <map>
#include <string>

using namespace std;

class IEksportowalny {
public:
    virtual map<string, string> eksportuj() = 0;
    virtual ~IEksportowalny() {}
};
#endif