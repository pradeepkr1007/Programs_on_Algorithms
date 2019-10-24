#ifndef HashTable_H
#define HashTable_H

#include<iostream>
#include<cstring>
using namespace std;

template <typename T>
class node{
	
	public:
		
	string key;
	T value;
	node<T> *next;     //eg. Integer Type node
	

	node(string key, T value){       //(string k, T v)
		this->key=key;               //key=k;
		this->value=value;           //value=v;
	}
};

template <typename T>
class hashtable{
	node<T> ** bucket;
	int cs;    //Current Size
	int ts;    //Total size
	
	
	//Hash Function
	int HashFn(string key){
		int ans=0;
		int p=1;
		
		for (int i=0; i<key.length(); i++){
			ans+=key[i]*p;
			p*=37;                //Can also take 37 instead of ts
			
			///////////IMPORTANT
			p%=ts;                //So that p is not very large
			ans%=ts;
		}
		
		return ans;    
	}
	
	
	void rehash(){
		node<T>** OldBucket=bucket;
		int OldTS=ts;
		
		ts=2*ts;
		cs=0;
		bucket=new node<T> *[ts];
		
		for (int i=0; i<ts; i++){
			bucket[i]=NULL;
		}
		
		//Copying old bucket
		for (int i=0; i<OldTS; i++){
			
			//Iterate over every node at every key position and copy
			node<T>* temp=OldBucket[i];
			while (temp!=NULL){
				insert(temp->key, temp->value);
				temp=temp->next;
			}
			
			if (OldBucket[i]!=NULL){
				delete OldBucket[i];    //Delete pointers
			}
			
		}
		
		delete []OldBucket;   //Delete main array of pointers
		
	}
	
	public:
		hashtable(int ms=7){             //Max Size
		cs=0;
		ts=ms;
		bucket=new node<T> *[ts];
		
		for (int i=0; i<ts; i++){
			bucket[i]=NULL;
		}
		
		}
		
		//Insertion
		void insert(string key, T value){
			int i=HashFn(key);
			
			node<T> *n=new node<T>(key, value);
			
			//Insert at front (where bucket[i] is head) so that traversal time is saved
			n->next=bucket[i];     //Can also be n->next=NULL
			bucket[i]=n;
			
			cs++;
			
			//Check if table is 70% full.
			float lf=cs/(ts*1.0);   //Load Factor
			if (lf>0.7){
				rehash();           //Create new table with larger size
			}
			
		}
		
		
		void print(){
			
			for (int i=0; i<ts; i++){
				node<T>*temp=bucket[i];
				cout<<"Bucket "<<i<<"->";
				
				while (temp!=NULL){
					cout<<temp->key<<"->";
					temp=temp->next;
				}
				
				cout<<endl;
			}
		}
	
	
	T* search(string key){      //Can't return NUlll with type T. So data type to be changed to T*
		int i=HashFn(key);
		
		node<T>* temp=bucket[i];
		
		while (temp!=NULL){
			if (temp->key==key){
				return &(temp->value);     //Return type is pointer
			}
			temp=temp->next;
		}
		
		return NULL; 
	}
	
	void erase(string key){
		int i=HashFn(key);
		
		node<T>* temp=bucket[i];
		
		while(temp!=NULL){
			if (temp->key==key){
				bucket[i]=temp->next;
				delete temp;
				break;
			}
			else if (temp->next->key==key){
				node<T>*n=temp->next;
				temp->next=temp->next->next;
				delete n;
				break;
			}
			temp=temp->next;
		}
	}
	
	
	T& operator[](string key){   //We want changes in original bucket
		T* temp=search(key);
		if (temp==NULL){       //If key not found, insert key by returning bucket of value eg. h["Mango"]=100
			T garbage;
			insert(key,garbage);
			temp=search(key);
			return (*temp);
		}
		else
			return (*temp);	//If found, return value. eg. cout<<h["Mango"]
	}
	
	
};


#endif
