//Stack library


#include "node.h"
//#include<iostream>
//using namespace std;
//INCLUDED BY DEFAULT AS THEY ARE IN NODE.H


class Stack{
	
		node* head;
		int count;
		
	public:
		Stack(){
			head=NULL;
			count=0;
		}
		
		
		void Push(int data){          //InsertAtFront
			node *n=new node(data);
			n->next=head;
			head=n;
			count++;
		}
		
		void Pop(){                  //DeleteAtFront
			node *temp=head;
			head=head->next;
			delete temp;
			count--;	
		}
		
		int top(){
			return (head->data);
		}
		
		bool IsEmpty(){
			return (!count);
		}
		
		int size(){
			return count;
		}
};

