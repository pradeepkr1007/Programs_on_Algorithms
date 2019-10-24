//Sum of array

#include<iostream>
using namespace std;

int sumofarray(int *a, int n)
{
	int sum=0;
	for (int i=0; i<n; i++)
	{
		sum+=*(a+i);
	}
	return sum;
}
int main()
{
	int a[100];
	
	//Length of Array
	int n;
	cin>>n;
	
	//Array input
	int i=0;
	for (i;i<n;i++)
	{
		cin>>a[i];
	}	
	
	int ans=sumofarray(a,n);
	cout<<"Sum= "<<ans;
	
	return 0;
}
