//Check if array is sorted using recursion.

#include<iostream>
using namespace std;

bool IsSorted(int a[], int n)
{
	if (n==0 || n==1)
		return true;
	
	bool issmallerarraysorted=IsSorted(a+1, n-1);
	
	if (a[0]<a[1] && issmallerarraysorted)   //checking first two elements ourselves and using recursion
		return true;
	else
		return false;
}

int main()
{
	int n;
	cin>>n;
	int a[1000];
	for (int i=0; i<n; i++)
		cin>>a[i];
		
	if (IsSorted(a,n))0
		cout<<"Sorted";
	else
		cout<<"Not Sorted";
		
	return 0;
}
