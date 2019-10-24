//Wine and maximum price

#include<iostream>
#include<climits>
using namespace std;

int Wine(int w[], int i, int j, int day){
	
	if (i>j){
		return 0;
	}
	
	int op1=w[i]*day+Wine(w,i+1,j,day+1);
	int op2=w[j]*day+Wine(w,i,j-1,day+1);
	
	return max(op1, op2);
}

int WineDPTD(int w[], int i, int j, int day, int dp[][100]){
	
	if (i>j){
		dp[i][j]=0;
		return 0;
	}
	
	if(dp[i][j]!=0){
		return dp[i][j];
	}
	
	int op1=w[i]*day+WineDPTD(w,i+1,j,day+1,dp);
	int op2=w[j]*day+WineDPTD(w,i,j-1,day+1,dp);
	
	return dp[i][j]=max(op1, op2);
}

int WineDPBU(int w[], int n){
	
	int dp[100][100]={0};
	
	int day=n+1;
	
	//Filling diagonal (For one bottle remaining)
	for (int i=0; i<=n; i++){
		dp[i][i]=w[i]*day;
	}
	
	day--;
	
	//Filling diagonal wise (length wise- number of bottles remaning)
	for (int k=2; k<=n+1; k++){
			
		//int start=0;
		int end=n-k+1;
		
		for (int i=0; i<=end; i++){
			int j=i+k-1;
			int op1=w[i]*day+dp[i+1][j];
			int op2=w[j]*day+dp[i][j-1];
			dp[i][j]=max(op1, op2);
		}
		day--;
	}
	
	for (int i=0; i<=n; i++){
		for (int j=0; j<=n; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return dp[0][n];
}

int main(){
	
	int dp[100][100]={0};
	
	int w[]={2,3,5,1,4};
	cout<<Wine(w,0,5-1,1)<<endl;
	cout<<WineDPTD(w,0,5-1,1,dp)<<endl;
	cout<<WineDPBU(w, 4);
}
