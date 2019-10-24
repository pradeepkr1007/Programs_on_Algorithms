//Ladder Problem

#include<iostream>
using namespace std;

int Ladder(int n){
	if (n==0){
		return 1;
	}
	
	if(n<0){
		return 0;
	}
	
	return Ladder(n-1)+Ladder(n-2)+Ladder(n-3);
}


int LadderDPTD(int n, int*dp){
	
	//cout<<n<<endl;
	if (n==0){
		dp[n]=1;
		return 1;
	}
	
	if(n<0){
		return 0;
	}
	
	if (dp[n]!=-1){
		return dp[n];
	}
	
	int ans=LadderDPTD(n-1,dp)+LadderDPTD(n-2,dp)+LadderDPTD(n-3,dp);
	dp[n]=ans;
	return ans;
}

int LadderDPBU(int n){
	int *dp=new int[n+1];
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	
	for (int i=3; i<=n ; i++){
		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	}
	
	int ans=dp[n];
	delete []dp;
	return ans;
}


//for k steps  O(nk)
int Steps(int n, int k){
	int *dp=new int[n+1];
	dp[0]=1;
	
	for(int step=1; step<=n; step++){
		dp[step]=0;
		for (int j=1; j<=k; j++){
			if (step-j>=0){
				dp[step] += dp[step-j];
			}
		}
	}
	
	return dp[n];
}

//for k steps  O(n), not O(nk)
int StepsFast(int n, int k){
	int *dp=new int[n+1];
	dp[0]=1;
	
	for(int step=1; step<=n; step++){
		dp[step]=0;
		for (int j=1; j<=k; j++){
			if (step-j>=0){
				dp[step]=2*dp[step-1]-dp[step-k-1];
			}
			else{
				dp[step]=2*dp[step-1];
			}
		}
	}
	
	return dp[n];
}


int main(){
	int dp[1000];
	int n;
	cin>>n;
	
	for (int i=0; i<=n; i++){
		dp[i]=-1;
	}
	
	cout<<LadderDPBU(n)<<endl;
	cout<<LadderDPTD(n,dp)<<endl;
	
	return 0;
}
