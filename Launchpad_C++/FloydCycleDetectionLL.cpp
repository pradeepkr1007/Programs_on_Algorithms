#include<iostream>
#include<list>

using namespace std;

bool isCyclic (node* head){
	node *slow=head;
	node *fast=head;
	
	while (fast!=NULL)    //Maybe cycle doesn't exist
		fast=fast->next->next;
		slow=slow->next;
		if (slow==fast){
			return true;
		}
	}
	return false;
}

node* FindCycle(node *head){
	node *slow=head;
	node *fast=head;
	
	while(fast!=NULL){
		fast=fast->next->next;
		slow=slow->next;
		if (slow==fast){
			slow=head;
			while (slow!=fast){
				slow=slow->next;
				fast=fast->next;
			}
			return fast;
		}
	}
}

void Floyds(node *head)    //Break the cycle
{
	node* slow=head;
	node* fast=head;
	
	while(fast!=NULL){
		fast=fast->next->next;
		slow=slow->next;
		
		if (slow==fast){    //Cycle found
			node* prev=head;
			while (prev->next!=fast){
				prev=prev->next;
			}
			
			slow=head;
			while (slow!=fast){
				prev=fast;
				fast=fast->next;
				slow=slow->next;
			}
			
			prev->next=NULL;   //Breaking the cycle
		}
	}
