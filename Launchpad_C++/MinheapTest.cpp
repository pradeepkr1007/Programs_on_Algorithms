#include<iostream>
#include "Minheap.h"
using namespace std;

void PrintTopK(int k){
	Minheap h;
	for (int i=0; i<k; i++){
		int data;
		cin>>data;
		h.push(data);
	}
	
	while (true){
		int data;
		cin>>data;
		if (data==-1){
			for (int i=1; i<=k; i++){
				cout<<h.v[i]<<" ";
			}
		}
		
		else if (data==0){
			break;
		}
		
		else if (data>h.top()){
			h.pop();
			h.push(data);
		}	
	}
	
}


int main(){
	
	/*
	Minheap h;
	h.push(5);
	h.push(1);
	h.push(6);=
	h.push(9);
	h.push(0);
	h.push(8);
	
	//Implementation of heap sort
	while (!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}
	
*/

	PrintTopK(3);
	return 0;
}
