//Rat in a maze: Find possible way(s) for rat to reach from source to destination in a maze.

#include<iostream>
using namespace std;


bool RatInmaze (char maze[][10], int sol[][10], int m, int n, int i, int j)
{
	//Base Case
	if (i==(m-1) && j==(n-1))
	{
		//Destination part of solution
		sol[i][j]=1;
		
		//Printing Solution
		for (int i=0; i<m; i++)
		{
			for (int j=0; j<n; j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false; //To print all solutions. Else, return false after printing.
	}
		
		
	sol[i][j]=1;
	
	//Check right
	if (j<=n-1 && maze[i][j+1]!='X')
		if(RatInmaze(maze,sol,m,n,i,j+1))
			return true;
		
		
	//Check down
	if (i<=m-1 && maze[i+1][j]!='X')
		if(RatInmaze(maze,sol,m,n,i+1,j))
			return true;
	
	//Backtrack
	sol[i][j]=0;
	return false;
}

int main()
{
	char maze[][10]={"000X","00X0","0000","XX00"};
	int sol[10][10]={0};
	RatInmaze(maze,sol,4,4,0,0);
	return 0;
}
