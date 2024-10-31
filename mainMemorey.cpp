// mainMemory.cpp
#include "mainMemorey.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QRegularExpression>
#include <QMessageBox>

// Default constructor
mainMemory::mainMemory() {
    maxSize = 0;  // Initialize maxSize to zero
}

// Constructor implementation
mainMemory::mainMemory(int m) {
    maxSize = m;
    memory.resize(m);  // Resize the QVector to the maximum size

    for (int i = 0; i < m; ++i) {
        memory[i].hex = "00";  // Initialize each memory unit
    }
    memoryUnit::count = -1;
}



void mainMemory::addData(QString input,int &currentInstructionPointer) {
    QVector<QString> hexValues;
    int maxBytes = std::min(input.size() / 2, 256);

    hexValues.push_back(input.mid(2,4));
    hexValues.push_back(input.mid(7,10));

    for (int i = currentInstructionPointer; i < hexValues.size(); i++) {
        memory[i].hex = hexValues[i];
        memory[i].binary = hexToBinary(hexValues[i]);
    }

    currentInstructionPointer +=2;
}



void mainMemory::clearData() {
    memory.clear();  // Clear the QVector
    memory.resize(maxSize);  // Resize it back to the original size
    for (int i = 0; i < maxSize; ++i) {
        memory[i].hex = "00";  // Reinitialize each memory unit
    }
    memoryUnit::count = -1;
}

int mainMemory::getSize()
{
    return memory.size();

}
