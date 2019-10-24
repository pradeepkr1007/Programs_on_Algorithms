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
	int N;
	cin>>N;
	int n=(N/2)+1;
	int m=N-n;
	cout<<endl;
	
	int i=1;
	for (i;i<=m;i++)
	{
		int j=1;
		for (j;j<=m-i+2;j++)
		{
			cout<<"*";
		}
		j=1;
		for (j;j<=i-1;j++)
		{
			cout<<" ";
		}
		j=1;
		for (j;j<i-1;j++)
		{
			cout<<" ";
		}
		j=1;
		if (i==m)
		{
			for (j;j<m-i+2;j++)
			{
			cout<<"*";	
			}
		}
		else
		{
		for (j;j<=m-i+2;j++)
		{
			cout<<"*";
		}
		cout<<endl;
	}
	}
	
	
	i=1;
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

