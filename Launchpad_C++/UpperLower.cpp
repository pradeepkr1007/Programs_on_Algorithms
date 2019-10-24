#include<iostream>
using namespace std;

//A=65, Z=90
//a=97, Z=122
int main()
{
	char a;
	cin>>a;
	if (a>='A' && a<='Z')
		cout<<endl<<"Upper Case";
	else if (a>='a' && a<='z')
		cout<<endl<<"Lower Case";
	else	
		cout<<endl<<"Invalid";
		
	return 0;
}
