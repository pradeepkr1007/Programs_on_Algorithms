#include<iostream>
using namespace std;

void bubblesort(int *a, int n)
{
	for (int i=0;i<n-1;i++)
	{
		
		//Comparison of adjacent numbers in pairs
		for (int j=0;j<n-1-i;j++)
			if(*(a+j)>*(a+j+1))
				swap(*(a+j),*(a+j+1));
	}
	return;
}

int main()
{
	int a[100];
	
	//Length of Array
	int n;
	cin>>n;
	
	//Array input
	int i=0;
	for (i;i<n;i++)
	{
		cin>>a[i];
	}
	
	bubblesort(a,n);
	
	//Printing sorted array
	for (int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	
	return 0;
	
}
