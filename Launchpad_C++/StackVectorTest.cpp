//Stack test

#include<iostream>
#include<cstring>
#include "Stack_vectors.h"

using namespace std;

class book{
	public:
		int price;
		char name[100];
		
		book(int p, char*n){
			price=p;
			strcpy(name,n);
		}
		
		void print(){
			cout<<"Name= "<<name<<endl;
			cout<<"Price= "<<price<<endl;
		}
};


void print (Stack <int> s){
	while (!s.IsEmpty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}

int main()
{
	/*
	Stack <int>s;
	
	for (int i=0; i<10; i++){
		s.push(i);
	}
	
	print(s);
	
	Stack <char> s1;
	s1.push('a');
	s1.push('b');
	
	while(!s1.IsEmpty()){
		cout<<s1.top()<<endl;
		s1.pop();
	}	*/
	
	Stack <book> s;
	
	book b1(150, "Java");
	book b2(200, "C++");
	
	s.push(b1);
	s.push(b2);
	
	while(!s.IsEmpty()){
		s.top().print();
		s.pop();
	}
	
	return 0;
}
