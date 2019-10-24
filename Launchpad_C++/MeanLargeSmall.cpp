//Find mean, largest and smallestv of n numbers.

#include<iostream>
#include<climits> //for minimum and maximum values
using namespace std;

int main()

{
	cout<<"Enter number of numbers:";
	int n;
	cin>>n;
	int i=1, l=INT_MIN, s=INT_MAX, sum=0, num;
	float mean=0;
	while (i<=n)
	{
		cout<<"Enter number:";
		cin>>num;
		sum+=num;
		if (num>l)
			l=num;
		if (num<s)
			s=num;
		i++;
	}
	mean=sum/n;
	cout<<"\nMean="<<mean;
	cout<<"\nLargest="<<l;
	cout<<"\nSmallest="<<s;
	return 0;
}
