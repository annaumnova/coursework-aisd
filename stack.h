#pragma once
#include <iostream>
#include <string>
#include <stdexcept>

//class stack
template  <typename T>
class Stack
{
private:
	class Element
	{
	public:
		Element* previous;
		T data;//information part
		/*Element(char data)
		{
			this->data = data;
			previous = 0;
		}*/
		Element(const T elem) : data(elem), previous(0) {};//constructor Node's class
	};
	Element* top_element;//LIFO 
	size_t size_of_stack;

public:
	Stack() : top_element(0), size_of_stack(0) {};//costructor
	/*Stack(T data)//constructor 2; if consisted of one element
	{
		Element* tmp = new Element(data);
		top_element = tmp;
		size = 1;
	}*/
	~Stack() { while (top_element) pop(); }//destructor

	//void clear()
	//void peek()

	void pop()
	{
		if (size_of_stack)
		{
			Element* temp = top_element->previous;
			delete top_element;
			top_element = temp;
			size_of_stack--;
		}
		else {
			throw std::out_of_range("stack is empty");
		}
	}

	bool isEmpty()//check the emptiness
	{
		return getsize() == 0;
	}

	T top()//return the top element
	{
		if (isEmpty())
			throw std::out_of_range("The stack is empty");
		else {
			return top_element->data;
		}
	}

	size_t getsize()//get size of the stack
	{
		return size_of_stack;
	}

	void push(T data)//add new element
	{
		Element* temp = new Element(data);
		top_element->previous = temp;
		size_of_stack++;
	}
};