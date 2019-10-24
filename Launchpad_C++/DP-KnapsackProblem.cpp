// 0/1 Knapsack Problem- DP

#include<iostream>
#include<climits>
using namespace std;


//Not required if we are using DP. We make classes in Greedy so that we can sort entire objects on the basis of one data item only.

/*
class item{
	public:
		int w;               //Weight
		int p;               //Price
		
		item(int weight=0, int price=0){
			w=weight;
			p=price;
		}
		
};*/

int Knapsack(int prices[], int wts[], int N, int W){
	
	if (N==0 || W==0){
		return 0;
	}
	
	int inc=0, exc=0;
	if (wts[N-1]<=W){
		inc=prices[N-1]+Knapsack(prices, wts, N-1, W-wts[N-1]);   //if an item can be picked multiple times, (prices, wts, N, W-wts[N-1])
	}
	
	exc=Knapsack(prices, wts, N-1, W);
	return max(inc, exc);
}


int KnapsackDPTD(int prices[], int wts[], int N, int W, int dp[][100]){
	
	if (N==0 || W==0){
		dp[N][W]=0;
		return 0;
	}
	
	if (dp[N][W]!=0){
		return dp[N][W];
	}
	
	int inc=0, exc=0;
	if (wts[N-1]<=W){
		inc=prices[N-1]+KnapsackDPTD(prices, wts, N-1, W-wts[N-1], dp);   //if an item can be picked multiple times, (prices, wts, N, W-wts[N-1])
	}
	
	exc=Knapsack(prices, wts, N-1, W);
	dp[N][W]=max(inc, exc);
	
	return dp[N][W];
}


int KnapsackDPBU(int prices[], int wts[], int N, int W){
	int dp[100][100]={0};
	
	for (int n=0; n<=N; n++){
		for (int w=0; w<=W; w++){
			if (n==0||w==0){
				dp[n][w]=0;
			}
			
			else{
				int inc=0, exc=0;
				if (wts[n-1]<=w){
					inc=prices[n-1]+dp[n-1][w-wts[n-1]];
				}
				exc=dp[n-1][w];
				dp[n][w]=max(inc, exc);
			}
		}
	}
	return dp[N][W];
}



int main(){
	
	//item a[1000];
	
	
	int wts[]={4,7,3,2};
	int prices[]={10,20,20,5};
	int N=4;
	int W=11;
	
	int dp[100][100]={0};
	
	/*
	for (int i=0; i<=N; i++){
		for (int j=0; j<=N; j++){
			dp[i][j]=0;
		}
	}*/
	
	cout<<Knapsack(prices, wts, N, W)<<endl;
	cout<<KnapsackDPTD(prices, wts, N, W, dp)<<endl;
	cout<<KnapsackDPBU(prices, wts, N, W)<<endl;
	
	return 0;
}
