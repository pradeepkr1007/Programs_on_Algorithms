// BUBBLE SORT USING RECURSION

#include<iostream>
using namespace std;

void BubbleSort(int a[], int n)
{
	if (n==0 || n==1) //last step. One element left, hence sorted
		return;
		
	for (int j=0; j<=n-2; j++)
		if (a[j]>a[j+1])
			swap(a[j],a[j+1]);
		
	BubbleSort(a,n-1); //Removing sorted part from array each time
}

int main()
{
	int n;
	cin>>n;
	int a[100];
	for (int i=0; i<n; i++)
		cin>>a[i];
		
	BubbleSort(a,n);
	
	for (int i=0; i<n; i++)
		cout<<a[i];
	
	return 0;
}
