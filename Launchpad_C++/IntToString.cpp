//Int to string

#include<iostream>
using namespace std;


int CountDigits(int a){
	int d=0;
	cout<<a<<endl;
	while (a>0){
		a/=10;
		d++;
	}
	
	return d;
}



string IntToString(int a){
	int d=CountDigits(a);
	cout<<a<<" "<<d<<endl;
	string ans;
	for (int i=d-1; i>=0; i--){
		ans[i]=char(a%10+'0');
		a/=10;
	}
	cout<<ans<<endl;
	return ans;
}

int main(){
	int c=123;
	int d=1340;
	cout<<IntToString(c)<<endl;//<<IntToString(d);
	return 0;
}
