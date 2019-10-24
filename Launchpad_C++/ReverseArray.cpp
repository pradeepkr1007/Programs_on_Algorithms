//ReverseArrays

#include<iostream>
using namespace std;

int main()
{
	int a[20];
	int n;
	cin>>n;
	int i=0;
	for (i;i<n;i++)
	{
		cin>>a[i];
	}
	
	//reverse print
	i=n-1;
	for (i;i>=0;i--)
	{
		cout<<a[i];
	}
	
	return 0;
}
