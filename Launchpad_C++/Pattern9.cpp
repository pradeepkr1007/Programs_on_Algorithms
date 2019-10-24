/*
Print:

ABCDEEDCBA
ABCDDCBA
ABCCBA
ABBA
AA

*/

#include<iostream>
using namespace std;

int main ()
{
	int n;
	cin>>n;
	int i=1;
	for (i;i<=n;i++)
	{
		char k='A';
		int j=1;
		for (j;j<=n-i+1;j++)
		{
			cout<<k;
			k++;
		}
		k--;
		j=1;
		for (j;j<=n-i+1;j++)
		{
			cout<<k;
			k--;
		}
		cout<<endl;
	}
	return 0;
}
