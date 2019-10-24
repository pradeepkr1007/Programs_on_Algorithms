//N-Queen Problem

#include<iostream>
using namespace std;

bool conflict(int board[][100], int i, int j, int n)
{
	//Column conflict
	for (int k=0; k<n; k++)
		if (board[i][k]==1 || board[k][j]==1)
			return true;
	
	//Diagonal conflict- left to right
	int r=i, c=j;
	while (r>=0 && c>=0)
	{
		if (board[r][c]==1)
			return true;
		r--;
		c--;
	}
	
	//Diagonal Conflict- right to left
	r=i; c=j;
	while(r>=0 && c<n)
	{
		if (board[r][c]==1)
			return true;
		r--;
		c++;
	}
	
	//No conflict. Safe.
	return false;
	
}


bool NQueen(int board[][100], int i, int j, int n)
{
	//Base Case
	if (i==n)
	{
		//Printing solution
		for (int i=0; i<n; i++)
		{
			for (int j=0; j<n; j++)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
		return true; //Solution found   //Return false if all possible solutions to be printed.
	}
	
	
	//Iterate every column in a row
	for (j=0; j<n; j++)
	{
		if (!conflict(board,i,j,n))  //if it is safe
		{
			board[i][j]=1;
			if (NQueen(board, i+1, j, n))
				return true;
			board[i][j]=0;           //else backtrack
		}
	}
	return false; //If no solution is found in any column
}


int main()
{
	int n;
	cin>>n;
	int board[100][100]={0};

	NQueen(board, 0, 0, n);

	return 0;
}
