//Linked List

#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
		
		node(int d): data(d), next(NULL){ 
		}
		
		~node(){                                         //NODE CONSTRUCTOR
			if (next!=NULL){  //Will delete nodes from end to start
				delete next; //Recursive call to itself
				next=NULL;
			}
			cout<<"Deleting node: "<<data<<endl;
		}
};

class LinkedList{
	public:
		node* head;
		node* tail;
		
		LinkedList(){                         //LINKED LIST CONSTRUCTOR
			head=tail=NULL;
		}
		  
		void InsertAtFront(int data){
			if (head==NULL){ 
				head=tail=new node(data);
			}
			
			else{
				node* n=new node(data);
				n->next=head;
				head=n;
			}
		}
		
		void InsertAtEnd(int data){
			if(head==NULL)
				head=tail=new node(data);
			else{
				node* n=new node(data);
				tail->next=n;
				tail=n;
			}
		}
		
		void InsertAtMid(int data, int pos){ //Position is place in list, not index in array
			if (pos==0){
				InsertAtFront(data);
			}
			
			else if (pos>=length()){
				InsertAtEnd(data);
			}
			
			else{
				node* temp=head;
				int jump=1;                   //To count the position
				while (jump<=pos-2){          //To reach pos-1 position (one position left to new node position)
					temp=temp->next;
					jump++;
				}
				
				node *n= new node(data);
				n->next=temp->next;
				temp->next=n;
			}
		}
		
		void DeleteAtFront(){
			if (head==NULL){  //Empty list
				return;
			}
			
			else if (head->next==NULL){ //One element only
				delete head;
				head=tail=NULL;
			}
			
			else{
				node *temp=head;
				head=head->next;
				temp->next=NULL;  	
	                                    //IF NOT COMMENTED, EVERY TIME DELETE FUNCTION IS CALLED, 
	                                    //OUR USER DEFINED DESTRUCTOR WILL BE CALLED AND WILL DELETE THE ENTIRE LINKED LIST INSTEAD OF ONE ELEMENT
				delete temp;
			}
		}
		
		void DeleteAtEnd(){
			if (head==NULL){  //Empty list
				return;
			}
			
			else if (head->next==NULL){ //One element only
				delete head;
				head=tail=NULL;
			}
			
			else{
				node *temp=head;
				
				while ((temp->next)!=tail) //OR temp->next->next!=NULL
				{
					temp=temp->next;
				}
				
				temp->next=NULL;	
	                                    //IF NOT COMMENTED, EVERY TIME DELETE FUNCTION IS CALLED, 
	                                    //OUR USER DEFINED DESTRUCTOR WILL BE CALLED AND WILL DELETE THE ENTIRE LINKED LIST INSTEAD OF ONE ELEMENT
				delete (temp->next);
				temp->next=NULL;   //////
				tail=temp;
			}
		}
		
		void DeleteFromMidKey(int key){
			if (head==NULL){  //Empty list
				return;
			}

			/*else if (head->next==NULL){ //One element only
				delete head;
				head=tail=NULL;
			}*/
			
			else{
				node *temp=head;
				
				while ((temp->next->data)!=key) //OR temp->next->next!=NULL
				{
					temp=temp->next;
				}
				
				node *n=temp->next;
				temp->next=n->next;
				n->next=NULL;
				delete (n);          //Now when deleted, destructor will not delete the array following this node.
			}
		}
		
		void DeleteFromMidPos(int pos){
			if (head==NULL){  //Empty list
				return;
			}
			
			else if (head->next==NULL){ //One element only
				delete head;
				head=tail=NULL;
			}
			
			else if (pos>=length()){
				DeleteAtEnd();
			}
			else{
				node *temp=head;
				int jump=1;
				while (jump<=pos-2){
					temp=temp->next;
					jump++;
				}
				
				node *n=temp->next;
				temp->next=n->next;
				n->next=NULL;                  //Now when deleted, destructor will not delete the array following this node.
				delete (n);
			}
		}
		
		void print(){
			node* temp=head;
			
			while (temp!=NULL){ 
				cout<<temp->data<<"-->";
				temp=temp->next;
			}
			
			cout<<"NULL"<<endl;
		}
		
		node* Search(int key){
			node *temp=head;
			
			while(temp!=NULL){
				if (temp->data==key){
					return temp;
				}
				temp=temp->next;
			}
			
			return NULL; //Not found. So that garbage is not returned.
		}
		
		node* SearchRecHelper(node *start, int key){
			if (start==NULL){                       //NOT FOUND
				return NULL;
			}
			if (start->data==key){
				return start;
			}
			return SearchRecHelper(start->next, key);
		}
		
		node *SearchRec(int key){           //If we donot want l.head input from user
			return SearchRecHelper(head, key);
		}
		
		int length(){
			int cnt=0;
			
			node *temp=head;
			
			while(temp!=NULL)
			{
				cnt++;
				temp=temp->next;
			}
			
			return cnt;
		}
		
		node* FindMid(){                //Find middle element of linked list without using length
			node *slow=head;
			node *fast=head->next;
			
			while (fast!=NULL){
				fast=fast->next;       //Slow moves forward only when fast takes 2 steps, not 1.
				if (fast!=NULL){
					slow=slow->next;
					fast=fast->next;
				}
			}
			
			return slow;
		}
				
		~LinkedList(){                        //LINKED LIST DESTRUCTOR
			if (head){ //if (head!=NULL)
				delete head;  //Calls destructor of node
				head=tail=NULL;
			}
		}
};


node *merge(node *a, node *b){
	if (a==NULL){    //a is over
		return b;
	}
	
	if (b==NULL){    //b is over
		return a;
	}
	
	node *c;
	if(a->data<b->data){
		c=a;
		c->next=merge(a->next,b);
	}
	
	else{
		c=b;
		c->next=merge(a,b->next);
	}
	
	return c;
	
}

int main()
{
	LinkedList l1;
	l1.InsertAtEnd(2);
	l1.InsertAtEnd(4);
	l1.InsertAtEnd(6);
	l1.print();
	
	LinkedList l2;
	l2.InsertAtEnd(1);
	l2.InsertAtEnd(3);
	l2.InsertAtEnd(5);
	l2.print();
	
	LinkedList l;
	l.head=merge(l1.head, l2.head);
	l.print();	
	
		
	/*LinkedList l;
	
	for (int i=0; i<5; i++){
		l.InsertAtFront(i);
	}	
	l.print();
	
	for (int i=10; i<15; i++){
		l.InsertAtEnd(i);
	}
	l.print();
	
	l.InsertAtMid(20,3);
	l.print();

	cout<<l.Search(20)->data<<endl;
	//node *s=l.Search(20);
	//cout<<s->data<<endl;
	cout<<l.SearchRecHelper(l.head, 20)->data<<endl;
	cout<<l.SearchRec(20)->data<<endl; //if l.head is private
	
	cout<<l.FindMid()->data<<endl;
	
	l.DeleteAtFront();
	l.print();
	
	l.DeleteAtEnd();
	l.print();
	
	l.DeleteFromMidKey(10);
	l.print();
	
	l.DeleteFromMidPos(3);
	l.print();
	
	cout<<l.length()<<endl;*/
	return 0;
}
