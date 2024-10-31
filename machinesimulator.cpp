#include "machinesimulator.h"
#include "./ui_machinesimulator.h"
#include "voleMachine.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include<QDebug>
#include "mainMemorey.h" // Ensure the spelling is consistent across your project
#include "CPU.h"

MachineSimulator::MachineSimulator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MachineSimulator)
    , currentInstructionPointer(0)
    ,ind (0)
    , memory(256)
    , registers(16)
    , controlUnit()
    , cpu(ind, registers, controlUnit)
    , vl(cpu, memory)
{
    setWindowTitle("Vole Machine");

    ui->setupUi(this); // Ensure UI is set up
    ui->inputLineEdit->setPlaceholderText("Enter instructions (e.g., 0x20 0x11)");
    ui->registerTable->setHorizontalHeaderLabels({"Register", "Value"});
    ui->memoryTable->setHorizontalHeaderLabels({"Address", "Value"});

    ui->memoryTable->setRowCount(256); // Ensure 256 rows for memory display
    ui->memoryTable->setColumnCount(2); // Address and Value columns

    ui->registerTable->setRowCount(16); // 16 rows for register display
    ui->registerTable->setColumnCount(2); // Register and Value columns


    for (int i = 0; i < 256; ++i) {
        if (i < vl.memory->memory.size()) {
            vl.memory->memory[i].hex = "00"; // Initialize within memory bounds
        }
    }
    for (int i = 0; i < 16; ++i) {
        if (i < cpu.Register->memory.size()) {
            cpu.Register->memory[i].hex = "00"; // Initialize within register bounds
        }
    }

}
MachineSimulator::~MachineSimulator()
{
    delete ui;
}


void MachineSimulator::processInput(int & currentInstructionPointer) {
    QString input = ui->inputLineEdit->text();
    QStringList instructions = input.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);

    for (int i = 0; i < instructions.size() && (currentInstructionPointer + i) < vl.memory->memory.size(); ++i) {
        QRegularExpression regex("^0x([0-9A-Fa-f]{2})");
        QRegularExpressionMatch match = regex.match(instructions[i]);

        if (match.hasMatch()) {
            // Extract only the two-digit hex number without "0x"
            QString hexNumber = match.captured(1);
            vl.memory->memory[currentInstructionPointer + i].hex = hexNumber; // Store just the hex digits
        } else {
            qDebug() << "Invalid input format for:" << instructions[i];
        }
    }

    currentInstructionPointer += instructions.size();
}


void MachineSimulator::on_loadButton_clicked()
{

    processInput(ind);
    updateMemoryDisplay();
    updateRegistersDisplay();
    ui->inputLineEdit->clear();
}


void MachineSimulator::updateMemoryDisplay() {
    ui->memoryTable->clearContents();
    int memorySize = vl.memory->memory.size();
    for (int i = 0; i < qMin(256, memorySize); ++i) {
        ui->memoryTable->setItem(i, 0, new QTableWidgetItem(QString::number(i, 16).toUpper()));
        ui->memoryTable->setItem(i, 1, new QTableWidgetItem(vl.memory->memory[i].hex));
    }
}

void MachineSimulator::updateRegistersDisplay() {
    ui->registerTable->clearContents();
    int registerCount = vl.cpu->Register->getSize();

    for (int i = 0; i < 16; ++i) {
        ui->registerTable->setItem(i, 0, new QTableWidgetItem(QString("R%1").arg(i)));
        if (i < registerCount) {
            ui->registerTable->setItem(i, 1, new QTableWidgetItem(vl.cpu->Register->memory[i].hex));
        } else {
            ui->registerTable->setItem(i, 1, new QTableWidgetItem("N/A"));
        }
    }
}

void MachineSimulator::on_oneCycleButton_clicked()
{
    vl.cpu->runOneCycle(memory);
    updateMemoryDisplay();
    updateRegistersDisplay();

}

void MachineSimulator::on_runAllButton_clicked()
{
    vl.cpu->runAll(memory);
    updateMemoryDisplay();
    updateRegistersDisplay();

}
void MachineSimulator::on_haltButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Exit", "Are you sure you want to exit?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QApplication::quit();
    }

}
void MachineSimulator::on_clearButton_clicked()
{
    vl.memory->clearData();

}



