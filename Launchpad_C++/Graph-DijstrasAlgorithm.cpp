#include<iostream>
#include<set>
#include<map>
#include<list>
#include<climits>

using namespace std;

template <typename T>

class Graph{
	
	map < T, list< pair <T,int> > > h;
	
	public:
		void addEdge(T u, T v, int d, bool bidir=true){
			h[u].push_back(make_pair(v,d));
			if (bidir){
				h[v].push_back(make_pair(u,d));
			}
		}
		
		void print(){
			for (auto i:h){
				cout<<i.first<<"->";
				for (auto neighbour:i.second){
					cout<<"("<<neighbour.first<<","<<neighbour.second<<")"<<" ";
				}
				cout<<endl;
			}
		}
		
		void SSSP(T src){                  //Dijkstra's Algo
			map <T,int> dist;
			
			for (auto i:h){
				dist[i.first]=INT_MAX;
			}
			
			set < pair<int,T> > s;            //Set sorts according to first parameter by default (here, distance)
			dist[src]=0;
			s.insert(make_pair(0,src));
			
			while (!s.empty()){
				auto p=*s.begin();         //Begin returns address. So p stores first pair in set
				int nodeDistance=p.first;  //p is a pair of int distance and T node.
				T node=p.second;
				
				s.erase(s.begin());        //Removes first element from set
				
				for (auto child: h[node]){
					if ( nodeDistance + child.second < dist[child.first] ){                //Stored as Amritsar->(Delhi,1)(Jaipur,2)
						T name=child.first;
						auto f=s.find( make_pair ( dist[name]) , name );      //Iterate over all pairs in set
						if ( f!=s.end() ){                                                 //f (pair) not found
							s.erase( make_pair ( dist[name] ) , name );      //Deleting old value to insert updated value
						}
						dist[name] = nodeDistance + child.second ;                  //Updated distance
						s.insert( make_pair (dist[name]) , name );           //Updating by inserting new value
					}  

				}
			}
			
			for (auto i:dist){
				cout<<"Distance of "<<i.first<<" from "<<src<<" is "<<i.second<<endl;
			}
			
		}
		
};

int main(){
	
	Graph <string> g;
	
	g.addEdge("Amritsar", "Agra", 1);
	g.addEdge("Amritsar", "Jaipur", 4);
	g.addEdge("Delhi", "Agra", 1);
	g.addEdge("Delhi", "Jaipur", 2);
	g.addEdge("Agra", "Bhopal", 1);
	
	g.print();
	g.SSSP("Delhi");
	
	
	return 0;
}
