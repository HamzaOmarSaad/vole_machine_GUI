#include <QApplication>
#include <QWidget>
#include "Machinesimulator.h"
using namespace std;


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MachineSimulator simulator;
    simulator.setWindowTitle("Machine Simulator");
    simulator.show();
    return app.exec();
}
