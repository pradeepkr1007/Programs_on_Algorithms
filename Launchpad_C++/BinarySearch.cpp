//Binary Search

#include<iostream>
using namespace std;

int binarysearch(int a[], int key, int s, int e)
{
	int mid=(s+e)/2;
	
	if (key==a[mid])
		return mid;

	while (s<e)
	{
		if (key<a[mid])
			return binarysearch(a, key, s, mid-1);
	
		else if (key>a[mid])
			return binarysearch(a, key, mid+1, e);
	}
	
	return -1;
	
}

int main()
{
	int n;
	cin>>n;
	int a[200];
	for (int i=0; i<n; i++)
		cin>>a[i];
	int key;
	cin>>key;
	
	cout<<endl<<"Found at: "<<binarysearch(a, key, 0, n-1);
	
	return 0;
}


