//Append string B to string A

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


void append( char a[], char b[])
{
	int len_a=length(a);
	int len_b=length(b);
	int i=0;
	for (i; i<len_b; i++)
	{
		a[len_a+i]=b[i];
	}
	a[len_a+i]='\0';
}

int main()
{
	char a[100], b[100];
	cin.getline(a,100);
	cin.getline(b,100);
	
	append(a,b);
	
	cout<<a;
	return 0;
}
