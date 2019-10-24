//Minheap

#include<iostream>
#include<vector>
using namespace std;

class Minheap{
	public:
	vector <int> v;
	
	void heapify(int index){
		
		int left=2*index;
		int right=left+1;
		int min=index;
		
		if (left<v.size() && v[left]<v[min]){
			min=left;
		}
		
		if (right<v.size() && v[right]<v[min]){
			min=right;
		}
		
		if (min!=index){
			swap(v[index], v[min]);
			heapify(min);
		}

	}
	
	
	public:
		
		Minheap(){
			v.push_back(-1);
		}
		
		void push(int data){
			v.push_back(data);
			int index=v.size()-1;
			int parent=index/2;
			
			while (v[parent]>v[index] && index>1){
				swap(v[parent], v[index]);
				index=parent;
				parent=parent/2;
			}
		}
		
		int top(){   //Minimum element
			return v[1];
		}
		
		bool empty(){
			return v.size()==1;
		}
		
		void pop(){
			swap(v[v.size()-1], v[1]);
			v.pop_back();
			heapify(1);
		}
		
};
