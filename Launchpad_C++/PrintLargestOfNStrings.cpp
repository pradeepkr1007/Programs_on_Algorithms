//Read n strings from a user and print the largest string (according to size)

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

int main()
{
	int n;
	cin>>n;
	cin.get();
	char largest[100];
	int len_largest=0;
	for (int i=0; i<n; i++)
	{
		char a[100];
		cin.getline(a,100);
		if (length(a)>len_largest)
		{
			len_largest=length(a);
			int i=0;
			for (i; i<len_largest; i++) 
			{
				largest[i]=a[i];
			}
			largest[i]='\0';
					
		}
	}
	
	cout<<largest;
	return 0;
}
