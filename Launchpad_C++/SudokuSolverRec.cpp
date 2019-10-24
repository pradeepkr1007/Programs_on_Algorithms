//Sudoku Solver

#include<iostream>
#include<cmath>
using namespace std;


bool isSafe(int mat[][9], int i, int j, int n, int number){
	for (int k=0; k<n;k++){
		if (mat[i][k]==number || mat[k][j]==number)
			return false;
	}
	
	n=sqrt(n);
	i=(i/n)*n;
	j=(j/n)*n;
	
	for (int k=i; k<i+n; k++){
		for (int l=j; l<j+n; l++){
			if (mat[k][l]==number)
				return false;
		}
	}
	
	return true;
}

bool SudokuSolver(int mat[][9], int i, int j, int n){
	//Base Case
	if (i==n){
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}
		return true;
	}
	
	//Other Cases
	if (j==n)
		return SudokuSolver(mat, i+1, 0, n);      //All columns in one row traversed

	
	if (mat[i][j]!=0)                             //Position already filled
		return SudokuSolver(mat, i, j+1, n);
		
	//Recursive Case
	for (int num=1; num<=n; num++){
		if (isSafe(mat,i,j,n,num)){
			mat[i][j]=num;
			if (SudokuSolver(mat,i,j+1,n))
				return true;
			mat[i][j]=0;                           //Number can't be placed
		}
	}
	return false;                                  //No possible number found
}



int main(){
	int mat[9][9] =
		{{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}};

	
	SudokuSolver(mat, 0, 0, 9);
	return 0;
}
