/*
IS PALINDROME?
Take as input N, a number. Take N more inputs and store that in an array. Write a recursive function which tests if the array is a palindrome and returns a Boolean value. Print the value returned.


Input Format:
Enter a number N , add N more numbers

Constraints:
None
Output Format:
Display the Boolean result

Sample Input:
4
1
2
2
1
Sample Output:
true
*/

#include<iostream>
using namespace std;

int ispalindrome(char a[1000], int s, int e)
{
	if (s==e) //Only 1 character
		return 1;
	
	if (a[s]!=a[e]) //Last and first character not same
		return 0;
	
	if (s<e+1) //more than 2 characters remain
		return ispalindrome(a,s+1,e-1);
		
	return 1;
}

int length(char a[])
{
	int i=0;
	int len=0;
	for (i; a[i]!='\0';i++)
	{
		len++;
	}
	return len;
}
		

int main()
{
	char a[1000];
	cin.getline(a,100);
	int ans=ispalindrome(a, 0, length(a)-1);
	if (ans==1)
		cout<<"true";
	else
		cout<<"false";
		
	return 0;
}

/*

bool palindrome(char b[])
{
	int len=length(b);
	int i=0;
	int j=len-1;
	while (i<j)
	{
		if (b[i]!b[j]
			return false;
		
		i++;
		j--;
	}
	return true;
}

*/
