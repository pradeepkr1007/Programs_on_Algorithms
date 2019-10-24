//LinearSearchinArray

#include<iostream>
using namespace std;

int main()
{
	int a[20];
	int n;
	cin>>n;
	int i=0;
	for (i;i<n;i++)
	{
		cin>>a[i];
	}
	
	int num;
	cin>>num;
	for (i=0;i<n;i++)
	{
		if (a[i]==num)
		{
			cout<<i;
			break;
		}
    }
	if (i==n)
		cout<<-1;
	return 0;
}
	
	
