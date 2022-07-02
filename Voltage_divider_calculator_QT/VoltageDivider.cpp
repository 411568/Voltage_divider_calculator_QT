#include "VoltageDivider.h"


VoltageDivider::VoltageDivider(const double inputV, const double outputV)
{
	//just to make sure...
	assert(inputV > outputV);
	assert(inputV > 0);
	assert(outputV > 0);

	inputVoltage = inputV;
	outputVoltage = outputV;
	ratio = outputVoltage / inputVoltage;
}


std::vector<double> VoltageDivider::calculateRatio(std::vector<int> resistors, double desiredRatio)
{
	std::vector<double> answer = { 0, 0, 0 };
	double tempRatio{ 0.0 };
	double outRatio{ 100.0 };
	int outRes1{};
	int outRes2{};

	for (auto res1 : resistors)
	{
		for (auto res2 : resistors)
		{
			tempRatio = (double)res1 / (res1 + res2);

			if (abs(tempRatio - desiredRatio) < abs(outRatio - desiredRatio))
			{
				outRatio = tempRatio;
				outRes1 = res1;
				outRes2 = res2;
			}
		}
	}

	answer[0] = outRatio;
	answer[1] = outRes1;
	answer[2] = outRes2;

	return answer;
}


std::vector<std::string> VoltageDivider::calculateValues()
{
	std::vector<std::string> answerVector;
	std::vector<double> temp;
	double outV{};
	int res1{};
	int res2{};
	std::string tempString;

	for (auto series : resistorValues)
	{
		tempString = "";
		tempString += series.first;

		temp = calculateRatio(series.second, ratio);
		outV = inputVoltage * temp[0];
		res1 = temp[1];
		res2 = temp[2];

		tempString += " output voltage: ";
		tempString += std::to_string(outV);
		tempString += " with resistors: ";
		tempString += std::to_string((int)res1) + " and " + std::to_string((int)res2);

		answerVector.push_back(tempString);
	}

	return answerVector;
}