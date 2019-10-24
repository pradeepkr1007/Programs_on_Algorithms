#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>

using namespace std;


template <typename T>
class Graph{
	map<T,list<T>> m;
	
	public:
		
		void addEdge(T u, T v, bool bidir=false){
			m[u].push_back(v);
			if (bidir){
				m[v].push_back(u);
			}
		}
		
		void print(){
			for (auto i:m){                              //For each loop to iterate over hash map
				cout<<i.first<<"->";                     //To print key(vertex)
				for (auto neighbour:i.second){           //Traversing each key to print its list of values
					cout<<neighbour<<", ";
				}
				cout<<endl;
			}
		}
		
		void BFS(T src){
			queue<T> q;
			map <T,bool> visited;    //Key-Vertex, Value-True/False
			q.push(src);
			visited[src]=true;
			
			while (!q.empty()){
				T node=q.front();
				q.pop();
				cout<<node<<" ";
				for (auto neighbour: m[node]){
					if (!visited[neighbour]){
						q.push(neighbour);
						visited[neighbour]=true;
					}
				}
			}
		}	
		
		void DFSHelper(T node, map<T, bool> &visited){
			cout<<node<<" ";
			visited[node]=true;
			
			for (auto children:m[node]){
				if (!visited[children]){
					DFSHelper(children, visited);
				}
			}
		}
		
		int DFS(){
			map<T, bool>visited;
			int component=0;
			for (auto i:m){
				if (!visited[i.first]){
					component++;
					DFSHelper(i.first, visited);
				}
			}
			cout<<endl<<"Number of components=";
			return component;
		}
		
		
		
		
		void SSSP(T src){
			queue<T> q;
			map <T,int> distance;    //Key-Vertex, Value-True/False
			map <T,T> parent;       //Parent-child map
			q.push(src);
			
			for (auto i:m){
				distance[i.first]=INT_MAX;   //Initial distance=0
			}
			
			distance[src]=0;
			parent[src]=src;
			
			while (!q.empty()){
				T node=q.front();
				q.pop();
				//cout<<node<<" ";
				for (auto children: m[node]){
					if (distance[children]==INT_MAX){
						q.push(children);
						distance[children]=distance[node] + 1;
						parent[children]=node;
					}
				}
			}
			
			
			for (auto d:distance){
				cout<<d.first<<"->"<<d.second<<endl;
		}
		
		/*
				int i=d.first;
				while (i[parent]!=src){
					cout<<i[parent]<<" ";
					i=i[parent];
				}
				cout<<src;
			}
			
			*/
		}
	
};


int main(){
	
	/*
	
	Graph <string> g;
	g.addEdge("Trump","Modi",true);
	g.addEdge("Modi", "Yogi", true);
	g.addEdge("Yogi", "Prabhu");
	g.addEdge("Putin", "Trump");
	g.addEdge("Putin", "Modi");
	g.addEdge("Putin", "Pope");
	g.addEdge("Prabhu", "Modi");
	
	g.print();
	
	*/
	Graph <int> g;
	g.addEdge(0,1);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(3,4);
	
	g.BFS(0);
	cout<<endl;
	g.SSSP(0);
	cout<<g.DFS();
	
	return 0;
}
