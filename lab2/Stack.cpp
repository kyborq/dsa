#include "Stack.h"

Stack::Stack()
{
	for (int i = 0; i <= 100; i++)
		arr[i] = 0;
}

Stack::~Stack()
{

}

int Stack::pop()
{
	if (is_empty()) {
		std::cout << "Stack is drained" << std::endl << std::endl;
		return 0;
	}
	top--;
	//std::cout << arr[top] << std::endl;

	return arr[top];
}

void Stack::show()
{
	std::cout << std::endl << std::endl;
	if (is_empty()) {
		std::cout << "Stack is empty" << std::endl << std::endl;
		return;
	}

	for (int i = 0; i <= top; i++)
	{
		std::cout << arr[i] << " ";
	}

	std::cout << std::endl << std::endl;
}

bool Stack::is_empty()
{
	if (top < 0)
	{
		return true;
	}
	return false;
}

void Stack::push(int data)
{
	arr[top] = data;
	top++;
}