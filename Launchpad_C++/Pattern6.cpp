/* Print:

54321012345
 432101234
  3210123
   21012
    101
     0
    101
   21021
  3210123
 432101234
54321012345
     
*/


#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	cout<<endl;
	int i=0;
	for (i;i<n;i++)
	{
		int k=n-i-1;
		int j=0;
		for (j;j<i;j++)
		{
			cout<<"  ";
		}
		j=1;
		for (j;j<=n-i;j++)
		{
			cout<<k<<" ";
			k--;
		}
		k+=2;
		j=1;
		for (j;j<n-i;j++)
		{
			cout<<k<<" ";
			k++;
		}
		cout<<endl;
	}
	
	i=1;
	for (i;i<n;i++)
	{
		int k=i;
		int j=1;
		for (j;j<=n-1-i;j++)
		{
			cout<<"  ";
		}
		j=1;
		for (j;j<=i+1;j++)
		{
			cout<<k<<" ";
			k--;
		}
		k+=2;
		j=1;
		for (j;j<i+1;j++)
		{
			cout<<k<<" ";
			k++;
		}
		cout<<endl;
		
	}
	
	
	
	return 0;
	
}
