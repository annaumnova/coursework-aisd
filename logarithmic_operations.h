#pragma once
#include <iostream>
std::string ln(std::string expression)//natural logarithm
{
	return std::to_string(log(stod(expression)));
}

std::string log(std::string expression)//decimal logarithm
{
	return std::to_string(log10(stod(expression)));
}

std::string sqrt(std::string expression)//square root
{
	return std::to_string(sqrt(stod(expression)));
}
