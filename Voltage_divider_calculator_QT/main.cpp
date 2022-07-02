#include "Voltage_divider_calculator_QT.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Voltage_divider_calculator_QT w;
    w.show();
    return a.exec();
}
