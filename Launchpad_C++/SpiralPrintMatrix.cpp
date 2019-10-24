#include<iostream>
using namespace std;

void SpiralPrint(int a[][200], int rows, int cols)
{
	int sr=0, sc=0; // Start Row, Start Column
	int er=rows-1;  // End Row
	int ec=cols-1;  // End Column
	
	while (sr<=er && sc<=er)
	{
		// Print start row
		for (int i=sc; i<=ec; i++)
			cout<<a[sr][i]<<" ";
		sr++;
		
		if (sc<ec){ /////// IMP: when rows=even and cols=odd
		// Printing end column
		for (int i=sr; i<=er; i++)
			cout<<a[i][ec]<<" ";
		ec--;
	    }
		
		if (sr<er){  /////// IMP: when rows=odd and cols=even
		// Printing end row
		for (int i=ec; i>=sc; i--)
			cout<<a[er][i]<<" ";
		er--;
	    }
	    
		// Printing start column
		for (int i=er; i>=sr; i--)
			cout<<a[i][sc]<<" ";
		sc++;
	}
	
}


int main()
{
	int n,m;
	int a[200][200];
	cin>>m>>n;
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			cin>>a[i][j];
			
	SpiralPrint(a, m, n);
	
	return 0;
}
