

#ifndef VOLEMACHINE_MAINMEMOREY_H
#define VOLEMACHINE_MAINMEMOREY_H
// mainMemory.h
#ifndef MAINMEMORY_H
#define MAINMEMORY_H

#include "iostream"
#include "vector"
#include "memoryUnit.h"
#include <iomanip>
#include<QVector>

using namespace std;

class mainMemory {
public:

    QVector<memoryUnit> memory;
    int maxSize;

    mainMemory();           // Default constructor
    mainMemory(int m);
        // Parameterized constructor
    void addData( QString input,int &currentInstructionPointer);         // Function to add data
    void clearData();       // Function to clear data
    int getSize() ;
};

#endif // MAINMEMORY_H

#endif //VOLEMACHINE_MAINMEMOREY_H

