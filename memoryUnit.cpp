// memoryUnit.cpp
#include "memoryUnit.h"
using namespace std ;

int  memoryUnit::count=-1;



// Constructor for memoryUnit class
memoryUnit::memoryUnit(const QString data) {

    count++;
    hex = data;
    binary = hexToBinary(hex);
    address = toHex(count, 2);
}

memoryUnit::memoryUnit() {}
