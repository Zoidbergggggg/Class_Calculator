
#include <iostream>


class Calculator
{
public: 

double FuncOfSum(double num1, double num2)
{
	return num1 + num2;
}
double FuncOfMultip(double num1, double num2)
{
	return num1 - num2;
}
double FuncOfSubtr(double num1, double num2)
{
	return num1 / num2;
}
double FuncOfDiv(double num1, double num2)
{
	return num1 * num2;
}

double Calculate(char op, double num1, double num2)
{
	double result = 0;
	if (op == '+')
	{
		result = FuncOfSum(num1, num2);
	}
	else if (op == '-')
	{
		result = FuncOfMultip(num1, num2);
	}
	else if (op == '/')
	{
		if (num2 == 0)
		{
			std::cout << "Sorry, but you can't do this operation with '0' \n";
		}
		else
		{
			result = FuncOfSubtr(num1, num2);
		}
	}
	else if (op == '*')
	{
		result = FuncOfDiv(num1, num2);
	}
	return result;
}

double Calculate(const char* op, const double* num1, const double* num2)
{
	if (op && num1 && num2)
	{
		return Calculate(*op, *num1, *num2);
	}
}

double& RefCalculate(double& refNum1, const double num2, const char op)
{
	refNum1 = Calculate(op, refNum1, num2);
	return refNum1;
}


};


int main()
{
	Calculator Calc;
	double num1;
	std::cout << "Please, input first number: \n";
	std::cin >> num1;

	double num2;
	std::cout << "Please, input second number: \n";
	std::cin >> num2;

	char op;
	std::cout << "Please, choose operation (+,/,-,*) \n";
	std::cin >> op;


	double result = Calc.Calculate(op, num1, num2);
	std::cout << "Result of your operation: " << result << "\n";

	double* Pnum1 = new double;
	double* Pnum2 = new double;
	char* P_op = new char;
	*Pnum1 = num1;
	*Pnum2 = num2;
	*P_op = op;

	result = Calc.Calculate(*P_op, *Pnum1, *Pnum2);
	std::cout << "Result of your operation with pointers: " << result << "\n";

	delete Pnum1;
	Pnum1 = nullptr;

	delete Pnum2;
	Pnum2 = nullptr;

	delete P_op;
	P_op = nullptr;

	result = Calc.RefCalculate(num1, num2, op);
	std::cout << "Result of your operation with references: " << result << "\n";
	return 0;
}