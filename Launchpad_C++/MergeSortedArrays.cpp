/*
2 sorted arrays a and b 
length of a=n+m, elements in a=n
length of b=m, elements in b=m
merge all in a
*/

//IMPORTANT: Compare a and b from the end.
//If compared from start, when one array ends, comparison with 0 takes place and answer will be wrong.

#include<iostream>
using namespace std;

//i=m-1
//j=n-1
//k=m+n-1

void merge(int a[], int b[], int i, int j, int k)
{
	while (i>=0 && j>=0)
	{
		if (a[i]>b[j])
		{
			a[k]=a[i];
			k--;
			i--;
		}
		
		else
		{
			a[k]=b[j];
			k--;
			j--;
		}
	}
		while (i>=0)
		{
			a[k]=a[i];
			k--;
			i--;
		}
		
		while (j>=0)
		{
			a[k]=b[j];
			k--;
			j--;
		}
}
	



int main()
{
	int m,n;
	int a[100], b[100];
	
	cin>>m;
	for (int i=0; i<m; i++)
		cin>>a[i];
		
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>b[i];
		
	merge(a,b,m-1,n-1,m+n-1);
	
	for (int i=0; i<n+m; i++)
		cout<<a[i]<<" ";
	
	return 0;
	
}
