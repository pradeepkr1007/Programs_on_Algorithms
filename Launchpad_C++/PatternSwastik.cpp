/*

Pattern:

*     * * * *
*     *
*     *
* * * * * * *
      *     *
      *     *
* * * *     *

*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	for (int i=1; i<=n; i++)
	{
		if (i==1)
		{
			cout<<"* ";
			for (int k=1; k<n/2; k++)
				cout<<"  ";
			for (int k=1; k<=n/2+1; k++)
				cout<<"* ";
		}
		
		else if (i==n)
		{
			for (int k=1; k<=n/2+1; k++)
				cout<<"* ";	
			for (int k=1; k<n/2; k++)
				cout<<"  ";
			cout<<"* ";
		}
		
		
		else if (i==n/2+1)
		{
			for (int k=1; k<=n; k++)
				cout<<"* ";
		}
		
		else if (i<n/2+1)
		{
			cout<<"* ";
			for (int k=1; k<n/2;k++)
			{
				cout<<"  ";
			}
			cout<<"* ";
		}
			
		else if (i>n/2+1)
		{
			for (int k=n/2+1; k<=n-1; k++)
			{
				cout<<"  ";
			}
			cout<<"* ";
			for (int k=n/2+1; k<n-1; k++)
			{
				cout<<"  ";
			}
			cout<<"* ";
		}
		
		cout<<endl;
	}
	return 0;
}
