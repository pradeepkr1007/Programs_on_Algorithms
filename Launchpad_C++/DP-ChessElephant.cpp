//Chess Elephant: Source to Destintion, right or down, any number of steps

#include<iostream>
using namespace std;


int StepsDPBU(int m, int n){
	
	int dp[10][10]={0};
	
	for (int i=0; i<=m; i++){
		
		for (int j=0; j<=n; j++){
			
			if (i==0 && j==0){
				dp[0][0]=1;
			}
			
			else if(i==0 && j>0){
				dp[i][j]=0;
				for (int k=0; k<j; k++){                    // int val=1; for (int j=1; j<=n; j++){ dp[0][j]=val; val*=2;}
					dp[i][j]+=dp[i][k];
				}
			}
			
			else if(i>0 && j==0){
				dp[i][j]=0;                                  // int val=1; for (int i=1; i<=m; i++){ dp[i][0]=val; val*=2;}
				for (int k=0; k<i; k++){
					dp[i][j]+=dp[k][j];
				}
			}
			
			else{
				dp[i][j]=0;
				for (int k=0; k<i; k++){
					dp[i][j]+=dp[k][j];
				}
				for (int l=0; l<j; l++){
					dp[i][j]+=dp[i][l];
				}		
			}
			
		}
	}
	
	for (int i=0; i<=m; i++){
		for (int j=0; j<=n; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return dp[m][n];
}



int main(){
	
	cout<<StepsDPBU(3,3);
	
	return 0;
}
