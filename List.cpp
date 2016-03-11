#include <iostream>
#include <string>
#include "List.h"
using namespace std;


	List::List(){
	
		count = 0;
		start = 0;

	}

	int List::howMany() {
	
		return count;
	
	}
	
	List::Node* List::iterator ( int i ){//i<=count
	
		Node *tmtPtr = start;

		for (int j = 2; j <= i ; j++)
			tmtPtr = tmtPtr->next;

		return tmtPtr;

	}
	
	void List::remove(int i){
		
		if (i == 1){
		
			Node *tmtPtr = start->next;
			delete (start);
			start = tmtPtr;
			count--;
		
		} else if( i == count){
		
			Node *tmtPtr = iterator(count - 1);
			delete ( tmtPtr->next );
			tmtPtr->next = 0;
			count--;
		
		} else{
			Node 
				*tmtPtr1 = iterator (i-1),
				*tmtPtr2 = iterator (i+1);

			delete( tmtPtr1->next);
			tmtPtr1->next = tmtPtr2;
			tmtPtr2->prev = tmtPtr1;
			count--;
		
		}
	
	}
	
	void List::add( string s){
		
		if (count != 0){
		
			Node 
			*tmtPtr1 = iterator (count),
			*tmtPtr2;
		
			tmtPtr2 = new (Node);
			tmtPtr2->Data = s;
			tmtPtr2->next = 0;
			tmtPtr2->prev = tmtPtr1;
			tmtPtr1->next= tmtPtr2;
		
			count++;
		
		}else{
			
			start = new (Node);
			start->Data = s;
			start->next = 0;
			start->prev = 0;
		
			count++;

		}
	
	}
	
	bool List::isEmpty(){
		
		return count == 0; 
	
	}
	
	void List::showAll(){
	
		for (int i = 1; i<= count; i++ )
		
			cout << (*this)[i] << endl;
		
	}
	
	void List::removeAll(){
	
		while ( count != 0 )
		 
			remove ( count );
	
	}
	
	List::~List(){
		
		if (count != 0){
			Node 
			*tmtPtr1 = start,
			*tmtPtr2;
		
			while(count > 0){
				
				tmtPtr2 = tmtPtr1->next;
				delete (tmtPtr1);
				
				count--;
				
				if (count > 0)
					tmtPtr1 = tmtPtr2;
			
			}

		}
	}

	string List::operator[] (int i){
		
		if (i <= count && i >= 1) 
		 
			return iterator(i)->Data;
		else {
			
			cerr << "Smth is wrong. List.cpp operator[]";
			
			return "";
		}

	}