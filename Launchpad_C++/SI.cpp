#include<iostream>
using namespace std;
int main(){
	float p,r,t,si;
	cout<<"Enter principle, rate of interest, time:\n";
	cin>>p>>r>>t;
	si=p*r*t/100;
	cout<<"Simple interest = "<<si;
	return 0;
}
