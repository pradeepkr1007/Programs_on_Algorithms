#include<iostream>
using namespace std;

class Pair
{ 
	public:
		int x;
		int y;
		
		Pair(int a, int b)    //Pair(int a, int b):x(a), y(b){}
		{
			x=a;
			y=b;
		}
	
		bool operator<(Pair &p)
		{
			if (x<p.x && y<p.y)
				return true;
			else
				return false;
		}
		
		bool operator>(Pair &p)
		{
			if (x>p.x && y>p.y)
				return true;
			else
				return false;
		}
		
		bool operator=(Pair &p)
		{
			if (x==p.x && y==p.y)
				return true;
			else
				return false;
		}		
			
		void print()
		{
			cout<<"("<<x<<","<<y<<")"<<endl;
		}
};

int main()
{
	Pair p1(4,3);
	Pair p2(8,5);
	cout<<(p1<p2)<<endl;
	cout<<(p1>p2)<<endl;
	cout<<(p1=p2)<<endl;
	return 0;
	
}
