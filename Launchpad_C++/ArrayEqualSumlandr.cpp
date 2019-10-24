//Find index of element in array, whose sum of elements on its left is the same as the sum of elements on its rights.

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[100];
	for (int i=0; i<n; i++)
		cin>>a[i];
	
	int ans=-1;
	
	for (int j=0; j<n; j++)
	{
		int s1=0, s2=0;
		for (int k=0; k<j; j++)
		{
			s1+=a[k];	
		}
		
		for (int k=j+1; k<n; k++)
		{
			s2+=a[k];
		}
		
		if (s1==s2)
		{
			cout<<2;
			ans=j;
			break;
		}
	}
		
	cout<<ans;
	return 0;
}
