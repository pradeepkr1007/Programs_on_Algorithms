#include<iostream>
using namespace std;

int main()
{
	int n,p;
	cout<<"Enter number and precision:"<<endl;
	cin>>n>>p;
	int currentp;
	float i=0;                                     //Whole number+precision=precision+1
	float inc=1;
	while (currentp<=p)
	{
		while (i*i<=n)
		{
			i=i+inc;
		}	
		i=i-inc;
		inc=inc/10;
		currentp++;
	}
	cout<<i;
	return 0;
}

