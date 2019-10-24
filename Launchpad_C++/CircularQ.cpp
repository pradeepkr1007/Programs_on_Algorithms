#include<iostream>
#include "QueueLinkedList.h"
using namespace std;

int main(){
	
	queue q;
	
	for (int i=0; i<4; i++){
		q.enqueue(i);
	}
	
	
	while (!q.empty()){
		cout<<q.front()<<endl;
		q.dequeue();
	}
	return 0;
}
