//
// Created by a on 10/22/2024.
//

#ifndef VOLEMACHINE_MEMORYUNIT_H
#define VOLEMACHINE_MEMORYUNIT_H

// memoryUnit.h
#ifndef MEMORYUNIT_H
#define MEMORYUNIT_H

#include "iostream"
#include <bitset>
#include <iomanip>
#include <QString>
using namespace std;

// Function declarations
QString hexToBinary(const QString& hex);
QString toHex(int number, int width = 2);

class memoryUnit {
public:
    QString address;
    QString hex;
    QString binary;
    static int  count ;


    memoryUnit(const QString data);
    memoryUnit();
};

#endif // MEMORYUNIT_H


#endif //VOLEMACHINE_MEMORYUNIT_H
