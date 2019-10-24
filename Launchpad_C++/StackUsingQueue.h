//Stack using queue

#include<iostream>
#include<queue>
using namespace std;

class stack{
	queue <int> q1;
	queue <int> q2;
	
	public:
		void push( int data){
			
			if (!q1.empty() && q2.empty()){
				q1.push(data);
			}
			
			else if(q1.empty() && !q2.empty()){
				q2.push(data);			
			}
			
			else{
				q1.push(data);
			}
		}
		
		
		void pop(){
			
			if (!q1.empty()){
				while (q1.size()>1){
					q2.push(q1.front());
					q1.pop();
				}
				
				q1.pop();   //But don't push
			}
			
			else{
				while (q2.size()>1){
					q1.push(q2.front());
					q2.pop();
				}
				
				q2.pop();   //But don't push
			}	
		}
		
		int top(){
			
			if (!q1.empty()){
				while (q1.size()>1){
					q2.push(q1.front());
					q1.pop();
				}
				
				int d=q1.front();
				q1.pop();
				q2.push(d);
				return d;
			}
			
			else{
				while (q2.size()>1){
					q1.push(q2.front());
					q2.pop();
				}
				
				int d=q2.front();
				q2.pop();
				q1.push(d);
				return d;
			}	
		}			
		
		bool empty(){
			return (q1.empty() && q2.empty());
		}
				
};
