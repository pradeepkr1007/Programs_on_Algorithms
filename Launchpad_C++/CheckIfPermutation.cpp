//WAP to check if 2 strings are permutations of each other

#include<iostream>
#include<algorithm>
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

bool permutation(char a[], char b[])
{
	int lena=length(a), lenb=length(b);
	
	if (lena!=lenb)
		return false;
	
	sort(a, a+lena);
	sort(b, b+lenb);
	
	for (int i=0; i<lena; i++){
		
	if ( a[i] == b[i])
		return true;
	
	else
		return false;
	}
}


int main()
{
	char a[100], b[100];
	cin.getline(a,100);
	cin.getline(b,100);
	
	int ans= permutation(a,b);
	
	if (ans)
		cout<<"Yes";
	else
		cout<<"No";
	
	return 0;
}




/*

ABOVE METHOD TAKES IS OF O(n^2), WHILE BELOW METHOD OF O(n)

Maintain an array with frequency of elements

int freq[26]={0};

for (int i=0; a[i]!='\n'; i++)
{
	int index= a[i]-'a';   //Subtract the character with smallest ASCII value among those input by the user
	freq[index]++;
}


for (int i=0; i<26; i++)
{
	cout<<freq[i]<<" ";
}

*/
