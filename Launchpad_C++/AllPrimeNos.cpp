
//Print all prime numbers between 2 to N

#include<iostream>
using namespace std;

int main()
{
	cout<<"Enter n:";
	int n;
	cin>>n;
	int i=2;
	for (i;i<=n;i++)
	{
		int j=2;
		for (j;j<i;j++)
		{
			if (i%j==0)
				break;
		}
		if (i==j)
			cout<<i<<" ";
	}
	return 0;
}
