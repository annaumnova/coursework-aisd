#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
//#include "Vector.h"//class vector doesn't work and it requires an overloading of [] operator...
#include <stack>
//#include "stack.h"//class stack doesn't work as well
#include "arithmetics_operations.h"//+, - , *, /, ^
//#include "trigonometric_operations.h"//sine, cosine, tangent, cotangent, Arch in tokens.h
//#include "logarithmic_operations.h"//ln, lg, sqrt in tokens.h
#include "tokens.h"

double postfix_calculating(std::string example = "0")
{
	std::string input_string;//the input string
	getline(std::cin, input_string);//input
	
	tokenize(input_string);//preparing the example to calculate
	
	std::stack<char> stack_with_operations;//there are operations
	std::stack<double> resulting_stack;//stack with result

	std::vector<double> vector_of_numbers;//to save numbers
	std::vector<char> output_string;//string with output data
	
	double number = 0;//some number
	char temp_symbol = '0';//the current symbol is a number
	int i = 0;//counter of input_string
	
	while (input_string.size() != i)//pass along the string
	{
		temp_symbol = input_string[i];//the current symbol of input

		//ASCII code of '0' is 48; codes of number is in [48;57]
		if ((input_string[i] < 58 && input_string[i] > 47) || (input_string[i] == '(' && input_string[i + 1] == '-'))//number? or open bracket and unary minus?
		{   
			bool unary_check;//check the unary minus or open bracket
			int begin_position;//the beginning
			
			if (input_string[i] == '(')
			{
				unary_check = true;//open bracket!
				i += 2;
				begin_position = i;//save this position
			}
			else//not found
			{
				unary_check = false;
				begin_position = i;//save this position
			}

			int ending_position = 0;//the end position 
			while ((input_string[i] < 58 && input_string[i] > 47) || input_string[i] == '.')
			{
				ending_position = i;
				i++;
			}

			if (unary_check) 
			{
				int first_pos = begin_position - 1;
				int last_pos = ending_position + 2 - begin_position;
				number = stod(input_string.substr(first_pos, last_pos));//newly constructed string

				vector_of_numbers.push_back(number);//add the number to save
				output_string.push_back('1');//mention the number        
				i++;
				temp_symbol = input_string[i];//the current symbol
			}
			else
			{
				int first_pos = begin_position;
				int last_pos = ending_position + 1 - begin_position;
				number = stod(input_string.substr(first_pos, last_pos));//same thing
				vector_of_numbers.push_back(number);
				output_string.push_back('1');				
				i--;
			}
		}

		if (temp_symbol == '*' || temp_symbol == '/' || temp_symbol == '+' || temp_symbol == '-' || temp_symbol == '(' || temp_symbol == '^')//process the symbols
		{
			while (!stack_with_operations.empty() && operation_priority(temp_symbol) 
				<= operation_priority(stack_with_operations.top()) && temp_symbol != '(')//compare the operators
			{
				output_string.push_back(stack_with_operations.top());//operations with higher priority
				stack_with_operations.pop();
			}
			stack_with_operations.push(temp_symbol);//with lower priority
		}

		if (temp_symbol == ')')//close bracket
		{
			while (stack_with_operations.top() != '(')//not open bracket
			{
				output_string.push_back(stack_with_operations.top());//add to output string
				stack_with_operations.pop();
			}
			stack_with_operations.pop();
		}
		i++;//counter
	}

	while (!stack_with_operations.empty())//transfer the operations to output
	{
		output_string.push_back(stack_with_operations.top());//add to output string
		stack_with_operations.pop();//clear the stack
	}
	
	std::cout << "\nPostfix notation: ";
	
	char check_the_number;//is it number or operation?									
	int position_in_vector = 0;//symbol's position in vector									
	
	for (int i = 0; i < output_string.size(); i++)//pass along the output string
	{
		check_the_number = output_string[i];//it is symbol
		if (check_the_number == '1')//number!
		{
			resulting_stack.push(vector_of_numbers[position_in_vector]);//mention the number
			std::cout << vector_of_numbers[position_in_vector] << ' ';//output
			position_in_vector++;
		}
		else										
		{
			std::cout << output_string[i] << ' ';
			double second_number = resulting_stack.top();//one, last
			resulting_stack.pop();
			double first_number = resulting_stack.top();//previous, first
			resulting_stack.pop();

			if (check_the_number == '/' && second_number == 0)
				throw std::invalid_argument("division by 0");//number/0 = ... 
			
			resulting_stack.push(operate_arithmetics_actions(check_the_number,first_number, second_number ));//calculating process
		}
	}
	
	std::cout << "\nResult: " << resulting_stack.top() << std::endl;//the result
	return resulting_stack.top();
}