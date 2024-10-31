
#ifndef UNTITLED6_HELPERFUNCTIONS_H
#define UNTITLED6_HELPERFUNCTIONS_H
#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <sstream>
#include<QString>
using namespace std;
// Function to convert hex to binary
QString hexToBinary(const QString& hex);

// Function to convert a binary string to an integer
int binaryStringToInt(const QString& binaryString);

// Function to convert an integer to a binary string
QString intToBinaryString(int num);

// Function to convert an integer to hex (with width)
QString toHex(int number, int width);

// Function to convert a hexadecimal string to an integer
int hexToInt(const QString& hexStr);

QString addTwoComplement(const  QString &bin1, const QString &bin2);

#endif  // CONVERTER_H

#endif //UNTITLED6_HELPERFUNCTIONS_H
