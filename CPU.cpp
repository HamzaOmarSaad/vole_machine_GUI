// CPU.cpp
#include "iostream"
#include "CPU.h"
#include "mainMemorey.h"
#include "helperFunctions.h"

// Constructor definition
CPU::CPU(int i, mainMemory & r, CU &c)  {
    indecator = i;
    Register = & r;
    cu=&c;
}

void CPU::fetch(mainMemory & memory) {


    fetchedDate=(memory.memory[indecator].hex + memory.memory[indecator+1].hex);
    indecator+=2;

}

void CPU::decode() {


    opCode=fetchedDate[0];
    R=fetchedDate[1];
    X=fetchedDate[2];
    Y=fetchedDate[3];

}


bool isValidHexChar(QChar c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}


void CPU::execute(mainMemory &memory) {

    if (!isValidHexChar(R[0]) || !isValidHexChar(X[0]) || !isValidHexChar(X[0])) {
        return;
    }

    if (opCode == "1") {
        cu->OP1(memory, Register, R, X, Y);
    } else if (opCode == "2") {
        cu->OP2(memory, Register, R, X, Y);
    } else if (opCode == "3") {
        cu->OP3(memory, Register, R, X, Y);
    } else if (opCode == "4") {
        cu->OP4(memory, Register, R, X, Y);
    } else if (opCode == "5") {
        cu->OP5(memory, Register, R, X, Y);
    } else if (opCode == "6") {
        cu->OP6(memory, Register, R, X, Y);
    } else if (opCode == "7") {
        cu->OP7(memory, Register, R, X, Y);
    } else if (opCode == "8") {
        cu->OP8(memory, Register, R, X, Y);
    } else if (opCode == "9") {
        cu->OP9(memory, Register, R, X, Y);
    } else if (opCode == "A" || opCode == "a") {
        cu->OPa(memory, Register, R, X, Y);
    } else if (opCode == "b" || opCode == "B") {
        cu->OPb(memory, Register, R, X, Y, indecator);
    } else if (opCode == "C" || opCode == "c") {
        cu->OPc(memory, Register, R, X, Y);
    }

}


void CPU::runOneCycle(mainMemory &memory) {
    fetch(memory);
    decode();
    execute(memory);

}

void CPU::runAll(mainMemory &memory) {

    while (opCode != "c" && opCode != "c") {

        runOneCycle(memory);
    }

}








