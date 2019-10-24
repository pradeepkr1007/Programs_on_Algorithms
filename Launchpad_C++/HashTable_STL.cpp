#include<iostream>
#include<unordered_map>    //if map instead of unordered_map, sorted output is obtained as BST is used
using namespace std;

int main(){
	unordered_map <string, int> h;
	
	//Method 1
	h.insert(make_pair("Apple",120));
	h.insert(make_pair("Mango",100));
	h.insert(make_pair("Chiku",130));
	h.insert(make_pair("Guava",10));
		
	//Method 2
	pair <string, int> p("Banana",20);
	h.insert(p);
	
	
	//No in-built print function
	
	//NOT WORKING
	auto i=1;
	cout<<i<<endl;
	for (auto node:h)   //Node=variable iterating over hash table  //auto=pair<string,int>
	{
		cout<<node.first<<" "<<node.second<<endl;
	}
	
	for (int i=0; i<h.bucket_count();i++){
		cout<<"Bucket "<<i<<"->";
		for (auto it=h.begin(i); it!=h.end(i); it++){    //it is a pointer
			cout<<it->first<<" "<<it->second<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
