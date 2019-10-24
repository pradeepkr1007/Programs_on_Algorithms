/*Print:
1
01
101
0101
10101
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	cout<<endl;
	int i=1;
	for (i;i<=n;i++)
	{
		int j=1,k;
		for (j;j<=i;j++)
		{
			if ((i+j)%2==0)
				k=1;
			else
				k=0;
			cout<<k<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
