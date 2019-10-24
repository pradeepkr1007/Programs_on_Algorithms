#include<iostream>
#include<queue>
#include<functional>
using namespace std;


void Print(priority_queue <int,vector <int>,greater<int> > h, int k){
	for (int i=1; i<=k; i++){
		cout<<h.top()<<" ";
		h.pop();
	}
}
void PrintTopK(int k){
	
	priority_queue <int,vector <int>,greater<int> > h;  //Minheap to find k maximum elements
	
	for (int i=0; i<k; i++){
		int data;
		cin>>data;
		h.push(data);
	}
	
	while (true){
		int data;
		cin>>data;
		if (data==-1){
			Print(h,k);  //Passing by value so that original heap is not changed
		}
		
		else if (data==0){  //Exit condition
			break;
		}
		
		else if (data>h.top()){
			h.pop();
			h.push(data);
		}	
	}
	
}


int main(){


	PrintTopK(3);
	return 0;
}
