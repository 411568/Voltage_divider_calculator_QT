#include "Voltage_divider_calculator_QT.h"
#include "VoltageDivider.h"

#include <iostream>
Voltage_divider_calculator_QT::Voltage_divider_calculator_QT(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("Voltage divider calculator");
    this->setWindowIcon(QIcon("icon.png"));
}

Voltage_divider_calculator_QT::~Voltage_divider_calculator_QT()
{}


void Voltage_divider_calculator_QT::on_calculateButton_clicked()
{
    QString inputString;
    std::string inputStandard;
    std::vector<std::string> outputText;

    //get input voltage
    inputString = ui.inputEdit->displayText();
    inputStandard = inputString.toStdString();
    if (isNumber(inputStandard) == false || stod(inputStandard) <= 0.0)
    {
        ui.outputText->clear();
        ui.outputText->setText("Please enter valid values!");
        return;
    }
    inputVoltage = stod(inputStandard);

    //get output voltage
    inputString = ui.outputEdit->displayText();
    inputStandard = inputString.toStdString();
    if (isNumber(inputStandard) == false || stod(inputStandard) >= inputVoltage || stod(inputStandard) <= 0.0)
    {
        ui.outputText->clear();
        ui.outputText->setText("Please enter valid values!");
        return;
    }
    outputVoltage = stod(inputStandard);

    //object for calculations
    VoltageDivider voltDiv(inputVoltage, outputVoltage);
    
    //get output text
    outputText = voltDiv.calculateValues();

    //output the text
    ui.outputText->clear();
    for (auto line : outputText)
    {
		ui.outputText->append(QString::fromStdString(line));
    }
}
