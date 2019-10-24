/*

PRINT ARMSTRONG NUMBERS
Take the following as input.

A number (N1)
A number (N2)
Write a function which prints all armstrong numbers between N1 and N2 (inclusive).

371 is an Armstrong number as 371 = 3^3 + 7^3 + 1^3


Constraints:
0 < N1 < 100 
N1 < N2 < 10000
Sample Input:
400
1000
Sample Output:
407
Explanation:
Each number in output is in separate line.

*/

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n1,n2;
	cin>>n1>>n2;
	int i=n1;
	while (i<=n2)
	{
		/////////////////////
		int n;
		n=i;
		int sum=0;
	
		//counting digits
		int d=0;
		while (n>0)
		{
			d++;
			n/=10;	
		}
		
		n=i;
		while (n>0)
		{
			int r=n%10;
			sum+=pow(r,d);
			n/=10;
		}
		if (i==sum)
			cout<<i<<endl;
		i++;
		
	}	
		
	return 0;
}

