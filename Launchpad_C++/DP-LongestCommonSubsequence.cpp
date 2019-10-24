//Longest Common Subsequence

#include<iostream>
using namespace std;

int LCS(string a, string b){
	int dp[100][100]={0};

	int m=a.length();
	int n=b.length();
	
	for (int i=0; i<=m; i++){
		for (int j=0; j<=n; j++){
			
			//Can be removed as the entire matrix is initialised by 0 already.
			if (i==0 || j==0){
				dp[i][j]=0;
			}
			
			else if (a[i-1]==b[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	
	///////USE STRING
	int index=dp[m][n];
	//string *ans=new string;
	char *ans=new char[index];
	ans[index]='\0';
	index--;
	
	int i=m;   //For first string
	int j=n;   //For second string
	
	while (i>0 && j>0){
		if (a[i-1]==b[j]-1){
			ans[index]=a[i-1];
			index--;
			i--;
			j--;
		}
		
		else if (dp[i-1][j]>dp[i][j-1]){
			i--;
		}
		
		else{
			j--;
		}
		
	}
	
	for (int i=0; i<=m; i++){
		for (int j=0; j<=n; j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<ans<<endl;
	return dp[m][n];
}


int main(){
	string a="prorgmnig";
	string b="programming";
	
	cout<<LCS(a,b)<<endl;
	return 0;
}
