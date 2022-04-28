#include "Utils.h"

bool is_operator(char op)
{
	if (op == '+' || op == '-' || op == '*' || op == '/')
	{
		return true;
	}
	return false;
}

bool is_operand(char op)
{
	if (op >= '0' && op <= '9')
	{
		return true;
	}
	return false;
}

int calc(char op, int a, int b)
{
	if (op == '+')
	{
		return a + b;
	}

	if (op == '-')
	{
		return a - b;
	}

	if (op == '*')
	{
		return a * b;
	}

	if (op == '/')
	{
		return a / b;
	}

	return -1;
}