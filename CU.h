#ifndef CU_H
#define CU_H

#include <string>
#include "mainMemorey.h"
#include<QString>

class CU {
public:
    CU();



    void OP1(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y);
    void OP2(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y);
    void OP3(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y);
    void OP4(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y);
    void OP5(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y);
    void OP6(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y);
    void OP7(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y);
    void OP8(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y);
     void OP9(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y);
    void OPa(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y);
    void OPb(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y,int & indecator);
    void OPc(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y);






};

#endif // CU_H
