//Write a function to reverse a string

#include<iostream>
using namespace std;


int length(char a[])
{
	int i=0;
	int len=0;
	for (i; a[i]!='\0';i++)
	{
		len++;
	}
	return len;
}

void reverse(char a[])
{
	int n=length(a);
	int k=n-1;
	char b[100];
	for (k; k>=0; k--)
	{
		b[n-1-k]=a[k];
	}
	
	int i=0;
	for (i; i<n; i++)
	{
		a[i]=b[i];
	}
	a[i]='\0';
}

int main()
{
	char a[1000];
	cin.getline(a,100);
	
	reverse(a);
	
	cout<<a;
	
	return 0;
	
}


//INSTEAD OF TAKING NEW ARRAY, TAKE 2 POINTERS I AND J.
//I FROM START AND J FROM END
//KEEP REPLACING THEM
