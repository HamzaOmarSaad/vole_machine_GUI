#ifndef MACHINESIMULATOR_H
#define MACHINESIMULATOR_H

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <QLabel>
#include <QVector>
#include "volemachine.h" // Ensure this header is defined and includes necessary dependencies
#include "mainMemorey.h"
#include "CPU.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MachineSimulator;
}
QT_END_NAMESPACE

#include <QMainWindow> // Change QWidget to QMainWindow

class MachineSimulator : public QMainWindow // Change QWidget to QMainWindow
{
    Q_OBJECT
public:
    explicit MachineSimulator(QWidget *parent = nullptr);
    ~MachineSimulator();


private slots:
    void on_loadButton_clicked();
    void on_oneCycleButton_clicked();
    void on_runAllButton_clicked();
    void on_haltButton_clicked();
    void on_clearButton_clicked();
    void processInput(int & currentInstructionPointer);

private:
    Ui::MachineSimulator *ui;
    void updateRegistersDisplay(); // Updates the register display
    void updateMemoryDisplay();   // Updates the memory display

    int currentInstructionPointer = 0; // Track the execution instruction pointer
    int ind =0 ;
    mainMemory memory;                 // Memory object for the machine
    mainMemory registers;              // Registers memory
    CU controlUnit;                    // Control unit for managing instructions
    CPU cpu;                           // CPU that executes instructions
    voleMachine vl;                    // Main voleMachine instance managing CPU and memory

};

#endif // MACHINESIMULATOR_H
