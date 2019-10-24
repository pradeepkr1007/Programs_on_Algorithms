//Fibonacci

#include<iostream>
using namespace std;

//Recursive approach O(2^n)
int fibo(int n){
	if (n==0 || n==1)
		return n;
		
	return fibo(n-1)+fibo(n-2);
}


//Top Down DP Approach -not working. Check.
int fiboDPTD(int n, int dp[]){
	if (n==0 || n==1){
		dp[n]=n;
		return n;
	}
		
	//Check if memoized
	if (dp[n]!=-1){
		return dp[n];
	}
	//cout<<n<<endl;
	int ans= fiboDPTD(n-1, dp) + fiboDPTD(n-2, dp);
	dp[n]=ans;
	return ans;
}

//Bottom Up DP Approach
int fiboDPBU (int n){
	int *dp=new int[n+1];
	
	dp[0]=0;
	dp[1]=1;
	
	for (int i=2; i<=n; i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	
	int ans=dp[n];
	delete []dp;
	return ans;
}

int main(){
	int dp[10000]; //Do not declare globally. Can have multiple DP functions
	int n;
	cin>>n;
	
	for (int i=0; i<=n; i++){
		dp[i]=-1;
	}
	
	cout<<fibo(10)<<endl;
	cout<<fiboDPBU(n)<<endl;
	cout<<fiboDPTD(n,dp)<<endl;
	
	return 0;
}
