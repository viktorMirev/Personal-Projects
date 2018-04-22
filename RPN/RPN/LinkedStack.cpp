/*
	LinkedStack implementation
	62231
*/


#include "LinkedStack.h"
#include <iostream>


using namespace std;

LinkedStack::LinkedStack() {
	top = NULL;
}

void LinkedStack::copyFromStack(LinkedStack const& other)
{
	if (other.top != NULL)
	{

		StackElement *currToCopy = other.top;
		StackElement *currToSet = NULL;
		StackElement *prevSet = NULL;


		
		currToSet = new StackElement;
		currToSet->value = currToCopy->value;
		currToSet->prev = NULL;
		this->top = currToSet;
		prevSet = this->top;
		currToCopy= currToCopy->prev;

		while (currToCopy != NULL) {
			currToSet = new StackElement;
			currToSet->value = currToCopy->value;
			currToSet->prev = NULL;
			prevSet->prev = currToSet;
			prevSet = currToSet;
			currToCopy = currToCopy->prev;
		}
	}
	else
		this->top = NULL;
}

void LinkedStack::deleteStack() {
	StackElement *elementToDelete;
	while (top != NULL) {
		elementToDelete = top;
		top = top->prev;
		delete elementToDelete;
	}
}

LinkedStack::~LinkedStack() {
	deleteStack();
}


LinkedStack::LinkedStack(LinkedStack const& other) {
	copyFromStack(other);
}
LinkedStack& LinkedStack::operator=(LinkedStack const & other) {
	if (this != &other)
	{
		deleteStack();
		copyFromStack(other);
	}
	return *this;
}
bool LinkedStack::IsEmpty() const
{
	return this->top == NULL;
}

bool LinkedStack::HasMore() const
{
	if (top != NULL)
	{
		return top->prev != NULL;
	}
	return false;
}


double LinkedStack::peek() const {
	if (IsEmpty()) {
		cout << "Error! The Stack is empty!"<<endl;
		return 0;
	}

	return top->value;
}

void LinkedStack::push(double x) {
	StackElement* p = new StackElement;
	p->value = x;
	p->prev= top;
	top = p;
}

double LinkedStack::pop() {
	if (IsEmpty()) {
		cout << "Error!The Stack is empty!"<<endl;
		return 0;
	}

	StackElement* p = top;
	top = top->prev;
	double x = p->value;
	delete p;
	return x;
}
