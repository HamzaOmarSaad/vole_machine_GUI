#include "CU.h"
#include "helperFunctions.h"
#include "mainMemorey.h"
#include<QApplication>

using namespace std;

CU::CU()
{};

// Convert std::string to QString
QString toQString(const std::string &str) {
    return QString::fromStdString(str);
}

// Convert QString to std::string
std::string toStdString(const QString &qStr) {
    return qStr.toStdString();
}

void CU::OP1(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y) {
    QString address = X + Y;
    Register->memory[QString(R).toInt()].hex = memory.memory[hexToInt(address)].hex;
    Register->memory[QString(R).toInt()].binary = memory.memory[hexToInt(address)].binary;
}

void CU::OP2(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y) {
    Register->memory[QString(R).toInt()].hex = X + Y;
    Register->memory[QString(R).toInt()].binary = hexToBinary(X + Y);
}

void CU::OP3(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y) {
    memory.memory[hexToInt(X + Y)].hex = Register->memory[QString(R).toInt()].hex;
    memory.memory[hexToInt(X + Y)].binary = Register->memory[QString(R).toInt()].binary;
}

void CU::OP4(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y) {
    Register->memory[hexToInt(Y)].hex = Register->memory[hexToInt(X)].hex;
    Register->memory[hexToInt(Y)].binary = Register->memory[hexToInt(X)].binary;
}

void CU::OP5(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y) {
    QString res = addTwoComplement(Register->memory[hexToInt(X)].binary, Register->memory[hexToInt(Y)].binary);
    memoryUnit::count = -1;
    Register->memory[hexToInt(R)].binary = res;
    Register->memory[hexToInt(R)].hex = toHex(res.toInt(nullptr, 2));
}

void CU::OP6(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y) {
    int num1 = binaryStringToInt(Register->memory[hexToInt(X)].binary);
    int num2 = binaryStringToInt(Register->memory[hexToInt(Y)].binary);
    int result = num1 | num2;

    Register->memory[hexToInt(R)].binary = intToBinaryString(result);
    Register->memory[hexToInt(R)].hex = toHex(result);
}

void CU::OP7(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y) {
    QString result;
    QString num1 = Register->memory[hexToInt(X)].binary;
    QString num2 = Register->memory[hexToInt(Y)].binary;

    for (int i = 0; i < num1.length(); ++i) {
        result += (num1[i] == num2[i] && num1[i] == '0') ? '0' : '1';
    }

    Register->memory[hexToInt(R)].binary = result;
    Register->memory[hexToInt(R)].hex = toHex(binaryStringToInt(result));
}

void CU::OP8(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y) {
    int num1 = binaryStringToInt(Register->memory[hexToInt(X)].binary);
    int num2 = binaryStringToInt(Register->memory[hexToInt(Y)].binary);
    int result = num1 & num2;

    Register->memory[hexToInt(R)].binary = intToBinaryString(result);
    Register->memory[hexToInt(R)].hex = toHex(result);
}

void CU::OP9(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y) {
    int num1 = binaryStringToInt(Register->memory[hexToInt(X)].binary);
    int num2 = binaryStringToInt(Register->memory[hexToInt(Y)].binary);
    int result = num1 ^ num2;

    Register->memory[hexToInt(R)].binary = intToBinaryString(result);
    Register->memory[hexToInt(R)].hex = toHex(result);
}

void CU::OPa(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y) {
    QString x = Register->memory[hexToInt(R)].binary;
    QString rotated;

    for (int i = 0; i < Y.toInt(); ++i) {
        rotated = x[x.length() - 1] + x.left(x.length() - 1);
        x = rotated;
    }

    Register->memory[hexToInt(R)].binary = rotated;
    Register->memory[hexToInt(R)].hex = toHex(binaryStringToInt(rotated));
}

void CU::OPb(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y, int &indicator) {
    if (memory.memory[0].binary == memory.memory[QString(R).toInt()].binary) {
        QString x = X + Y;
        indicator = hexToInt(x);
    }
}

void CU::OPc(mainMemory &memory, mainMemory *Register, const QString &R, const QString &X, const QString &Y) {
    QApplication::quit;
}
