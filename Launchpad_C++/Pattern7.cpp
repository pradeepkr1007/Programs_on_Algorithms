/*
Print:


*     *
**   **
*** ***
*******


*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int i=1;
	for (i;i<=n;i++)
	{
		int j=1;
		for (j;j<=i;j++)
		{
			cout<<"*";
		}
		j=1;
		for (j;j<=n-i;j++)
		{
			cout<<" ";
		}
		j=1;
		for (j;j<n-i;j++)
		{
			cout<<" ";
		}
		j=1;
		if (i==n)
		{
			for (j;j<i;j++)
			{
				cout<<"*";
			}
		}
		else
		{	
		for (j;j<=i;j++)
		{
			cout<<"*";
		}
	}
		cout<<endl;
	}
	
	return 0;
	
}

