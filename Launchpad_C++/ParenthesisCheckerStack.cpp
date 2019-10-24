//Given an expression, check if the brackets are balanced using stacks

#include<iostream>
#include "Stack_vectors.h"   //#include<stack> (in-built stack library)
using namespace std;


/*
#include<stack>

stack <char> s;
stack.push()
stack.pop()
stack.size()
stack.top()
stack.empty()

*/


bool ParenthesisChecker(string a){
	Stack <char> s;
	for (int i=0; i<a.length(); i++){
		if (a[i]=='(' || a[i]=='[' || a[i]=='{'){
			s.push(a[i]);
		}
		
		else if (a[i]==')'){
			if (!s.IsEmpty() && s.top()=='(')
				s.pop();

			else
				return false;
		}
		
		else if (a[i]==']'){
			if (!s.IsEmpty() && s.top()=='[')
				s.pop();
			
			else
				return false;
		}
				
		else if (a[i]=='}'){
			if (!s.IsEmpty() && s.top()=='{')
				s.pop();
				
			else
				return false;
		}

		}
		
	if (s.size()==0){
		return true;
	}	
	else
		return false;
	}
	
	
int main()
{
	string a;
	cin>>a;
	cout<<ParenthesisChecker(a);
	return 0;
}

/*

bool isBalanced( char *a ){
	stack <char> s;
	for (int i=0; a[i]!='\0'; i++){
		char ch=a[i];
		switch(ch){
			case '{':
			case '[':
			case '(':
				s.push(ch);
				break;
			case '}':
				if (!isempty() && s.top()=='{'
					s.pop();
					break;
				else
					return false;
			case ')':
				if (!isempty() && s.top()=='('
					s.pop();
					break;
				else
					return false;
			case ']':
				if (!isempty() && s.top()=='['
					s.pop();
					break;
				else
					return false;
			
	if (!s.empty())
		return false;
	else
		return true;
		
}
	
	
	
*/
