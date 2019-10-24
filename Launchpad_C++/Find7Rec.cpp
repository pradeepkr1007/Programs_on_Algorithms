//Given an array, return the index of first occurence of 7

#include<iostream>
using namespace std;

int Find7(int a[],  int n, int i)
{
	if (i==n)
		return -1;
	
	if (a[i]==7)
		return i;

	return Find7(a,n, i+1);
}

int main()
{
	int n;
	cin>>n;
	int a[100];
	for (int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	
	cout<<Find7(a,n,0);
	
	return 0;
}
