#include "Stack.h"
#include <string>
#include <iostream>
using namespace std;


	Stack::Stack(){
		
		headPtr = 0;
		
	}


	bool Stack::isEmpty(){

		return headPtr == 0;//headPtr->prevPtr == 0
	}

	void Stack::add( string s){
		Node *nePtr;
		nePtr = new ( Node );
		nePtr->prevPtr = headPtr;
		headPtr = nePtr;
		headPtr->Data = s;
	}

	void Stack::push(){
		Node *tmp;
		tmp = headPtr->prevPtr;
		delete (headPtr);
		headPtr = tmp;
	}

	string Stack::show()const{
		return headPtr->Data;
	}
	
	Stack::~Stack(){
		Node *tmpt, *zPtr;
		tmpt = headPtr;
		while (tmpt != 0 ){
			zPtr = headPtr->prevPtr;
			delete (tmpt);
			headPtr = zPtr;
			tmpt = headPtr;
		}
	}



