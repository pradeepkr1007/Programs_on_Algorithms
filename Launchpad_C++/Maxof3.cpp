#include<iostream>
using namespace std;

int main()
{
	cout<<"Enter 3 numbers:\n";
	int a,b,c,max;
	cin>>a>>b>>c;
	if (a>b && a>c)
		max=a;
	else if (b>c)
		max=b;
	else
		max=c;
	cout<<"Maximum = "<<max;
	
	return 0;
}

