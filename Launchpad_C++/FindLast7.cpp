//Given an array, return the index of last occurence of 7, starting from the start

#include<iostream>
using namespace std;

int Find7(int a[],  int n, int i, int index)
{
	if (i==n)
		return index;
	
	if (a[i]==7)
		index=i;

	return Find7(a,n, i+1,index);
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
	
	cout<<Find7(a,n,0,-1);
	
	return 0;
}
