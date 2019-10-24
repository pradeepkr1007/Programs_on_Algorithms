//Sum of array using recursion

#include<iostream>
using namespace std;

int sumarray(int a[], int n)
{
	if (n==0)
		return 0;
	
	return (a[n-1]+sumarray(a, n-1));
}

int main()
{
	int n;
	cin>>n;
	int a[100];
	for (int i=0; i<n; i++)
		cin>>a[i];
		
	cout<<sumarray(a,n);
	
	return 0;
}


/*

int SumOfArray(int a[], int n, int i)
{
	if (i==n)
		return 0;
		
	return ( a[i] + SumOfArray(a,n,i+1) );
}

While calling,
SumOfArray(a,n,0);

*/
