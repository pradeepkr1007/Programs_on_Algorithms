//Print Fibonacci using recursion

#include<iostream>
using namespace std;

int fibo(int n)
{
	if ((n==0) || (n==1))
		return n;
		
	return (fibo(n-1)+(n-2));
}

int main()
{
	int n;
	cin>>n;
	cout<<fibo(n);
	return 0;
}
