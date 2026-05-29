#include "ISerializable.h"
#include <iostream>

using namespace std;

void drukuj(ISerializable *obj) {
    cout << obj->serialize() << endl;
}   