//Convert string to integer: "12345" to 12345

#include<iostream>
#include<cstring>
using namespace std;


int convert (string s, int n)              //(string s, int ans, int i, int n)
{
	if (n==0) 
		return 0;
	int last=s[n-1]-'0';                   //int first=s[i]-48;
	return convert(s,n-1)*10+last;         //return (convert(s, 10*ans+first, i+1, n-1));
}


int main()
{
	string s;
	cin>>s;
	int ans=0;
	cout<<convert(s, s.length());         //cout<<convert(s,ans, 0, s.length());
	return 0;
}
