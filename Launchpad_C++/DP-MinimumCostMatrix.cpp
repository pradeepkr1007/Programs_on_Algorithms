//Minimum Cost Grid

#include<iostream>
#include<climits>
using namespace std;

int MinCost(int cost[][10], int i, int j){
	
	if (i==0 && j==0){
		return cost[0][0];
	}
	
	if (i<0 || j<0){
		return INT_MAX;
	}
	
	if (MinCost(cost,i-1,j)==INT_MAX){
		if ( MinCost(cost, i, j-1)==INT_MAX){
			return INT_MAX;
		}
		
		else 
		{
			return MinCost(cost, i, j-1) + cost[i][j];
		}
	}
	else if ( MinCost(cost, i, j-1)==INT_MAX){
		return MinCost(cost, i-1, j) + cost[i][j];
	}
	
	else
		return min( ( MinCost(cost,i-1,j) + cost[i][j] ) , ( MinCost(cost,i,j-1) + cost[i][j] ) );
}


int MinCost2DPTD(int cost[][10], int i, int j, int dp[][100]){
	if (dp[i][j]!=0){
		return dp[i][j];
	}
	
	if (i==0 && j==0){
		dp[i][j]=cost[0][0];
		return cost[0][0];
	}
	
	else if (i==0 && j>0){
		dp[i][j]=MinCost2DPTD(cost, i, j-1, dp) + cost[i][j];
		return dp[i][j];
	}
	
	else if (i>0 && j==0){
		dp[i][j]=MinCost2DPTD(cost, i-1, j, dp) + cost[i][j];
		return dp[i][j];
	}
	
	int op1=MinCost2DPTD(cost, i, j-1, dp) + cost[i][j];
	int op2=MinCost2DPTD(cost, i-1, j, dp) + cost[i][j];
	
	dp[i][j]=min(op1,op2);
	return min(op1,op2);
}

int MinCost2(int cost[][10], int i, int j){

	if (i==0 && j==0){
		return cost[0][0];
	}
	
	else if (i==0 && j>0){
		return MinCost2(cost, i, j-1) + cost[i][j];
	}
	
	else if (i>0 && j==0){
		return MinCost2(cost, i-1, j) + cost[i][j];
	}
	
	int op1=MinCost2(cost, i, j-1) + cost[i][j];
	int op2=MinCost2(cost, i-1, j) + cost[i][j];
	
	return min(op1,op2);
}


int MinCostBU(int cost[][10], int m, int n){
	
	int dp[10][10]={0};
	
	//dp[0][0]=cost[i][j];
	
	for (int i=0; i<=m; i++){
		for (int j=0; j<=n; j++){
			
			if (i==0 && j==0){
				dp[0][0]=cost[i][j];
			}
			else if (i==0 && j>0){
				dp[i][j]=cost[i][j] + dp[i][j-1];
			}
			else if (i>0 && j==0){
				dp[i][j]=cost[i][j] + dp[i-1][j];
			}
			else{
				dp[i][j]=min(dp[i-1][j],dp[i][j-1]) + cost[i][j];
			}
		}
	}
	
	return dp[m][n];
	
}

int main(){
	int cost[][10]={
	{1,2,3,1},
	{2,5,1,3},
	{1,2,2,2},
	{1,1,1,1}};
	
	cout<<MinCost(cost,2,2)<<endl;
	cout<<MinCost2(cost,2,2)<<endl;
	
	int dp[100][100]={0};
	
	//for (int i=0; i<=4; i++){
	//	dp[i][i]=-1;
	//}
	
	cout<<MinCost2DPTD(cost, 2, 2, dp)<<endl;
	
	cout<<MinCostBU(cost,3,3)<<endl;
	
	return 0;
}
