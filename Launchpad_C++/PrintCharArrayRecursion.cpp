//Print reverse char array using recursion

#include<iostream>
using namespace std;

void PrintSortedArray(string a, int n) 
{
	if (n==0)
	{
		return;
    }

	cout<<a[n-1]<<" ";          
	PrintSortedArray(a,n-1); 
}

int main()
{
	int n;
	cin>>n;
	string a;
	cin>>a;
	PrintSortedArray(a,n);
	
	return 0;
}

/*

void print(char a[], int i)
{
	if (a[i]=='0''
	
	
	
*/
