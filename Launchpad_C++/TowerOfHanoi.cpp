#include<iostream>
using namespace std;

void toh(int n, char source, char helper, char destination)
{
	if (n==0)
		return;
		
	toh(n-1,  source, destination, helper);
	cout<<"Moving disk "<<n<<" from "<<source<<" to "<<destination<<endl;
	toh(n-1, helper, source, destination);
}


int main()
{
	int n;
	cin>>n;
	//int a[]={'A','B', 'C'};
	toh(n, 'A','B', 'C');
	return 0;
}
