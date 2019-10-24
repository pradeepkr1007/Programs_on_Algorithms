#include<iostream>
using namespace std;

int main()
{
	int x=0,y=0;
	while (true)
	{
		char a;
		a=cin.get();
		if (a=='\n')
			break;
		else if (a=='N')
			y++;
		else if (a=='S')
			y--;
		else if (a=='W')
			x--;
		else if (a=='E')
			x++;
	}
	
	
	if (x>0)
	{
		int i=1;
		while (i<=x)
		{
			cout<<'E';
			i++;
		}
	}
	if (y>0)
	{
		int i=1;
		while (i<=y)
		{
			cout<<'N';
			i++;
		}
	}
	if (y<0)
	{
		int i=-1;
		while (i>=y)
		{
			cout<<'S';
			i--;
		}
	}
	if (x<0)
	{
		int i=-1;
		while (i>=x)
		{
			cout<<'W';
			i--;
		}
	}
	
	return 0;
}
