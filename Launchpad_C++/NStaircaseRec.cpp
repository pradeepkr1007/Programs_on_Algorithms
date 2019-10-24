//N-staircase: In how many ways can a child reach the top of an n-step staircase if he can jump 1,2 and 3 steps.
//eg let n=4
//Possible solutions: (1,1,1,1) (1,1,2) (1,3) (2,1,1) (2,2) (3,1)

#include<iostream>
using namespace std;

/*int fibo(int n)
{
	if ((n==0) || (n==1))
		return n;
		
	return (fibo(n-1)+(n-2));
}


int staircase(int n)
{
	
	return fibo(n+1);
}*/


int cntways(int n)
{
if (n==0)
	return 1;

if (n<0)
	return 0;
	
return (cntways(n-1)+cntways(n-2)+cntways(n-3));  //If jumps=k, iteration for n-k.
}

int main()
{
	int n;
	cin>>n;
	cout<<cntways(n);
	return 0;
}



