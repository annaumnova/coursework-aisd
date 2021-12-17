#pragma once
#include <iostream>

int operation_priority(char operation)//priority of operations
{
	if (operation == '^')
		return 4;
	else if (operation == '*' || operation == '/')
		return 3;
	else if (operation == '+' || operation == '-')
		return 2;
	else if (operation == '(' || operation == ')')
		return 1;
	else 
		return 0;
}

int operate_arithmetics_actions(char operation, double number_one, double number_two)//it's what to do if chosen one of these operations
{
	switch (operation)
	{
	case '^': return pow(number_one, number_two); break;//exponentiation
	case '*': return (number_one * number_two); break;//multiplication
	case '/': return (number_one / number_two); break;//division
	case '-': return (number_one - number_two); break;//subtraction
	case '+': return (number_one + number_two); break;//addition 
	}
}

