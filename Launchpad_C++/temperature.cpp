#include<iostream>
using namespace std;

int main()
{
	int i,f,s;
	cout<<"Enter initial temperatue, final temperature and step value:";
	cin>>i>>f>>s;
	cout<<"\nTemperatures in Celsius:\n";
	int j=i;
	for (j;j<=f;j+=s)
	{
		int c;
		c=(5/9.0)*(j-32);
		cout<<j<<"\t"<<c<<'\n';
	}
	return 0;
}
