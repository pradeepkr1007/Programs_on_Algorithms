//Chess Elephant : Moves straight in row or column (not diagonal); can take any number of steps

#include<iostream>
using namespace std;

int elephant(int i, int j)
{
	//Base Case
	if (i==0 && j==0)
		return 1;
	
	//Recursive Case
	int ans=0;
	
	for (int k=1; k<=i;k++)
		ans+=elephant(i-k,j);
		
	for (int k=1; k<=j;k++)
		ans+=elephant(i,j-k);
	
	return ans;
	
	/*
	
//	THIS WAS WRONG because one inner loop has to be called first, not the innermost.

	int sumj=0,	sumi=0;
	int i2=i;
	int j2=j;

	for (i2-1; i2>=0;i2--)
	{
		sumj+=elephant(i2,j);
		cout<<sumj<<endl; /////////////
	}
	

	for (j2-1; j2>=0; j2--)
	{
		sumi+=elephant(i,j2);
		cout<<sumi<<endl; ///////////
	}
	
	return sumi+sumj;
	*/

}

int main()
{
	int n,m;
	cin>>n>>m;
	cout<<elephant(n-1, m-1);	
	return 0;
}

