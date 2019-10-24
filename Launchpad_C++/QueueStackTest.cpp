#include<iostream>
#include "StackUsingQueue.h"
using namespace std;

int main(){
	stack s;
	for (int i=0; i<10; i++){
		s.push(i);
	}
	
	while (!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
	
	return 0;
}
