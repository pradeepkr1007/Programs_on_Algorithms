#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[100];
	
	for (int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	
	
	int c[10]={0};

	for (int j=0; j<n;j++)
	{
		c[a[j]]++;
	}
	
	for (int j=0; j<10; j++)
	{
		if (c[j]>0)
			cout<<j<<" "<<c[j]<<endl;
	}
	
	//converting input int to array
	for (int j=0;j<i;j++)
	{
		a[i-1-j]=n%10;
		n/=10;
	}
	
	for (int j=0; j<i; j++)
	{
		cout<<a[j]<<endl;
	}
	
	/*
	
	for (int j=0; j<n; j++)
	{
		int cnt=0;
		c[2*j]=a[j];
		for (int k=0; k<n; k++)
		{
			if (k==j)
				cnt++
		}
		c[2*j+1]=cnt;		
	}
	
	for (int j=)
	
	*/
	return 0;
}
