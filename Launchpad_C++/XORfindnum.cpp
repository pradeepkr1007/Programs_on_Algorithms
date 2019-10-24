 /*
 Given some numbers, find the number that occurs only once. */
 
 #include<iostream>
 using namespace std;
 
 int main()
 {
 	int n;
 	cin>>n;
 	int i=1;
 	int ans=0;
 	for (i;i<=n;i++)
 	{
 		int num;
 		cin>>num;
 		ans=ans^num;	
	 }
	 cout<<ans;
 	return 0;
 }
