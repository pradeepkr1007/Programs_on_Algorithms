/*
1
23
456
78910
*/

#include<iostream>
using namespace std;

int main()
{
	cout<<"Enter number of lines:";
	int n;            //n=total no. of lines
	cin>>n;
	cout<<"\n";
	int i=1,k=1;
	while (i<=n)      //i=line no.
	{
		int j=1;
		while (j<=i)  //j=element no.
		{ 
			cout<<k;  //k=element to be printed
			k++;
			j++;
		}
		cout<<"\n";
		i++;
	}
	
	return 0;
}
