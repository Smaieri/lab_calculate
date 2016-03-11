#include "Reader.h"
#include "iostream"
#include "string"
#include "List.h"
using namespace std;


	int Reader::numberLexem(string &s, int start){
		if ( s[start] == '(' )

			return start;

		else if (  s[start] == ')'  )

			return start;

		else if (  s[start] == 'n'  ){

			if ( ((start+2) <=( s.length() - 1 )) && s [start + 1] == 'o' && s [start + 2] == 't' )

				return start + 2;

			else 

				return -1;

		}else if (  s[start] == 'a'  ){

			if ( ((start + 2) <=( s.length() - 1 )) && s [start + 1] == 'n' && s [start + 2] == 'd' )

				return start + 2;

			else
				
				return -1;

		}else if (  s[start] == 'o'  ){

			if ( ((start + 1) <=( s.length() - 1 )) && s [start + 1] == 'r'  )

				return start + 1;

			else 
				
				return -1;
		}else if (  s[start] == 't'  ){
			if ( ( (start + 3) < s.length() ) && s [start + 1] == 'r' && s [start + 2] == 'u'&& s [start + 3] == 'e' )

				return start + 3;

			else 
				
				return -1;
		}else if (  s[start] == 'f'  ){
			if ( ( (start + 4) < s.length() ) && s [start + 1] == 'a' && s [start + 2] == 'l' && s [start + 3] == 's' && s [start + 4] == 'e' )

				return start + 4;

			else 
				
				return -1;
		}else if (  s[start] == 'x'  ){
			
			if ( ((start + 2) <=( s.length() - 1 )) && s [start + 1] == 'o' && s [start + 2] == 'r' )

				return start + 2;

			else 

				return start;						
		}else if (  s[start] == 'y'  ){

			return start;

		}else if (  s[start] == 'z'  ){
			
			return start;

		} else if ( s[start] == ' '||s[start] == '	' ){
			string s1;

			for (int i = 0; i < start; i++ )
				s1 += s[i];
			for (int i = start + 1; i < s.length () ; i++ )
				s1 += s[i];
			s = s1;

			if ( start < s.length () )
				return numberLexem( s, start);
			else 
				return s.length() - 1;
		}
			else return -1;

	}

	bool Reader::makeWithDelim(string &s){
		int i = 0;
		for (int j = 0; j < s.length() - 1; j++)
			if(s[i] == ' ' && s[i+1] == ' ') {
				string h;
				for (int k = 0; k <= j; k++)
					h += s[k];
				
				for (int k = j + 2; k <= s.length() ; k++)
					h += s[k];

				s = h;

			}
		

		while (i < s.length() ){
			i = numberLexem (s, i);
			if (i != -1){
			string s1;
			for (int j = 0; j <= i; j++) 
				s1 += s[j];
			s1 += " ";
			for (int j = i + 1; j < s. length() ; j++ )
				s1 += s[j];
			s = s1;
			i+=2;
			}
			else 
				return false;
		}

		return true;

	}

	string Reader::nextLexem(string &s){
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
			cout << "smth is wrong. We cannot find lexem.\"Reader.cpp\" - NextLexem";
			return "";

		}
			
	}

	bool Reader::isBinaryOperator(string s){
		return s == aOr || s == aXor || s == aAnd;
	}

	bool Reader::isUnaryOperator(string s){
		return s == aNot ;
	}

	bool Reader::isVar(string s){
		return s == "x" || s == "y" || s == "z";
	}

	bool Reader::isValue(string s){
		return s == aTrue || s == aFalse;
	}

	bool Reader::isExpression(string s) {
		
		string s1 = s;

		if (!makeWithDelim(s1))
			return false;

		List pr;

		if (s1.length() == 0)
			return false;

		while (s1.length() != 0)
			pr.add( nextLexem(s1) );
		
		s1 = s;

			if( pr.howMany() == 1) 
				return isVar(pr[1]) || isValue(pr[1]);

			int curI = 1;
			bool f = true;

			while ( f == true ){
				if ( isUnaryOperator( pr[curI] ) ){
					if ( curI +  1<= pr.howMany() &&( isVar( pr[curI + 1] ) || isValue( pr[curI + 1] ) || isUnaryOperator (pr[curI + 1]) ) )
					{
						if ( curI - 1 > 0 && ( isBinaryOperator (pr[curI - 1])|| isValue (pr[curI - 1] ) ) )
						
							curI += 2;
					
						else if ( curI - 1 > 0 && !( isBinaryOperator (pr[curI - 1])|| isValue (pr[curI - 1] ) ) )
							
							return false;
						
						else if (curI - 1  == 0 )
							
							curI += 2;

					}else if (  curI +  1<= pr.howMany() && pr[curI + 1 ] == "(" ){
						
						if ( curI - 1 > 0)
							if( !( isBinaryOperator (pr[curI - 1])|| isValue (pr[curI - 1] ) ||isUnaryOperator (pr[curI - 1])) )
							return false;

						int count = 1,
							j = curI + 2;

						//шукаємо закриваючу дужку
						while ( count != 0 && j <= pr.howMany() ){
							if ( pr[j] == "(" ) 
								count++; 
							else if ( pr[j] == ")" )
								count--;
							j++;
						}
						if (count != 0) 
							return false;
						j--; //')'
						
						string str;

						for (int k = curI + 2; k < j; k++ )
							str += pr[k];

						if ( isExpression (str) )
							curI = j + 1;
						else
							return false;
						
					} else 

						return false;			
					
				} else if ( isBinaryOperator( pr[curI] ) ){
						
					if ( curI + 1 <= pr.howMany() && (isVar( pr[curI + 1] ) || isValue( pr[curI + 1] ) || isUnaryOperator (pr[curI +1]) ) ){
						if (curI - 1 > 0 && (isVar( pr[curI - 1] ) || isValue( pr[curI - 1] )|| pr[curI - 1] == ")" ) )
						curI += 2;
						else if (curI - 1 > 0 )
							return false;
						else if (curI - 1 == 0 )
							return false;
					}
					else if (curI + 1 <= pr.howMany() && pr[curI + 1 ] == "(" ){
						
						if (curI - 1 > 0)
							if( !(isVar( pr[curI - 1] ) || isValue( pr[curI - 1] ) ) )
								return false;

						int count = 1,
							j = curI + 2;
						
						while (count != 0 && j <= pr.howMany()){
							if ( pr[j] == "(" ) 
								count++; 
							else if ( pr[j] == ")" )
								count--;
							j++;
						}
						if(count !=0 )
							return false;
						j--;  
						
						string str;
						for (int k = curI + 2; k < j; k++ )
							str += pr[k];
						if ( isExpression (str) )
							curI = j + 1;
						else return false;

					}
					else 
						return false;

				}else if ( isVar( pr[curI] ) || isValue ( pr[curI] ) ) {

					if ((curI + 1 <= pr.howMany() ) && ( isBinaryOperator( pr[curI + 1] ) || isUnaryOperator ( pr[curI + 1 ]) ) ){
						if (curI - 1 > 0 && ( isBinaryOperator( pr[curI - 1] ) || isUnaryOperator ( pr[curI - 1 ]) ))
							curI += 2;
						else if ( curI - 1 > 0 )
							return false;
						else if( curI - 1 == 0 )
							curI += 2;
					}
					else 
						return false;
					
				}else if(pr[curI] == "(" ){
					if ((curI - 1 > 0 &&( isBinaryOperator (pr[curI - 1])  || isUnaryOperator( pr[curI - 1] ) ) ) || (curI - 1 == 0 )){
						
						int count = 1,
							j = curI + 1;
						
						while (count != 0 && j <= pr.howMany() ){
							if ( pr[j] == "(" ) 
								count++; 
							else if ( pr[j] == ")" )
								count--;
							j++;
						}
						if (count!= 0) 
							return false;
						j--; //')' = pr[j]
						
						string str;

						for (int k = curI + 1; k < j; k++ )
							str += pr[k];
					
						if ( isExpression (str) )
							curI = j + 1;
						else 
							return false;
					
					}else 
						return false;

				}
				else
					return false;
			
				if (curI >= pr.howMany()) 
					f = false;
			}
			int howM = pr.howMany ();
			if ( curI > howM && !(isBinaryOperator( pr [ howM ] ) || isUnaryOperator( pr[howM] ) ) )
				return true;
			else{
				if (  isVar (pr[howM]) || isValue (pr[howM]) || pr[howM] == ")")
					return true;
				else if(isBinaryOperator( pr [ howM ]) || isUnaryOperator( pr[howM] )){
					return false;
				}
				else 
					return false;
			}	

	}

	string Reader::read(istream& h){
		
		
		while ( ! h.eof() ){

			string s1;
			getline(h,s1);
			s += " " + s1;

		}
	
		
		return correct(s);

	}

	string Reader::read(string &s1 ){
		
		s = s1;
		getline(cin,s);
		return correct(s);

	}

	string Reader::correct(string &s){

	if (s.length () == 0)

		return "";

	if ( isExpression ( s ) ){

		makeWithDelim(s);

		return s;

	} else 

		return "";
	


	}

	Reader::~Reader(){
		s = "";
	}