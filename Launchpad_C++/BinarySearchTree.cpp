//BST: Binary Search Tree

#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class node{
	public:
		int data;
		node* left;
		node* right;
		
		node(int d): data(d), left(NULL), right(NULL){}
		
};

class Pair{           //TO CHECK IF BST IS BALANCED
	public:
	bool bal;  //Balanced or not
	int h;     //Height
};

class LinkedList{    //TO CONVERT BST TO LL
	public:
		node* head;
		node* tail;
};



node* InsertInBST(node *root, int data){
	if (root==NULL){
		root=new node(data);
		return root;
	}
	
	if (data>(root->data)){
		root->right=InsertInBST(root->right, data);
	}

	else{
		root->left=InsertInBST(root->left, data);
	}
	
	return root;
}

node *TakeInput(){	
	int data;
	cin>>data;
	node* root=NULL;
	while(data!=-1){
		root=InsertInBST(root,data);
		cin>>data;
	}
	
	return root;
}

bool isBST(node *root, int min=INT_MIN, int max=INT_MAX){
	if (root==NULL){
		return true;
	}
	
	if (root->data>=min && root->data<=max && isBST(root->left, min, root->data) && isBST(root->right, root->data, max)){
		return true;
	}
	
	else{
		return false;
	}
}

void LevelOrder(node *root){
	queue <node *> q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()){
		node* temp=q.front();
		q.pop();
		if (temp==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			
			cout<<temp->data<<" ";
			
			if (temp->left){
				q.push(temp->left);
			}
			if (temp->right){
				q.push(temp->right);
			}
		}
	}
}

Pair Balanced(node *root){
	Pair p;
	
	if (root==NULL){
		p.bal=true;
		p.h=0;
		return p;
	}
	
	Pair left=Balanced(root->left);
	Pair right=Balanced(root->right);
	
	p.h=1+max(left.h, right.h);
	if (left.bal && right.bal && (abs(left.h-right.h)<=1)){
		p.bal=true;
	}
	
	else{
		p.bal=false;
	}
	
	return p;
}

node *SortedArraytoBST(int a[], int s, int e){
	if (s>e){
		return NULL;
	}
	
	int mid=(s+e)/2;
	node *n=new node(a[mid]);
	n->left=SortedArraytoBST(a, s, mid-1);
	n->right=SortedArraytoBST(a, mid+1, e);
	return n;
	
}

void PrintinRange(node *root, int k1, int k2){
	if (root==NULL){
		return;
	}
	
	if (root->data >= k1 && root->data <= k2){
		cout<<root->data<<" ";
	}
	
	if (root->data >= k1){
		PrintinRange(root->left, k1, k2);
	}
	
	if (root->data <= k2){
		PrintinRange(root -> right, k1, k2);
	}
}

LinkedList BSTtoLL(node* root){
	LinkedList l;
	
	//Base Case
	if (root==NULL){
		l.head=l.tail=NULL;
		return l;
	}
	
	//Case 1: Left child non-null, right child null
	if (root->left!=NULL && root->right==NULL){
		LinkedList left=BSTtoLL(root->left);
		left.tail->right=root;
		l.head=left.head;
		l.tail=root;
		return l;
	}
	
	//Case 2: Left child null, right child non-null
	else if (root->right!=NULL && root->left==NULL){
		LinkedList right=BSTtoLL(root->right);
		root->right=right.head;
		l.head=root;
		l.tail=right.tail;
		return l;
	}
	
	//Case 3: Both children are null
	else if(root->left==NULL && root->right==NULL){
		l.head=l.tail=root;
		return l;
	}

	//Case 4: Both children are non-null
	else{
		LinkedList left=BSTtoLL(root->left);
		LinkedList right=BSTtoLL(root->right);
		left.tail->right=root;
		root->right=right.head;
		l.head=left.head;
		l.tail=right.head;
		return l;
	}
	
}

void print(LinkedList l){
	node *temp=l.head;
	while (temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->right;
	}
}

int main(){
	/*
	node* root=TakeInput();
	LevelOrder(root);
	if(isBST(root)){
		cout<<"BST"<<endl;
	}
	else{
		cout<<"Not BST"<<endl;
	}
	
	if(Balanced(root).bal){
		cout<<"Balanced"<<endl;
	}
	else{
		cout<<"Not Balanced"<<endl;
	}
	*/
	
	int a[]={1,2,3,4,8,9,10,11};
	node *b=SortedArraytoBST(a,0,7);
	LevelOrder(b);
	cout<<endl;
	//PrintinRange(b,3,10);
	LinkedList l=BSTtoLL(b);
	print(l);
	return 0;
}
