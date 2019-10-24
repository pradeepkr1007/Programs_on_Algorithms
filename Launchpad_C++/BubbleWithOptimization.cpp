//Bubble Sort

#include<iostream>
using namespace std;

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
	
	//n-1 outer loops
	for (int i=0;i<n-1;i++)
	{
		int cnt=0;
		//Comparison of adjacent numbers in pairs
		for (int j=0;j<n-1-i;j++)
			if(a[j]>a[j+1])
			{
				swap(a[j],a[j+1]);
				cnt++; //cnt=0 when no swapping required as already sorted
			}
		if(cnt==0)
			break; //No swapping takes place, so further loops don't take place
	}

	
	//Printing sorted array
	for (int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	
	return 0;
}
