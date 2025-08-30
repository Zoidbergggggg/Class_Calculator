
#include <iostream>


class Calculator
{
public:
	void setResult(double StartValue)
	{
		result = StartValue;
	}
	double getResult() const
	{
		return result;
	}
	Calculator& Calculate(const double& value, const char& operation)
	{
		result = Calculate(operation, result, value);
		return *this;
	}
	Calculator& operator+ (double value)
	{
		return Calculate(value, '+');

	}
	Calculator& operator- (double value)
	{
		return Calculate(value, '-');

	}
	Calculator& operator* (double value)
	{
		return Calculate(value, '*');

	}
	Calculator& operator/ (double value)
	{
		return Calculate(value, '/');

	}

private:
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


	double result = 0;

};


int main()
{
	Calculator Calc;

	Calc.Calculate(5, '+').Calculate(2, '-').Calculate(7, '*').Calculate(4, '/');

	std::cout << "Result of your operations: " << Calc.getResult() << std::endl;

	Calc + 123;
	Calc - 13;
	Calc * 3;
	Calc / 5;

	std::cout << "Result of your operations: " << Calc.getResult() << std::endl;
	
	return 0;
}