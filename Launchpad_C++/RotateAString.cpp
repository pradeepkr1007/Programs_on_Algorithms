//Given a string, rotate a string by n characters

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

int rotate(char a[], int n)
{
	int len=length(a);
	while (n>0)
	{
		int temp=a[len-1];
		for (int i=len-2; i>=0; i--)
		{
			a[i+1]=a[i];
		}
		a[0]=temp;
		n--;
	}
	a[len]='\0';
}

int main()
{
	char a[1000];
	int n;
	cin.getline(a,100);
	cin>>n;
	
	rotate(a,n);
	
	cout<<a;
	
	return 0;
	
}

