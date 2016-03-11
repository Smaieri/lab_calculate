#include <iostream>
#include <string>
using namespace std;
#ifndef LIST
#define LIST

class List{

private:
	struct Node{
		string Data;
		Node *next;
		Node *prev;
	};
	Node *start;
	int count;

public:
	List();
	int howMany();
	Node* iterator ( int  );//i<=count
	void remove(int );
	void add( string );
	bool isEmpty();
	void showAll();
	void removeAll();
	string operator[] (int );
	~List();

};
#endif