#pragma once
#include <iostream>
#include "arithmetics_operations.h"//+, - , *, /, ^
#include "trigonometric_operations.h"
#include "logarithmic_operations.h"
#include <string>
//pi and exp are const

void tokenize(std::string& exapmle)
{
	for (int i = 0; i < exapmle.size(); i++)
	{
		if (exapmle[i] == 'e' && exapmle[i + 1] == 'x' && exapmle[i + 2] == 'p')//exp = 2.72
		{
			exapmle.erase(i, 3);
			exapmle.insert(i, "2.72");
		}
		if (exapmle[i] == 'p' && exapmle[i + 1] == 'i')//pi = 3.14 
		{
			exapmle.erase(i, 2);
			exapmle.insert(i, "3.14");
		}
		if (exapmle[i] == 's' && exapmle[i + 1] == 'i' && exapmle[i + 2] == 'n' && exapmle[i + 3] == '(')
		{
			int symbols = 0;//counter
			int position = i;//symbol's position
			i += 4;
			
			while (exapmle[i] != ')')//not close bracket
			{
				symbols++;//counter
				i++;
			}
			if (symbols == 0)
				std::invalid_argument("invalid_argument");//unexpected

			int begining_of_new_string;//start of old string
			int length_of_new_string;//length of string
			begining_of_new_string = i - symbols;
			length_of_new_string = symbols;
			
			std::string new_string = exapmle.substr(begining_of_new_string, length_of_new_string);//create a new string from old one
			exapmle.erase(position, (i - position + 1));//from position to length

			if (stod(sin(new_string)) < 0.0000000001)//
			{
				exapmle.insert(position, ")");
				exapmle.insert(position, sin(new_string));
				exapmle.insert(position, "(");
			}
			else
				exapmle.insert(position, sin(new_string));
			i = position;
		}

		if (exapmle[i] == 'ñ' && exapmle[i + 1] == 'o' && exapmle[i + 2] == 's' && exapmle[i + 3] == '(')//cosine
		{	
			int symbols = 0;
			int position = i;
			i += 4;
			
			while (exapmle[i] != ')')
			{
				symbols++;
				i++;
			}
			if (symbols == 0)
				std::invalid_argument("invalid_argument");//unexpected


			int begining_of_new_string;//start of old string
			int length_of_new_string;//length of string
			begining_of_new_string = i - symbols;
			length_of_new_string = symbols;

			std::string new_string = exapmle.substr(begining_of_new_string, length_of_new_string);
			exapmle.erase(position, (i - position + 1));

			if (stod(cos(new_string)) < 0.0000000001) 
			{
				exapmle.insert(position, ")");
				exapmle.insert(position, cos(new_string));
				exapmle.insert(position, "(");
			}
			else
				exapmle.insert(position, cos(new_string));
			
			i = position;
		}

		if (exapmle[i] == 't' && exapmle[i + 1] == 'g' && exapmle[i + 2] == '(')//tangent
		{		
			int symbols = 0;
			int position = i;
			i += 3;
			
			while (exapmle[i] != ')')
			{
				symbols++;
				i++;
			}
			if (symbols == 0)
				std::invalid_argument("invalid_argument");//unexpected

			int begining_of_new_string;//start of old string
			int length_of_new_string;//length of string
			begining_of_new_string = i - symbols;
			length_of_new_string = symbols;
			
			std::string new_string = exapmle.substr(begining_of_new_string, length_of_new_string);
			exapmle.erase(position, (i - position + 1));

			if (stod(tg(new_string)) < 0.0000000001)
			{
				exapmle.insert(position, ")");
				exapmle.insert(position, tg(new_string));
				exapmle.insert(position, "(");
			}
			else
				exapmle.insert(position, tg(new_string));
			
			i = position;
		}

		if (exapmle[i] == 'c' && exapmle[i + 1] == 't' && exapmle[i + 2] == 'g' && exapmle[i + 3] == '(')//cotangent
		{		
			int symbols = 0;
			int position = i;
			i += 4;
			
			while (exapmle[i] != ')')
			{
				symbols++;
				i++;
			}

			if (symbols == 0)
				std::invalid_argument("invalid_argument");//unexpected

			int begining_of_new_string;//start of old string
			int length_of_new_string;//length of string
			begining_of_new_string = i - symbols;
			length_of_new_string = symbols;

			std::string new_string = exapmle.substr(begining_of_new_string, length_of_new_string);
			exapmle.erase(position, (i - position + 1));

			if (stod(ctg(new_string)) < 0.0000000001)
			{
				exapmle.insert(position, ")");
				exapmle.insert(position, ctg(new_string));
				exapmle.insert(position, "(");
			}
			else
				exapmle.insert(position, ctg(new_string));
		
			i = position;
		}

		if (exapmle[i] == 'l' && exapmle[i + 1] == 'n' && exapmle[i + 2] == '(')//natural logarithm
		{	
			int symbols = 0;
			int position = i;
			i += 3;
			
			while (exapmle[i] != ')')
			{
				symbols++;
				i++;
			}

			if (symbols == 0)
				std::invalid_argument("invalid_argument");//unexpected

			int begining_of_new_string;//start of old string
			int length_of_new_string;//length of string
			begining_of_new_string = i - symbols;
			length_of_new_string = symbols;

			std::string new_string = exapmle.substr(begining_of_new_string, length_of_new_string);
			exapmle.erase(position, (i - position + 1));

			if (stod(ln(new_string)) < 0.0000000001)
			{
				exapmle.insert(position, ")");
				exapmle.insert(position, ln(new_string));
				exapmle.insert(position, "(");
			}
			else
				exapmle.insert(position, ln(new_string));
			
			i = position;
		}

		if (exapmle[i] == 'l' && exapmle[i + 1] == 'o' && exapmle[i + 2] == 'g' && exapmle[i + 3] == '(')//decimal logarithm
		{	
			int symbols = 0;
			int position = i;
			i += 4;
			
			while (exapmle[i] != ')') 
			{
				symbols++;
				i++;
			}

			if (symbols == 0)
				std::invalid_argument("invalid_argument");//unexpected
			
			int begining_of_new_string;//start of old string
			int length_of_new_string;//length of string
			begining_of_new_string = i - symbols;
			length_of_new_string = symbols;

			std::string new_string = exapmle.substr(begining_of_new_string, length_of_new_string);
			exapmle.erase(position, (i - position + 1));
		
			if (stod(log(new_string)) < 0.0000000001) 
			{
				exapmle.insert(position, ")");
				exapmle.insert(position, log(new_string));
				exapmle.insert(position, "(");
			}
			else
				exapmle.insert(position, log(new_string));
			
			i = position;
		}

		if (exapmle[i] == 's' && exapmle[i + 1] == 'q' && exapmle[i + 2] == 'r' && exapmle[i + 3] == 't' && exapmle[i + 4] == '(')//square root
		{		
			int symbols = 0;
			int position = i;
			i += 5;
			
			while (exapmle[i] != ')') 
			{
				symbols++;
				i++;
			}
		
			if (symbols == 0)
				std::invalid_argument("invalid_argument");//unexpected
			
			int begining_of_new_string;//start of old string
			int length_of_new_string;//length of string
			begining_of_new_string = i - symbols;
			length_of_new_string = symbols;
			
			std::string new_string = exapmle.substr(begining_of_new_string, length_of_new_string);
			exapmle.erase(position, (i - position + 1));
			exapmle.insert(position, sqrt(new_string));
			i = position;
		}

		if (exapmle[i] == 'A' && exapmle[i + 1] == 'r' && exapmle[i + 2] == 'c' && exapmle[i + 3] == 'h' && exapmle[i + 4] == '(')//hyperbolic cosine
		{
			int symbols = 0;
			int position = i;
			i += 5;
			
			while (exapmle[i] != ')')
			{
				symbols++;
				i++;
			}

			if (symbols == 0)
				std::invalid_argument("invalid_argument");//unexpected
			
			int begining_of_new_string;//start of old string
			int length_of_new_string;//length of string
			begining_of_new_string = i - symbols;
			length_of_new_string = symbols;
		
			std::string new_string = exapmle.substr(begining_of_new_string, length_of_new_string);
			exapmle.erase(position, (i - position + 1));
			
			if (stod(Arch(new_string)) < 0.0000000001)
			{
				exapmle.insert(position, ")");
				exapmle.insert(position, Arch(new_string));
				exapmle.insert(position, "(");
			}
			else
				exapmle.insert(position, Arch(new_string));
			
			i = position;
		}
	}
}
