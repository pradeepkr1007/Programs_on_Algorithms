/* Print the below pattern:

    1
   232
  34543
 4567654
567898765

*/


//i=line number
//j=spaces
//j=element number
//k=element
#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter number of lines in pattern:";
	cin>>n;
	
	int i=1;
	for (i;i<=n;i++)
	{
		int j=n-i;
		for (j;j>=1;j--)
			cout<<" ";
		int k=i;
		j=1;
		for (j;j<=i;j++)
		{
			cout<<k;
			k++;
		}
		k=k-2;
		j=1;
		for (j;j<i;j++)
		{
			cout<<k;
			k--;
		}
		cout<<"\n";
	}
	return 0;
 } 
