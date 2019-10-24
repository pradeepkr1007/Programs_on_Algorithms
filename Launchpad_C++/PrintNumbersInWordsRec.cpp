/* Given an integer say 2048, print
two zero four eight */

#include<iostream>
using namespace std;

string Words[11]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void PrintInWords(int n){
	//Base Case
	if (n==0)
		return;
	
	//Recursive Case
	PrintInWords(n/10);
	int last=n%10;
	cout<<Words[last]<<" ";
}

int main(){
	int n;
	cin>>n;
	PrintInWords(n);
	return 0;
}
