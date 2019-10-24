//Girl Boy- Calories Burnt

#include<iostream>
using namespace std;

//int CalBurnt()

int MinCalBurnt(int cal[][10], int m, int n){
	
	int b_s[10][10]={0};
	int b_e[10][10]={0};
	int g_s[10][10]={0};
	int g_e[10][10]-{0};
	
	//Boy Start Grid
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if (i==0 && j==0){
				b_s[0][0]=cal[0][0];
			}
			
			else if (i==0 && j>0){
				b_s[0][j]=b_s[0][j-1] + cal[i][j];
			}
			
			else if (i>0 && j==0){
				b_s[i][0]=b_s[i-1][0] + cal[i][j];
			}
			
			else{
				b_s[i][j]=max(b_s[i-1][0] + b_s[0][j-1]) + cal[i][j];
			}
		}
		
	/////////////////////	
	
	//Girl Start Grid
	for (int i=m-1; i>=0; i--){
		for (int j=0; j<n; j++){
			if (i==(m-1) && j==0){
				g_s[i][j]=cal[i]j];
			}
			
			else if (i==(m-1) && j>0){
				g_s[0][j]=g_s[0][j-1] + cal[i][j];
			}
			
			else if (i>0 && j==0){
				g_s[i][0]=g_s[i-1][0] + cal[i][j];
			}
			
			else{
				g_s[i][j]=max(g_s[i-1][0] + g_s[0][j-1]) + cal[i][j];
			}
		}	
		
	}
}



int main(){
	
	
	
	return 0;
}
