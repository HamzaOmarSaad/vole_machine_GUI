#include "helperFunctions.h"
#include <QString>
#include <QDebug>
#include <QBitArray>

// Function to convert hex to binary
QString hexToBinary(const QString& hex) {
    QString binary;
    for (QChar hexChar : hex) {
        // Convert each hex character to an integer
        int value = (hexChar.isDigit()) ? hexChar.digitValue() : (hexChar.toUpper().unicode() - 'A' + 10);

        // Convert the integer to a binary string (4 bits)
        QString binarySegment = QString("%1").arg(value, 4, 2, QChar('0'));  // Pad to 4 bits
        binary += binarySegment;
    }
    return binary;
}

// Function to convert a binary string to an integer
int binaryStringToInt(const QString& binaryString) {
    return binaryString.toInt(nullptr, 2);  // Convert binary string to an int (base 2)
}

// Function to convert an integer to a binary string
QString intToBinaryString(int num) {
    return QString("%1").arg(num, 8, 2, QChar('0'));  // Convert integer to binary with 8-bit width
}

// Function to convert an integer to hex (with width)
QString toHex(int number, int width) {
    return QString("%1").arg(number, width, 16, QChar('0')).toUpper();  // Convert to hex with padding
}

// Function to convert a hexadecimal string to an integer
int hexToInt(const QString& hexStr) {
    bool ok;
    int decimalValue = hexStr.toInt(&ok, 16);
    if (!ok) {
        qDebug() << "Invalid hexadecimal input.";
        return -1;
    }
    return decimalValue;
}

// Function to add two binary numbers using two's complement
QString addTwoComplement(const QString &bin1, const QString &bin2) {
    // Convert the binary strings to integers
    int num1 = bin1.toInt(nullptr, 2);
    int num2 = bin2.toInt(nullptr, 2);
    int sum = num1 + num2;

    // Use 8 bits for the two's complement representation
    QString result = QString("%1").arg(sum & 0xFF, 8, 2, QChar('0'));  // Mask to get the last 8 bits
    return result;
}
