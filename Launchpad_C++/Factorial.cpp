//Factorial

#include<iostream>
using namespace std;

int factorial(int n)
{
	if (n==1)  // or (n==0). Saving 1 step here.
		return 1;
	return (n*factorial(n-1));
}


int main()
{
	int n;
	cin>>n;
	cout<<factorial(n);
	return 0;
}
