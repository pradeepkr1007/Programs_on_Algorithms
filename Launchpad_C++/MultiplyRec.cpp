//Multiply 2 numbers x and y without using *, and using recursion.

#include<iostream>
using namespace std;

int mul(int x, int y)
{
	if (y==0)               //if (y==1)
		return 0;           //return 0;s
	
	return x+mul(x, y-1);
}

int main()
{
	int x, y;
	cin>>x>>y;
	cout<<mul(x,y);
	return 0;
}
