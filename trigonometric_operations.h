#pragma once
#include <iostream>

std::string sin(std::string expression)//sine
{
	return std::to_string(sin(stod(expression)));
}

std::string cos(std::string expression)//cosine
{
	return std::to_string(cos(stod(expression)));
}

std::string tg(std::string expression)//tangent
{
	return std::to_string(double(sin(stod(expression)) / cos(stod(expression))));
}

std::string ctg(std::string expression)//cotangent
{
	return std::to_string(double(cos(stod(expression)) / sin(stod(expression))));
}

std::string Arch(std::string expression)//hyperbolic cosine
{
	return std::to_string(cosh(stod(expression)));
}
