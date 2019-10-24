//Print reverse array using recursion

#include<iostream>
using namespace std;

void PrintSortedArray(int a[], int n, int i) //n=length, i=elements printed
{
	if (i==n) //All elements printed, exit.
		return;
	
	PrintSortedArray(a,n,i+1); //cout<<a[i]<<" ";   IF ACTUAL ARRAY TO BE PRINTED
	cout<<a[i]<<" ";          //PrintSortedArray(a,n,i+1);  
}

int main()
{
	int n;
	cin>>n;
	int a[1000];
	for (int i=0; i<n; i++)
		cin>>a[i];
	
	PrintSortedArray(a,n, 0);
	
	return 0;
}
