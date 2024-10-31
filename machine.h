#ifndef MACHINE_H
#define MACHINE_H

#include <vector>
#include <qapplication.h>
#include "mainMemorey.h"
#include "helperFunctions.h"
#include"CU.h"


using namespace std;

class machine {

public:
    string fetchedDate;
    string opCode="";
    string R;
    string X;
    string Y;
    bool halted ;
    int indecator;
    mainMemory*  Register;
    CU*  cu;

    machine( int i, mainMemory & r,CU &  c){

        halted= false ;
        indecator = i;
        Register = & r;
        cu=&c;
    };
    void fetch(mainMemory & memory)
    {
        fetchedDate=(memory.memory[indecator].hex + memory.memory[indecator+1].hex);
        indecator+=2;
    };
    void decode()
    {
        opCode=fetchedDate[0];
        R=fetchedDate[1];
        X=fetchedDate[2];
        Y=fetchedDate[3];
    }
    bool isValidHexChar(char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
    }
    void execute(mainMemory &memory)
    {
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

    void executeOneCycle(mainMemory &memory) {
        fetch(memory);
        decode();
        execute(memory);
    }

    void runAll(mainMemory &memory) {


        while (opCode != "c" && opCode != "c") {

        executeOneCycle(memory);

        }
    }
    void halt() {
        if(opCode != "c" && opCode != "c")
        {
            QApplication::quit;
        }
    }

    void reset() {
        halted = false;
        indecator = 0;
        Register->clearData();

    }

};


#endif // MACHINE_H
