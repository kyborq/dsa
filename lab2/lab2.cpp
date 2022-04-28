// 11. В символьной строке записано выражение из цифр и
//     операций в постфиксной форме(знак операции после операндов).
//     Проверить правильность записи и найти значение выражения.
//     При наличии ошибок указать место первой из них.
//     Пример: выражение (2+3)*4-5*6 записывается в постфиксной
//     форме как 23+4*56*- (7).
// Подыганов Констатин Эдуардович ПС-22
// Visual Studio 2022

#include <iostream>
#include <fstream>
#include <string>
#include "Utils.h"
#include "Stack.h"

using namespace std;

int calc_postfix(string);

int validate_postfix(string);
void print_error(string, int, string);

int main()
{
	ifstream input;
	ofstream output;
	string postfix;
	int error;
	int result;

	setlocale(0, "");

	input.open("input.txt");
	output.open("output.txt");

	if (!input.is_open())
		return -1;

	getline(input, postfix);
	error = validate_postfix(postfix);

	if (error == -1)
	{
		result = calc_postfix(postfix);
		cout << postfix << " = " << result << endl;
		output << result;
	}
	else
	{
		output << "Ошибка вычислений";
	}
}

int calc_postfix(string postfix)
{
	Stack st;

	int len = (int)postfix.length();
	int answer = 0;

	for (int i = 0; i <= len; i++)
	{
		if (postfix[i] == ' ')
		{
			continue;
		}
		else if (is_operand(postfix[i]))
		{
			st.push(int(postfix[i] - '0'));
		}
		else if (is_operator(postfix[i]))
		{
			int b = st.pop();
			int a = st.pop();

			int result = calc(postfix[i], a, b);
			st.push(result);

			answer = result;
		}
	}

	return answer;
}

int validate_postfix(string postfix)
{
	int operands = 0;
	int operators = 0;

	if (postfix.length() == 0)
	{
		print_error(postfix, 0, "Выражение не может быть пустым");
		return 0;
	}

	if (postfix.length() == 1 && is_operand(postfix[0]))
	{
		print_error(postfix, 1, "Выражение не полное");
		return 1;
	}

	for (int i = 0; i < postfix.length(); i++)
	{
		if (postfix[i] == ' ')
		{
			continue;
		}
		else if (is_operator(postfix[i]))
		{
			if (operands < 2)
			{
				print_error(postfix, i, "Ожидался операнд");
				return i;
			}

			operators++;

			if (operands >= 2) {
				operands -= (2 - 1);
				operators -= 1;
			}
		} 
		else if (is_operand(postfix[i]))
		{
			if (operands - 1 > operators)
			{
				print_error(postfix, i, "Нужно больше операторов");
				return i;
			}

			operands++;
		}
		else
		{
			print_error(postfix, i, "Непредвиденная ошибка");
			return i;
		}
	}

	return -1;
}

void print_error(string postfix, int position, string message)
{
	cout << "Неверно написано выражение: " << endl;
	cout << postfix << endl;
	for (int i = 0; i < position; i++)
		cout << " ";
	cout << "^ - " << message << endl;
}