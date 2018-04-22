/*
* Main.cpp
*/

#include "LinkedStack.h"

#include <iostream>
using namespace std;


//Function to split the string from the console
char ** ReadRpnFromConsole(int &len)
{
	char ** rpn = new char*[100]();

	int rpn_lenght = 0;
	char * currentPart= new char[100]();
	char currSymbol = cin.get();

	int currPartLenght = 0;

	while (currSymbol!='\n')
	{
		if (currSymbol != ' ')
		{
			currentPart[currPartLenght] = currSymbol;
			currPartLenght++;
		}
		else
		{
			currentPart[currPartLenght] = '\0';
			rpn[rpn_lenght] = currentPart;
			rpn_lenght++;
			currPartLenght = 0;
			currentPart = new char[100]();
		}
		currSymbol = cin.get();
	}
	currentPart[currPartLenght] = '\0';
	rpn[rpn_lenght] = currentPart;
	rpn_lenght++;

	len = rpn_lenght;
	return rpn;
}

//Return true if a number is integer
bool IsInteger(double num)
{
	return num == ceil(num);
}

//Reports when you try to use % with non integer values
void ReportModError()
{
	cout << "Error! You cannot use '%' with non integer values!" << endl;
}

void ReportDivisionByZero()
{
	cout << "Error! You cannot devide by Zero!" << endl;
}

//Reports if the rpn is incomplete
void ReportNotCompleteRpn()
{
	cout << "Error! Incomplete expression!" << endl;
}

double Calculate(char ** rpn, int length)
{
	LinkedStack stack;
	bool success = true;
	for (size_t i = 0; i < length; i++)
	{
		switch (rpn[i][0])
		{
		case '+' :
			if (stack.HasMore()) 
			{
				double s_operand = stack.pop();
				double f_operand = stack.pop();
				stack.push(f_operand + s_operand);
			}
			else
			{
				ReportNotCompleteRpn();
				success = false;
			}
			break;
		case '-' :
			if (stack.HasMore())
			{
				double s_operand = stack.pop();
				double f_operand = stack.pop();
				stack.push(f_operand - s_operand);
			}
			else
			{
				ReportNotCompleteRpn();
				success = false;
			}
			break;
		case '*' :
			if (stack.HasMore())
			{
				double s_operand = stack.pop();
				double f_operand = stack.pop();
				stack.push(f_operand * s_operand);
			}
			else
			{
				ReportNotCompleteRpn();
				success = false;
			}
			break;
		case '/' :
			if (stack.HasMore())
			{
				double s_operand = stack.pop();
				if (s_operand == 0)
				{
					ReportDivisionByZero();
					success = false;
					break;
				}
				double f_operand = stack.pop();
				
				stack.push(f_operand / s_operand);
			}
			else
			{
				ReportNotCompleteRpn();
				success = false;
			}
			break;
		case '%' :
			if (stack.HasMore())
			{
				double s_operand = stack.pop();
				if (!IsInteger(s_operand))
				{
					ReportModError();
					success = false;
					break;
				}
				double f_operand = stack.pop();
				if (!IsInteger(f_operand))
				{
					ReportModError();
					success = false;
					break;
				}
				stack.push(f_operand * s_operand);
			}
			else
			{
				ReportNotCompleteRpn();
				success = false;
			}
			break;
		default:
			double number;
			if (sscanf_s(rpn[i], "%lf", &number) == 1)
			{
				stack.push(number);
			}
		}

		if (!success) break;
	}

	if (!success)
	{
		return 0.0;
	}

	if (stack.HasMore())
	{
		ReportNotCompleteRpn();
		return 0.0;
	}

	return stack.peek();

}

int main()
{
	int length;
	char**  testExpr = ReadRpnFromConsole(length);
	cout << Calculate(testExpr,length) << endl;
	return 0;
}
