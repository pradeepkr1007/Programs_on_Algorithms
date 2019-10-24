//WAP to print all substrings of a given string

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

void substrings(char a[])
{
	int len=length(a);
	for (int i=1; i<=len; i++)                    //length of substring
	{
		for (int j=0; j<=len-i; j++)              //starting letter
		{      
			for (int k=j; k<=j+i-1; k++)          //letter to be printed
		{
			cout<<a[k];
		}
		cout<<endl;
	 } 
	}
}


int main()
{
	char a[1000];
	cin.getline(a,100);
	
	substrings(a);
	
	return 0;
}
