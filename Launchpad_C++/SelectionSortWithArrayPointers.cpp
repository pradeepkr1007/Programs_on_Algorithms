#include<iostream>
using namespace std;

void selectionsort(int *a, int n)
{
	//n-1 outer loops
	for (int i=0; i<n-1; i++)         //n-1 steps, but index starts from 0
	{
		
		//Find smallest at each outer loop
		int smallest=i;              //Let the first element be the smallest
		for (int j=i+1; j<n; j++)    //Even last element has to be considered
		{
			if (*(a+j)<*(a+smallest))
			{
				smallest=j;
			}
		}
		
		//Swapping smallest and i
		int temp=*(a+i);
		*(a+i)=*(a+smallest);
		*(a+smallest)=temp;
		
	}
	
	return;
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
	
	selectionsort(a,n);
	
	//Printing sorted array
	for (int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	
	return 0;
	
}
