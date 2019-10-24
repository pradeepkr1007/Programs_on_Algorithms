 #include<iostream>
 using namespace std;
 
 int main()
 {
	int n,m;
	int a[200][200];
	cin>>m>>n;
	for (int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			cin>>a[i][j];
 	
 	int j=0, i=0;
 	int cnt=m*n-1;
	while (cnt>=0)
	{
		cout<<a[i][j]<<" ";
		if ((j%2==0) && (i==m-1))
		{
			i=n-1;
			j++;
		}
		else if ((i==0) && (j%2!=0))
		{
			i=0;
			j++;
	    }
		else if (j%2==0)
			i++;
		else
			i--;
		cnt--;
	}
	
	return 0;
 }
