//Find all sub sequences of a given string
//"abc"=" <null> ", "a", "b","c", "ab", "bc", "abc"

#include<iostream>
#include<cstring>
using namespace std;

void Subsequences(char *input, int i, char *output, int j) //Output at jth index, input taken from ith index
{
	
	//Base Case
	if (input[i]=='\0')
	{
		output[j]='\0';
		cout<<output<<endl;
		return;
	}
	
	//Pick the character
	output[j]=input[i];
	Subsequences(input, i+1, output, j+1);
	
	//Don't pick the character
	Subsequences(input, i+1, output, j);    //Output array has updated character at j index (array passed by reference)
	                                        //but j is not incremented, therefore array is overwritten in the next step
	
}

int main()
{
	char a[]="abc";
	char output[100];
	
	Subsequences(a,0,output,0);
	
	return 0;
}
