//Hash Table

#include<iostream>
#include "HashTable.h"
using namespace std;

int main(){
	
	hashtable <int>h;
	h.insert("Mango",100);
	h.insert("Apple",120);
	h.insert("Banana",20);
	h.insert("Chiku",10);
	
	h.print();
	
	cout<<endl;
	
	h.insert("Pineapple", 700);
	
	h.print();
	
	cout<<endl;
	
	int *val=h.search("Mango");
	cout<<*val;
	cout<<endl;
	
	//h.print();
		
	h.erase("Banana");
	h.print();
	
	cout<<endl;
	
	h.erase("Mango");
	h.print();
	
	cout<<endl;
	
	h["Cherry"]=20;  //Insertion
	h["Cherry"]=200;   //Updation
	
	h.print();
	
	cout<<h["Cherry"]<<endl;
	
	
	return 0;
}
