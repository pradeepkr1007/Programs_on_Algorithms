//Phone Keypad

#include<iostream>
#include<string>
using namespace std;

string keys[]={" "," ","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
	
void PhoneKeyPad(char input[], int i, char output[], int j)
{
	//Base Case
	if (input[i]=='\0')
	{
		output[j]='\0';
		cout<<output<<endl;
		return;
	}
	
	//Recursive Case
	int digit=input[i]-'0';   //ASCII to int
	for (int k=0; keys[digit][k]!=0; k++)  //eg. for digit 2, k=A,B,C
	{
		output[j]=keys[digit][k];
		PhoneKeyPad(input, i+1, output, j+1);
	}

}

int main()
{
	//int n;
	//cin>>n;

	char input[100]="23\0";
	/*for (int i=0; i<n; i++)
	{
		cin>>input[i];
	}
	input[n]='\0';	*/
	char output[100];

	PhoneKeyPad(input,0,output,0); //input, i, output, j
}
