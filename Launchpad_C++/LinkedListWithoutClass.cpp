//Linked List without class

#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		
	node(int d): data(d), next(NULL){
	}
};

//INSERT AT FRONT
node* takeinput(){               //To return head of linkedlist
	node* head=NULL;
	int data;
	cin>>data;
	
	while (data!=-1){
		node* n=new node(data);   //Dynamic because we don't want local static variable to be destroyed with the function
		n->next=head;             //If head=NULL, n will be the first element in list automatically
		head=n;
		cin>>data;
	}
	
	return head;
}

//INSERT AT END


//INSERT AT MID


//MERGE 2 SORTED LINKED LISTS
node* merge(node* a, node* b){
	
	if (a==NULL){
		return b;
	}
	
	if (b==NULL){
		return a;
	}
	
	node* c;
	
	if(a->data<b->data){
		c=a;
		c->next=merge(a->next,b);
	}
	else{
		c=b;
		c->next=merge(a, b->next);
	}
	
	return c;
}

//FIND MID
node* FindMid(node *head){                //Find middle element of linked list without using length
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

//MERGE SORT
node* MergeSort(node *head){
	
	//Base Case
	if (head==NULL || head->next==NULL)  //No elements or 1 element
		return head;
	
	//Divide
	node *mid=FindMid(head);
	node *a=head;
	node *b=mid->next;
	mid->next=NULL;
	
	//Sort
	a=MergeSort(a);
	b=MergeSort(b);
	
	//Merge
	return merge(a,b);
	
}


void print (node *head){
	while (head!=NULL){
		cout<<head->data<<"->";    //Head is not lost here as we will pass head by value, not by reference (void print(node* &head))
		head=head->next;
	}
	cout<<"NULL"<<endl;
}

/*
node *BubbleSortRec(node *head, int n){
	
	//BASE CASE
	if (n==0 or n==1)
		return head;
		
	while (head->next->next!=NULL){
		if (head->data>head->next->data){
			/////SWAP	
				
			//while (current!=NULL && current->next!=NULL){    //Refer to notes in register on swapping
			//if (current->data>current->next->data){
				//SWAP
				if (prev==NULL){         //Swapping first two elements in list
					node *n=current->next;
					current->next=n->next;
					n->next=current;
					head=prev=n;
				}
				
				else{                  //Swapping middle 2 elements in list
					node* n=current->next;
					current->next=n->next;
					prev->next=n;
					n->next=current;
					prev=n;		
					}
			}
			else{                     //Not Swapping
				//DON'T SWAP
				prev=current;
				current=current->next;
			}
		//}
		
		
		head=head->next;
		}
	return BubbleSortRec(head, n-1);	
}
*/

int Length(node *head){
	node *temp=head;
	int count=0;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	
	return count;
}

void BubbleSort(node* &head){   //Passed by reference so that head can be updated
	int n=Length(head);
	
	for (int i=0; i<n; i++){  //Traversing linked list n times
		node* current=head;
		node* prev=NULL;
		
		while (current!=NULL && current->next!=NULL){    //Refer to notes in register on swapping
			if (current->data>current->next->data){
				//SWAP
				if (prev==NULL){         //Swapping first two elements in list
					node *n=current->next;
					current->next=n->next;
					n->next=current;
					head=prev=n;
				}
				
				else{                  //Swapping middle 2 elements in list
					node* n=current->next;
					current->next=n->next;
					prev->next=n;
					n->next=current;
					prev=n;		
					}
			}
			else{                     //Not Swapping
				//DON'T SWAP
				prev=current;
				current=current->next;
			}
		}
		
	
	}
}

//NOT WORKING
void reverse(node * &head){
	node *c=head;
	node *n;///
	node *prev=NULL;
	while (c!=NULL){
		n=c->next;
		c->next=prev;
		prev=c;
		c=n;
	}
	
}


int main(){
	
	node *head=takeinput();
	print(head);
	
	BubbleSort(head);
	print(head);
		
	reverse(head);
	print(head);
	return 0;
}
