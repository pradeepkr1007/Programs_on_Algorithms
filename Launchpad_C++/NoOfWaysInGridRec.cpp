//Ways in (n*m) empty grid

#include<iostream>
using namespace std;

int CountWays(int i, int j)
{
	//Base Case
	if (i==0 && j==0)
		return 1;
	
	//Boundary Condition
	if (i<0 || j<0)
		return 0;
	
	//Recursive Case
	return (CountWays(i-1, j) + CountWays(i,j-1));
}

int main()
{
	int n,m;
	cin>>n>>m;
	cout<<CountWays(n-1, m-1);	
	return 0;
}
