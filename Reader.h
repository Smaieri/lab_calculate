#include "iostream"
#include "string"
#include "List.h"
using namespace std;

#ifndef READER
#define READER

class Reader{

private:
	const string aTrue,
				aFalse,
				aNot,
				aAnd,
				aXor,
				aOr;

	string s;
	int numberLexem(string &, int );
	bool makeWithDelim(string &);
	string nextLexem(string &);
	bool isBinaryOperator(string );
	bool isUnaryOperator(string );
	bool isVar(string );
	bool isValue(string );
	bool isExpression(string );
	string correct(string & );
public:
	Reader():aTrue("true"),	aFalse("false"),aNot("not"),aAnd("and"),aXor("xor"),aOr("or"){}
	string read(istream & );
	string read(string & );
	
	~Reader();

};
#endif