//Ways in (n*m) empty grid

#include<iostream>
using namespace std;

int CountWays(int n, int m, int i, int j)
{
	if (i==0 || j==0)
		return 1;
	
	
	return (CountWays(n,m,i-1, j) + CountWays(n,m,i,j-1));
}

int main()
{
	int n,m;
	cin>>n>>m;
	
	cout<<CountWays(n, m, n-1, m-1);	
	
	return 0;
}
