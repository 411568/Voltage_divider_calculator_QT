#pragma once

#include <QtWidgets/QWidget>
#include "ui_Voltage_divider_calculator_QT.h"
#include "additionalFunctions.h"

class Voltage_divider_calculator_QT : public QWidget
{
    Q_OBJECT

public:
    Voltage_divider_calculator_QT(QWidget* parent = nullptr);
    ~Voltage_divider_calculator_QT();


public slots:
    //when the button has been clicked (starts calculations and prints the output)
    void on_calculateButton_clicked();


private:
    Ui::Voltage_divider_calculator_QTClass ui;

    double inputVoltage{};
    double outputVoltage{};
};
