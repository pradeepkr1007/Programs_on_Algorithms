#include<iostream>
using namespace std;

int main()
{
	char a='A';
	char *ch=&a;
	cout<<(void *)ch<<endl;
	int *p, *c;
	cout<<p<<endl;
	cout<<c<<endl;
	return 0;
}
