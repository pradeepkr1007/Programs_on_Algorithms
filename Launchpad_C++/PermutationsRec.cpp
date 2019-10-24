//Print all permutations of a string

#include<iostream>
using namespace std;

void Permutations(char *input, int i, int j)
{
	if (input[i]=='\0')
	{
		cout<<input<<endl;
		return;
	}
	
	for (int j=i; input[j]!='\0'; j++)
	{
			swap(input[i], input[j]);
			Permutations(input, i+1, j);
			//The above code does not give the desired result because arrays are passed by ref and changed at every step.
			swap(input[i], input[j]); //Backtracking
	}
}

int main()
{
	char a[]="abc";
	char output[100];
	
	Permutations(a,0,0);
	
	return 0;
}
