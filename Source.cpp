//input_string is an example or expression that we need to process
//stack is the store place
//output_string is the output data
#include <iostream>
#include <string.h>
#include <stdexcept>
#include "PPx Calculator.h"//Polish Postfix Calculator

void instruction()
{
	std::cout << "Operations can be used:\n" <<
		"* arithmetics: +, -, *, / , ^\n" <<
		"* trigonometric : sin, cos, tg, ctg, Arch\n" <<
		"* logarithmic : ln, lg, sqrt\n"<<
		"It works with numbers, not with letters"
		<< std::endl;
}

int main()
{
	setlocale(LC_ALL, "English");
	instruction();
	std::cout << "Please, enter your expression: " << std::endl;
	postfix_calculating();//polish postfix calculator
	return 0;
}