#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H
#include <string>

using namespace std;

class ISerializable {
public:
    virtual string serialize() = 0;
    virtual ~ISerializable() {}
};

void drukuj(ISerializable *obj);

#endif