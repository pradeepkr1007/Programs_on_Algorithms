#include<iostream>
using namespace std;

int main()
{
	int rows;
	int cols;
	cin>>rows>>cols;
	int **arr=new int*[rows];
	for (int i=0; i<rows; i++)
		arr[i]=new int[cols];
	
	int val=1;
	for (int i=0; i<rows; i++)
		for (int j=0; j<cols; j++)
		{
			arr[i][j]=val;
			val++;
		}
	
	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	
	cout<<endl<<"Deleting arrays of integers:"<<endl;		
	for (int i=0; i<rows; i++)
		delete [] arr[i];
		
	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	
	cout<<endl<<"Deleting arrays of pointers to arrays of integers:"<<endl;	
	delete []arr;
	
	for (int i=0; i<rows; i++){
		for (int j=0; j<cols; j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
