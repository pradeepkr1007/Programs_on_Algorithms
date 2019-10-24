//QUEUE using arrays

#include<iostream>
using namespace std;

class queue{

		int *arr;
		int cs;  //Current Size
		int ts;  //Total Size
		int f;   //Front
		int r;   //Rear
		
	public:		
		queue(int ms=4){
			cs=0;
			ts=ms;
			f=0;
			r=ts-1;
			arr=new int[ms];
		}
		
		void enqueue(int data){   //void push(int data)
			if (!full()){
				r=(r+1)%ts;
				arr[r]=data;
				cs++;
			}
			else
				cout<<"Queue Overflow!";
		}
				
		void dequeue(){          //void pop()
			if (!empty()){
				f=(f+1)%ts;
				cs--;
			}
			else
				cout<<"Queue Underflow!";
		}
		
		bool empty(){
			return cs==0;
		}
		
		bool full(){
			return cs==ts;
		}
		
		int size(){
			return cs;
		}
		
		int front(){
			return arr[f];
		}
		
		int max_size(){
			return ts;
		}
		
};
