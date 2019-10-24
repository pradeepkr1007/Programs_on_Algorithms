#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter number:\n";
	cin>>n;
	int i=2;
	for (i;i<n;i++)
	{
		if (n%i==0)
		{
			cout<<"Not prime\n";
			break;            //return 0;
		}
	}
	if (n==i)                 //not required if return 0 above
		cout<<"Prime\n";
		
	return 0;
}

