#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H
#include <string>

using namespace std;

class ISerializable {
public:
    virtual string serialize() = 0;
    virtual ~ISerializable() {} // wirtualny destruktor jest wymagany przy polimorfizmie
};

// globalna funkcja drukujaca cokolwiek co implementuje interfejs
void drukuj(ISerializable *obj);

#endif
