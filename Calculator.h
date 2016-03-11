#include <iostream>
#include "Stack.h"
#include "List.h"

#ifndef CALCULATOR
#define CALCULATOR

class Calculator {

private:
	const string aTrue,
				aFalse;
	Stack st;
	List polN;

	void polishNotation (string &);
	string nextLexem(string &);
	bool isOperator(string);
	int priority(string);
	bool isThereAVar(const string &, const string & );
	int howManyVars(const string &);
	string replace (string , string , string);	
	string calculatePolN (string);
	bool calculateWithVars ( string );

public:

	Calculator():aTrue("true"),aFalse("false"){}	
	string calculate (string);
	string calculate (istream&);
	
};
#endif