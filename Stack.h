#include <string>
using namespace std;
#ifndef STACK
#define STACK
class Stack{
private:
	struct Node{
		string Data;
		Node *prevPtr;
	};
	Node *headPtr;
	

public:
	Stack();
	bool isEmpty();
	void add( string );
	void push();
	string show()const;
	~Stack();
	
};
#endif