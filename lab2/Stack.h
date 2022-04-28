#pragma once
#include<iostream>

class Stack
{
public:
	Stack();
	~Stack();

	int arr[100];
	int top = -1;

	int pop();
	void show();
	bool is_empty();
	void push(int data);
};

