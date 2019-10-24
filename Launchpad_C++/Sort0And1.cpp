#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[100];
	for (int i=0; i<n; i++)
		cin>>a[i];
	
	int cnt=0;
	for (int j=0; j<n; j++)
	{
		if (j==0)
			cnt++;
	}
	
	for (int i=0; i<n; i++)
	{
		if (cnt>=0)
		{
			cout<<0;
			cnt--;
		}
		else
			cout<<1;
	}
		
	return 0;
}
