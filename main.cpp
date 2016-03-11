#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"
#include "Calculator.h"
#include "Reader.h"
#include <cstring>
using namespace std;

	int t (string&, Reader&, Calculator&, string, int ) ;
	void Test();

	void LabStart();
	void fromFile(char *);
	void fromScreen();
	void fromFile(char *);
	void infConsole();

int main(int argc, char **argv){
	
	if (argc < 2){

		infConsole();
		
	}else if ( strcmp(argv[1], "screen") == 0 ){
		LabStart();
		fromScreen();
		
	}else if( strcmp(argv[1], "file") == 0 ){
		LabStart();
		fromFile(argv[2]);

	}else if(  strcmp(argv[1], "test") == 0 ){
		LabStart();
		Test();

	}else {
		infConsole();
	}
	
	system ("pause");
	
return 0;
}

	void infConsole(){
	cout << "Arguments in Console:\n" <<
			"   screen information from screen\n" <<
			"   file information from file\n" <<
			"   test test\n" << endl;
}

	void Test(){

	cout << endl;

	string 		
		s1("true or false and true xor true"),
		s2("not false"),
		s3("(true and 3) or true"),
		s4("(false or true or false true) and false xor true and  not true"),
		s5("false and true xor true or false or true and true"),
		s6("not (true and true) or true or false or true and true"),
		s7("true or true and false xor true and  not false"),
		s8("true and true or false(true or false or false xor true)"),
		s9("true or not true or true or true or false xor true xor true xor false"),
		s10("false or false or  and true xor false and (true and false xor true)");


	string 
		answer1("false"),
		answer2("true"),
		answer3("There was incorrect data."),
		answer4("There was incorrect data."),
		answer5("true"),
		answer6("true"),
		answer7("false"),
		answer8("There was incorrect data."),
		answer9("true"),
		answer10("There was incorrect data.");

	Reader R;
	Calculator C;

	int count = 0;

	count = t(s1,R,C,answer1,1) + t(s2,R,C,answer2,2) + t(s3,R,C,answer3,3) + t(s4,R,C,answer4,4) + t(s5,R,C,answer5,5) + t(s6,R,C,answer6,6) + t(s7,R,C,answer7,7) + t(s8,R,C,answer8,8) + t(s9,R,C,answer9,9) + t(s10,R,C,answer10,10);
	
	cout << "\nThere were " << count << " correct answers." << endl;
}

	int t (string&s, Reader &R, Calculator &C, string correct, int i ) {

		cout << "Test. Number of " << i << ".InputData:\n" << s << endl;

		string result = R.read(s);
		string s1;
		s1 = C.calculate(result);

		cout << "After calculating, :" << s1 << endl;
		cout << "The correct answer is: "<< correct << endl;

		if (s1 == correct) {

			cout << "It is OK." << "\n" << endl;

			return 1;

		}else {

			cout << "It is NOT OK" <<  "\n" << endl;

			return 0;

		}

}

	void LabStart(){
	cout << "Victor Melnikov. K - 11. Lab 5 Calculator.\n" <<
		"Var 3. Logic Gates.\n"<<
		 "and, xor, or, not, true false."<<
		 "All you need - write an expresion with these expressions.\n\n" <<
		 "BNF\n"<<
		
"<InputData> ::= <Expression> \n\n" <<
"<Expression> ::=<ExpOper>|\n" <<
"\"(\"<ExpOper>\")\"|\n" <<
"<Expression><BinaryOperator><Expression>[<Expression><BinaryOperator><Expression>]|\n" <<
"<UnaryOperator>[<UnaryOperator>]\"(\"<Expression>\")\"|\n" <<
"<Expression><BinaryOperator><UnaryOperator>[<UnaryOperator>]\"(\"<Expression>\")\"\n\n" <<
"<ExpOper> ::=<BasicExp>|\n" <<
"<UnaryOperator>[<UnaryOperator>]<BasicExp>| \n" <<
"<ExpOper><BinaryOper><BasicOper>[<ExpOper><BinaryOper><BasicOper>] |\n" <<
"<ExpOper><BinaryOper><UnaryOperator>[<UnaryOperator>]<BasicOper>[<ExpOper><BinaryOper><UnaryOperator>[<UnaryOperator>]<BasicOper>]\n\n" <<
"<BasicExpr> ::= <value>|\n" <<
"<var>\n\n" <<
"<UnaryOperator> ::= \"not\"\n\n" <<
"<BinaryOperator>::= \"and\"|\n\n" <<
"\"xor\"|\n" <<
"\"or\"\n\n" <<
"<value> ::= \"true\"|\n" <<
"\"false\"\n\n" <<
"<var> ::= \"x\"|\n" <<
"\"y\"|\n" <<
"\"z\"\n" << endl;

		
}

	void fromScreen(){
	
		Calculator C;
	
		string rezult ;	

	cout << "Now write an expression\n" << endl;

	rezult = C.calculate(rezult);
	
	if (rezult != "")
			cout << "The rezult is:\n" << rezult;

	
}

	void fromFile(char *f){

	ifstream h(f);

	if( h.is_open() ){

		Calculator C;
		string rezult;		
		rezult = C.calculate ( h);
		if (rezult != "")
			cout << "The rezult is:\n" << rezult;
		h.close();

	}else 

		cout << "File is not open\n";
}