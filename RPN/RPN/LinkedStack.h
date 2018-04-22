#pragma once


struct StackElement {
	double value;

	//the element just below the current
	StackElement* prev;
};

class LinkedStack {


private:
	StackElement * top;
	void copyFromStack(LinkedStack const&);
	void deleteStack();
public:

	// default constructor 
	LinkedStack();


	// copy constructor 
	LinkedStack(LinkedStack const&);


	//destructor
	~LinkedStack();

	//operator = 
	LinkedStack& operator=(LinkedStack const &);

	//check of it has no elements
	bool IsEmpty() const;

	//check if the stack has at least 2 elements
	bool HasMore() const;

	// return the top element
	double peek() const;


	// include new element
	void push(double);

	// return the top element and remove it from the stack
	double pop();


};
