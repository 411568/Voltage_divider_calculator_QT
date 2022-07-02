#include "additionalFunctions.h"


bool isNumber(const std::string inStr)
{
	bool answer{ true };
	int countDots{ 0 };

	for (int i = 0; i < inStr.length(); ++i)
	{
		if (isdigit(inStr[i]) == false)
		{
			if (i == 0)
			{
				answer = false;
				break;
			}
			else if (countDots > 0)
			{
				answer = false;
				break;
			}
			else if (inStr[i] == '.')
			{
				countDots++;
			}
		}
	}

	return answer;
}