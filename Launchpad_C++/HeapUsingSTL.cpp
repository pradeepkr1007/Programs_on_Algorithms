//Heap_STL

#include<iostream>
#include<queue>
#include<functional>
using namespace std;

class Person{
		string name;
		int money;    //Criteria for sorting
		
	public:
		
		Person(string name, int money){
			this->name=name;    //This Pointer
			this->money=money;   
		}
		
		int getmoney(){
			return money;
		}
		
		friend ostream & operator<<(ostream &os, Person P); //Friend function
};

ostream & operator<<(ostream &os, Person P){
	os<<P.name<<endl;
	os<<P.money<<endl;
	
	return os;
}

/*
class mycompare{
	public:
		bool operator() (int a, int b){
			return a>b;
		}
};
*/

class mycompare{
	public:
		bool operator() (Person a, Person b){
			return a.getmoney()>b.getmoney();
		}
};




int main(){
	
	/*
	priority_queue <int> q; //Maxheap
	
	int a[]={8,9,5,6,7,4,3,0,1,2};
	int n=sizeof(a)/sizeof(int);
	
	for (int i=0; i<n; i++){
		q.push(a[i]);
	}
	
	while(!q.empty()){
		cout<<q.top()<<" ";
		q.pop();
	}
	
	cout<<endl;
	
	//priority_queue <int,vector <int>,mycompare> q2; //IMPORTANT! (Using user-defined function)
	priority_queue <int,vector <int>,greater<int> > q2;   //Using in-built function (Space between > and > after int are important)
	
	int a2[]={8,9,5,6,7,4,3,0,1,2};
	int n2=sizeof(a2)/sizeof(int);
	
	for (int i=0; i<n2; i++){
		q2.push(a2[i]);
	}
	
	while(!q2.empty()){
		cout<<q2.top()<<" ";
		q2.pop();
	}
	*/
	
	priority_queue <Person,vector <Person>,mycompare> q;
	
	/*
	Person P1("Kartik", 100);
	Person P2("Sanjeev", 150);
	Person P3("Shubham", 50);
	Person P4("Ankita", 200);
	
	q.push(P1);
	q.push(P2);
	q.push(P3);
	q.push(P4);
	
	while (!q.empty()){
		cout<<q.top()<<endl;
		q.pop();
	}
	
*/

 
	return 0;
}
