//Stack test

#include<iostream>
#include "Stack.h"

using namespace std;


void print (Stack s){
	while (!s.IsEmpty()){
		cout<<s.top()<<endl;
		s.Pop();
	}
}

int main()
{
	Stack s;
	
	for (int i=0; i<10; i++){
		s.Push(i);
	}
	
	print(s);
	
	return 0;
}
