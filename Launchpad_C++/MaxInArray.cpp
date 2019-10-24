//Max elememt in array

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
	
	int max;
	max=a[0];
	i=0;
	for (i;i<n;i++)
	{
		if (a[i]>max)
			max=a[i];
	}
	cout<<"Maximum element="<<max;
	return 0;
}
