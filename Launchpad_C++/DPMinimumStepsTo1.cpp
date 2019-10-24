//MinimumStepsTo1

#include<iostream>
#include<climits>
using namespace std;


//Recursion
int MinWays(int n){
	if (n==1)
		return 0;
		
	//3 Options
	int a=INT_MAX, b=INT_MAX, c=INT_MAX;
	
	//Option 1: Divide by 3.
	if (n%3==0){
		a=1+MinWays(n/3);
	}
	
	//Option 2: Divide by 2.
	if (n%2==0){                 //if, not else if. We are trying all cases
		b=1+MinWays(n/2);
	}
	
	//Option 3: Subtract 1.
	c=1+MinWays(n-1);
	
	return min(a,min(b,c));
}


//Top Down DP Approach
int MinWaysDPTD(int n, int*dp){
	if (n==1){
		dp[n]=0;
		return 0;
	}
		
	//Using memoized result
	if (dp[n]!=-1){
		return dp[n];
	}	
		
	//3 Options
	int a=INT_MAX, b=INT_MAX, c=INT_MAX;
	
	//Option 1: Divide by 3.
	if (n%3==0){
		a=1+MinWaysDPTD(n/3, dp);
	}
	
	//Option 2: Divide by 2.
	if (n%2==0){                 //if, not else if. We are trying all cases
		b=1+MinWaysDPTD(n/2, dp);
	}
	
	//Option 3: Subtract 1.
	c=1+MinWaysDPTD(n-1, dp);
	
	dp[n]=min(a,min(b,c));
	return dp[n];
}

//Bottom Up DP Approach
//int MinWaysDPBU(int n){



int main(){
	int dp[10000]; //Do not declare globally. Can have multiple DP functions
	int n;
	cin>>n;
	
	for (int i=0; i<=n; i++){
		dp[i]=-1;
	}
	
	cout<<MinWays(n)<<endl;
	cout<<MinWaysDPTD(n,dp)<<endl;
	
	
	return 0;
}
