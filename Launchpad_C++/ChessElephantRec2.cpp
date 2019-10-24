//Chess Elephant : Moves straight in row or column (not diagonal); can take any number of steps

#include<iostream>
using namespace std;

int elephant(int i, int j)
{
	//Base Case
	if (i==0 && j==0)
		return 1;
	
	//Recursive Case
	
	int sumj=0;
	int i2=i;
	int j2=j;
	for (i2;i2>=0;i2--)
		sumj+=elephant(i2,j);
		
	int sumi=0;
	for (j2; j2>=0; j2--)
		sumi+=elephant(i,j2);
	
	return sumi+sumj;

}

int main()
{
	int n,m;
	cin>>n>>m;
	cout<<elephant(n-1, m-1);	
	return 0;
}

