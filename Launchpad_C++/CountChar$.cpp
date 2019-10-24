#include<iostream>
using namespace std;

int main()
{
	int cnt=0;
	while (true)
	{
		char ch;
		ch=cin.get();        //IMPORTANT- same as cin>>ch but reads spaces and \n also. Copies the buffer as it is.
		if (ch=='$')
			break;
		cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
