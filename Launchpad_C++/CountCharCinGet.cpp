/*

Modify the above to print total number of digits, whitespaces, alphabets and other characters till you read a $.

*/


#include<iostream>
using namespace std;

int main()
{
	int cntd=0, cntspaces=0, cntal=0, cntother=0;
	while (true)
	{
		char ch;
		ch=cin.get();        //IMPORTANT- same as cin>>ch but reads spaces and \n also. Copies the buffer as it is.
		if (ch=='$')
			break;
		else if (ch>='0' and ch<='9')
			cntd++;
		else if (ch==' ')
			cntspaces++;
		else if ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
			cntal++;
		else
			cntother++;
	}
	cout<<"Digits: "<<cntd<<endl;
	cout<<"Whitespaces: "<<cntspaces<<endl;
	cout<<"Alphabets: "<<cntal<<endl;
	cout<<"Other characters: "<<cntother<<endl;
	return 0;
}
