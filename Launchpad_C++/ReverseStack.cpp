//Reverse a stack with the help of recursion

#include<iostream>
#include<stack>
//#include<Stack_vectors.h>

using namespace std;

void pushBottom(stack <int> &s, int topelement){
	
	if(s.empty()){
		s.push(topelement);
		return;
	}
	
	int top=s.top();
	s.pop();
	pushBottom(s,topelement);
	s.push(top);
}

void ReverseStack(stack <int> &s){
	
	//Base Case
	if (s.empty())
		return;
	
	//Pick topmost element
	int topelement=s.top();
	s.pop();
	
	//Recursive Call
	ReverseStack(s);
	
	//Push the topmost element at the bottom
	pushBottom(s, topelement);
	
}

int main(){
	stack <int> s;
	s.push(4);
	s.push(3);
	s.push(2);
	s.push(1);
	
	ReverseStack(s);
	
	while (!s.empty())
	{
	cout<<s.top()<<endl;
	s.pop();
	}	
	
	return 0;
}
