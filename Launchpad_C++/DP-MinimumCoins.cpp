//Minimum Number of coins for a denomination

#include<iostream>
#include<climits>
using namespace std;

//Recursion
int MinCoins(int coins[], int n, int amt){
	if (amt==0)
		return 0;

	int ans=INT_MAX;
	
	for (int i=0; i<n; i++){
		if (amt-coins[i]>=0){
			int smallerans=MinCoins(coins, n, amt-coins[i]);
			if (smallerans!=INT_MAX){
				ans=min(ans, 1+smallerans);
			}	
		}
	}
	return ans;
}


//DP- Top Down
int MinCoinsDPTD(int coins[], int n, int amt, int dp[]){
	
	if (amt==0){
		dp[amt]=0;
		return 0;
	}
	
	if (dp[amt]!=-1){
		return dp[amt];
	}
		
	int ans=INT_MAX;
	
	for (int i=0; i<n; i++){
		if (amt-coins[i]>=0){
			int smallerans=MinCoinsDPTD(coins, n, amt-coins[i], dp);
			if (smallerans!=INT_MAX){
				ans=min(ans, 1+smallerans);
			}	
		}
	}
	dp[amt]=ans;
	return ans;
}


//DP- Bottom Up
int MinCoinsDPBU(int coins[], int n, int amt){
	
	int *dp=new int[amt+1];
	for (int i=0; i<=amt; i++){
		dp[i]=INT_MAX;
	}
	
	dp[0]=0;
	
	for (int rupee=1; rupee<=amt; rupee++){
		for (int i=0; i<n; i++){
			if (rupee-coins[i]>=0){
				int smallerans=dp[rupee-coins[i]];
				//if (smallerans!=INT_MAX)                   //Building top from bottom. Bottom will already have answer
				dp[rupee]=min(dp[rupee], 1+smallerans);
				//}		
			}
		}	
	}
	
	int ans=dp[amt];
	delete []dp;
	return ans;
}


int main(){
	
	int coins[]={1,7,10};
	int n=3;
	int amt;
	cin>>amt;
	int dp[10000]; //Do not declare globally. Can have multiple DP functions
	
	for (int i=0; i<=amt; i++){
		dp[i]=-1;
	}
	

	cout<<MinCoins(coins, n, amt)<<endl;
	cout<<MinCoinsDPTD(coins, n, amt, dp)<<endl;
	cout<<MinCoinsDPBU(coins, n, amt)<<endl;
	
	return 0;
}
