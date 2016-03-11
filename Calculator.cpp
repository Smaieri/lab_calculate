#include <iostream>
#include "Stack.h"
#include <string>
#include "Reader.h"
#include "Calculator.h"

using namespace std;

	void Calculator::polishNotation (string &s){
	
	string lexem;

	while (s.length () != 0){

		lexem = nextLexem(s);
		
		if ( !isOperator( lexem ) ){
				
			if ( lexem == ")"){
					
					while (! (st.show() == "(") ){
						polN.add ( st.show () );
						
						st.push();
					}

					st.push();

			} else if ( lexem == "(" )

				st.add( lexem );
			else 
				polN.add( lexem );


		}else{

				if ( st.isEmpty() )
					st.add ( lexem );
					else {
						int pr1,
							pr2;
						pr1 = priority ( st.show() );
						pr2 = priority ( lexem );
					
						if ( pr2 > pr1 )
							st.add ( lexem );
						
							else{
								while ( (!st.isEmpty()) && isOperator( st.show() )&& ( priority( st.show() ) >= pr2) )
								{
									polN.add( st.show () );
								
									st.push();

								}
								st.add( lexem );
							}

					}
			}

	}

	while ( !st.isEmpty() ){
		polN.add( st.show() );
		
		st.push();
	}


}

	string Calculator::nextLexem(string &s){
	
		string s1;
		
		if (s[0] == '(') {
			
			for (size_t i = 2; i < s.length() ; i++) 
				s1+=s[i];
			s = s1;
			return "(";	

		}else if(s[0] == ')'){ 

			for (size_t i = 2; i < s.length() ; i++) 
				s1+=s[i];
			s = s1;			
			return ")";
		}else if(s[0] == 't'){

			for (size_t i = 5; i < s.length() ; i++) 
				s1+=s[i];
			s = s1;			
			return "true";
		}else if(s[0] == 'f'){
		
			for (size_t i = 6; i < s.length() ; i++) 
				s1+=s[i];
			s = s1;			
			return "false";
		}else if(s[0] == 'o'){
		
			for (size_t i = 3; i < s.length() ; i++) 
				s1+=s[i];
			s = s1;			
			return "or";
		}else if(s[0] == 'a'){


			for (size_t i = 4; i < s.length() ; i++) 
				s1+=s[i];
			s = s1;			
			return "and";
		}else if(s[0] == 'n'){
	
			for (size_t i = 4; i < s.length() ; i++) 
				s1+=s[i];
			s = s1;			
			return "not";
		}else if(s[0] == 'x'){
		
			if (s[1] == 'o'){
				for (size_t i = 4; i < s.length() ; i++)
					s1+=s[i];
				s = s1;			
				return "xor";
			}else {
				for (size_t i = 2; i < s.length() ; i++)
					s1+=s[i];
				s = s1;			
				return "x";
			}
		}else if(s[0] == 'y'){
		
			for (size_t i = 2; i < s.length() ; i++) 
				s1+=s[i];
			s = s1;			
			return "y";

		}else if(s[0] == 'z'){
		
			for (size_t i = 2; i < s.length() ; i++) 
				s1+=s[i];
			s = s1;			
			return "z";
	}else {
			cout << "smth is wrong. We cannot find lexem.\"Caclulator.cpp\" - NextLexem";
			return "";

		}
			
	}

	int Calculator::priority( string s ){

		if ( s == "or" || s == "xor" ) 
			return 1;
		if (s == "and" )
			return 2;
		if (s == "not" )
			return 3;

		return -1;

	}

	bool Calculator::isOperator(string s){
	
		return s == "or" || s == "and" || s == "xor" || s == "not";

	}

	string Calculator::calculatePolN (string s){
		
		

		if (s == "") 		
			return "There was incorrect data.";
	
		string 
			s1 = s;

		polishNotation (s1);
	

		while (polN.howMany() != 1) {
			
			int i = 1;
			while ( !isOperator ( polN[i] ) && i <= polN.howMany() )
				i++;

			if ( polN[i] == "not" ){

				if ( polN[i-1] == aTrue ){
					polN.iterator(i-1)->Data = aFalse;
					polN.remove(i);
				}else if ( polN[i-1] == aFalse ){
					polN.iterator(i-1)->Data = aTrue;
					polN.remove(i);
				}
			}else if (polN[i] == "and") {
				string 
					st2 = polN[i-1],
					st1 = polN[i-2];

				if ( st1 == aTrue && st2 == aTrue ){
					polN.iterator(i-2)->Data = aTrue;
					polN.remove(i);
					polN.remove(i-1);
				} else {
					polN.iterator(i-2)->Data = aFalse;
					polN.remove(i);
					polN.remove(i-1);
				}

			}else if (polN[i] == "or"){

				string 
					st2 = polN[i-1],
					st1 = polN[i-2];

				if ( st1 == aTrue || st2 == aTrue ){
					polN.iterator(i-2)->Data = aTrue;
					polN.remove(i);
					polN.remove(i-1);
				} else {
					polN.iterator(i-2)->Data = aFalse;
					polN.remove(i);
					polN.remove(i-1);
				}
				
			}else if (polN[i] == "xor"){
				string 
					st2 = polN[i-1],
					st1 = polN[i-2];
				if ( (st1 == aTrue && st2 == aFalse) || ( st2 == aTrue && st1 == aFalse ) ){
					polN.iterator(i-2)->Data = aTrue;
					polN.remove(i);
					polN.remove(i-1);
				}else{
					polN.iterator(i-2)->Data = aFalse;
					polN.remove(i);
					polN.remove(i-1);
				}
		
			}



	}
		string rez = polN[1];
		polN.removeAll();
		return rez;
		
	}
	
	string Calculator::replace (string s, string var1, string var2){ //var1-->var2
		
		string s1 = s;

		while( s1.find(var1) != - 1 ){

			string start = "";

			for (unsigned int i = 0; i < s1.find(var1) ; i++) 
				start += s1[i];

			start += var2;

			for (unsigned int i = s1.find(var1) + var1.length(); i < s1.length(); i++)
				start += s1[i];

			s1 = start;
		}

		return s1;
	
}
	
	bool Calculator::isThereAVar(const string&s, const string &var )  {
	
		if (s.find(var) != - 1 ) 
			return true;
		else
			return false;
}
		
	int Calculator::howManyVars(const string &s){

		return isThereAVar( s, "x ") +  isThereAVar( s, "y ") + isThereAVar( s, "z ");
	}

	bool Calculator:: calculateWithVars ( string s){
	
		if (s == "") {
			cout << "There was incorrect data." <<endl;
		return false;
		}
	
		int vars = howManyVars (s);

	
		switch (vars)
	
		{
	
		case 0:
		
	
			cout << "The rezult is:\n" <<
		
				calculatePolN (s) << endl;
	
			break;

	
		case 1:
	
			{
	
				string c = "";
	
				if ( isThereAVar(s,"x ") ) 
			
					c = "x ";
	
				else if ( isThereAVar(s, "y ") )

					c = "y ";
	
				else if ( isThereAVar(s, "z ") )
	
					c = "z ";
	
				cout << "The rezult is: " << endl;
	
				cout << c << "== 0 : " << calculatePolN (replace(s,c, aFalse + " ")) ;

				cout<< "\n" << c << "== 1 : " << calculatePolN (replace(s,c,aTrue + " "))<<endl;
		
				break;

			}
	
		case 2:{
	
			string 		
				d1,
				d2;


			if ( isThereAVar(s,"x ") && isThereAVar(s, "y ") ) {
		
				d1 = "x ";
				d2 = "y ";
	
			} else if ( isThereAVar(s, "y ") && isThereAVar(s, "z ") ){
				d1 = "y ";
				d2 = "z ";
			}else if ( isThereAVar(s,"x ") &&  isThereAVar(s, "z ") ){
				d1 = "x ";
				d2 = "z ";
			}
	
			cout << "The rezult is: " << endl;
	
			cout << d1 << "== 0," << d2 << "== 0,"<< calculatePolN (replace( replace(s,d1,aFalse + " "), d2, aFalse + " ") ) <<"\n"<<
			 d1 << "== 0," << d2 << "== 1,"<< calculatePolN (replace( replace(s,d1,aFalse + " "), d2, aTrue + " ") ) <<"\n"<<
			 d1 << "== 1," << d2 << "== 0,"<< calculatePolN (replace( replace(s,d1,aTrue + " "), d2, aFalse + " ") ) <<"\n"<<
			 d1 << "== 1," << d2 << "== 1,"<< calculatePolN (replace( replace(s,d1,aTrue + " "), d2, aTrue + " ") ) << endl;

		
			break;
		  
			   }
	
		case 3:
		
			string
				c1 = "x ",
				c2 = "y ",
				c3 = "z ";
		
			cout << c1 << "== 0," << c2 << "== 0,"<< c3 << "== 0,"<< calculatePolN (replace( replace( replace(s,c1,aFalse + " "), c2, aFalse + " ") , c3, aFalse + " " ) )<<"\n"<<
			c1 << "== 0," << c2 << "== 0,"<< c3 << "== 1,"<< calculatePolN (replace( replace( replace(s,c1,aFalse + " "), c2, aFalse + " ") , c3, aTrue + " " ) )<<"\n"<<
			c1 << "== 0," << c2 << "== 1,"<< c3 << "== 0,"<< calculatePolN (replace( replace( replace(s,c1,aFalse + " "), c2, aTrue + " ") , c3, aFalse + " " ) )<<"\n"<<
			c1 << "== 0," << c2 << "== 1,"<< c3 << "== 1,"<< calculatePolN (replace( replace( replace(s,c1,aFalse + " "), c2, aTrue + " ") , c3, aTrue + " " ) )<<"\n"<<
			c1 << "== 1," << c2 << "== 0,"<< c3 << "== 0,"<< calculatePolN (replace( replace( replace(s,c1,aTrue + " "), c2, aFalse + " ") , c3, aFalse + " " ) )<<"\n"<<
			c1 << "== 1," << c2 << "== 0,"<< c3 << "== 1,"<< calculatePolN (replace( replace( replace(s,c1,aTrue + " "), c2, aFalse + " ") , c3, aTrue + " " ) )<<"\n"<<
			c1 << "== 1," << c2 << "== 1,"<< c3 << "== 0,"<< calculatePolN (replace( replace( replace(s,c1,aTrue + " "), c2, aTrue + " ") , c3, aFalse + " " ) )<<"\n"<<
			c1 << "== 1," << c2 << "== 1,"<< c3 << "== 1,"<< calculatePolN (replace( replace( replace(s,c1,aTrue + " "), c2, aTrue + " ") , c3, aTrue + " " ) )<<endl;
		
			break;
	

		}
	
		return true;
	}
	
	string Calculator::calculate (istream&h){
		Reader R;
		string s;
		s = R.read(h);

		if( s == "") 
			return "There was incorrect data.";
		else
		if ( howManyVars(s) == 0 )
			return calculatePolN (s);
		else {
			calculateWithVars(s);
			return "";
		}
	}

	string Calculator::calculate (string s){
		Reader R;
		
		s = R.read(s);
		if( s == "") 
			return "There was incorrect data.";
		else

		if ( howManyVars(s) == 0 )
			return calculatePolN (s);
		else {
			calculateWithVars(s);
			return "";
		}

	}