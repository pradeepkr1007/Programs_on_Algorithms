/*Print:

1
23
456
78910
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	cout<<endl;
	int k=1, i=1;
	for (i;i<=n;i++)
	{
		int j=1;
		for (j;j<=i;j++)
		{
			cout<<k;
			k++;
		}
		cout<<endl;
	}
	
	return 0;
}
