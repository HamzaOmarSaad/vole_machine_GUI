#ifndef VOLEMACHINE_VOLEMACHINE_H
#define VOLEMACHINE_VOLEMACHINE_H

// voleMachine.h
#include "mainMemorey.h"
#include "CPU.h"

#ifndef VOLEMACHINE_H
#define VOLEMACHINE_H




class voleMachine {
public:
    CPU* cpu;            // Instance of CPU
    mainMemory* memory;  // Instance of mainMemory

    // Constructor for voleMachine
    voleMachine(CPU & c, mainMemory & m);
};

#endif // VOLEMACHINE_H


#endif //VOLEMACHINE_VOLEMACHINE_H
