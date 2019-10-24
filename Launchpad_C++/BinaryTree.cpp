//Binary Tree

#include<iostream>
#include<queue>
using namespace std;

class node{
	
	public:
		int data;
		node *left;
		node *right;
		
		node(int d): data(d), left(NULL), right(NULL){}
};


///// For FastDiameter function
class Pair{
	public:
		int h;    //Height
		int d;    //Diameter
};

node* createTree(){
	int data;
	cin>>data;
	
	if(data==-1){
		return NULL;
	}
	
	node *n=new node(data);
	n->left=createTree();
	n->right=createTree();
	
	return n;
}

node* BuildLevelWise(){
	int data;
	cout<<"Enter root node:";
	cin>>data;
	if (data==-1){
		return NULL;
	}
	
	node* root=new node(data);
	queue <node*> q;
	
	q.push(root);
	while (!q.empty()){
		node *temp=q.front();
		q.pop();
		int child1, child2;
		cout<<"Enter children of "<<temp->data<<": ";
		cin>>child1>>child2;
		if (child1!=-1){
			temp->left=new node(child1);
			q.push(temp->left);
		}
		if (child2!=-1){
			temp->right=new node(child2);
			q.push(temp->right);
		}
		
	}
	return root;
}


void printPre(node *root){
	
	if (root==NULL)
		return;
		
	cout<<root->data<<" ";
	printPre(root->left);
	printPre(root->right);
	
}

void printIn(node *root){
	
	if (root==NULL)
		return;
		
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);
}

void printPost(node *root){
	
	if (root==NULL)
		return;
		
	printPost(root->left);
	printPost(root->right);
	cout<<root->data<<" ";
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

int count(node *root){
	if (root==NULL){
		return 0;
	}
	return (count(root->left) + count(root->right) +1 );
}


int height(node *root){
	if (root==NULL)
		return 0;
		
	int h1= height(root->left);
	int h2= height(root->right);
	return (1+max(h1,h2));	
}

/*
int height(node *root){
	if (root->left==NULL || root->right==NULL)
		return 1;
		
	node *n=( height(root->left) > height(root->right) ) ? root->left : root->right ;
	return (1+height(n));	
}
*/

///O(n^2)   //Asks height of every node which further calls its child nodes. top to bottom.
int diameter(node *root){
	if (root==NULL){
		return 0;
	}
	
	int op1=height(root->left) + height(root->right);  //Option 1: diameter thru root node
	int op2=diameter(root->left);   //Option 2: diameter thru root->left
	int op3=diameter(root->right);  //Option 3: diameter thru root->right
	return max(op1, max(op2, op3));
}

//O(n) modifying height function
int heightfast(node *root, int &dia){
	if (root==NULL)
		return 0;
		
	int h1= heightfast(root->left, dia);
	int h2= heightfast(root->right, dia);
	dia=max(dia, h1+h2);
	return (1+max(h1,h2));	
}

int diameterfast(node *root){
	
	if (root==NULL)
		return 0;
		
	int dia=0;
	int h=heightfast(root,dia);
	return dia;
	
}

//O(n) using Pair class  //Calculating height from bottom to top
Pair FastDiameter(node* root){
	
	Pair p;
	if (root==NULL){
		p.h=0;
		p.d=0;
		return p;	
	}
	
	Pair left=FastDiameter(root->left);
	Pair right=FastDiameter(root->right);
	
	p.h=1+max(left.h, right.h);
	int op1=left.h+right.h;
	int op2=left.d;
	int op3=right.d;
	p.d=max(op1, max(op2, op3));
	return p;
}

node* Search(node *root, int key){
	if (root==NULL)
		return NULL;

	if (root->data==key)
		return root;
	
	node *n=Search(root->left, key);
	if (n==NULL)
		n=Search(root->right, key);

	return n;
}

void mirror(node *root){
	if (root==NULL){
		return;
	}
	
	mirror(root->left);
	mirror(root->right);
	
	//node *n=root->left;
	//root->left=root->right;
	//root->right=n;
	swap(root->left, root->right);
	
	//delete n;
	
}

/*
node * FormTree(int pre[], int in[], int s, int e){   //Assuming elements are not repeated

	for (int i=0; i<=9; i++){
			if(s>e){
		return NULL;
	}	

	node* root=NULL;
	
		int data=pre[i];
		root=new node(data);
		
		for (int j=s; j<=e; j++){
			if (in[j]==data){
				root->left=FormTree(pre, in, s, j-1);
				root->right=FormTree(pre, in, j+1, e);
			}
		}
	}
	return root;
}*/

int index=0;

node * FormBinaryTree(int pre[], int in[], int s, int e){   //Assuming elements are not repeated
	
	//Base Case
	if(s>e){
		return NULL;
	}
	
	//Create a root node using pre order
	node* root=NULL;
	int data=pre[index];
	root=new node(data);
	index++;
	
	
	//Search for the root in inorder
	int k=-1;
	for (int j=s; j<=e; j++){
		if (in[j]==data){
			k=j;
			break;
		}
	}
	
	//Build left and right subtree
	root->left=FormBinaryTree(pre, in, s, k-1);
	root->right=FormBinaryTree(pre, in, k+1, e);

	return root;
}

int main(){
	/*
	node *root=createTree();
	//node* root=BuildLevelWise();
	
	printPre(root);
	cout<<endl;
	printIn(root);
	cout<<endl;
	printPost(root);
	cout<<endl;
	LevelOrder(root);
	cout<<"Number of nodes= "<<count(root);
	cout<<endl;
	cout<<"Height= "<<height(root);
	cout<<endl;
	cout<<"Diameter using pair class, O(n)= "<<FastDiameter(root).d;
	cout<<endl;
	cout<<"Diameter, O(n^2)= "<<diameter(root);
	cout<<endl;
	cout<<"Diameter modifying height function, O(n)= "<<diameterfast(root);
	cout<<endl;
	cout<<Search(root,13)->data;
	cout<<endl;
	mirror(root);
	LevelOrder(root);*/
	
	int p[]={8,10,1,6,4,7,3,14,13};
	int i[]={1,10,4,6,7,8,3,13,14};
	node* root=FormBinaryTree(p,i,0,8);
	LevelOrder(root);
	//LevelOrder(root);
	return 0;
}
