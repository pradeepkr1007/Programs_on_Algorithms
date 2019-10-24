//NCR

#include<iostream>
using namespace std;

int factorial(int n)
{
	if (n==0 || n==1)
		return 1;
	return (n*factorial(n-1));
}

int NCR(int n, int r)
{
	int num=factorial(n);
	int den=factorial(n-r)*factorial(r);
	return (num/den);
}

int main()
{
	int n,r;
	cin>>n>>r;
	cout<<NCR(n,r);
	return 0;
}
