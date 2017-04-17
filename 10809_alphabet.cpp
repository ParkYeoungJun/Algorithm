#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
	int alpha[150];
	string str;
	 
	memset(alpha, -1, sizeof(int) * 150);

	getline(cin, str);

	for(int i = 0 ; i < str.length() ; ++i)
	{
		if(alpha[(int)str[i]] == -1)
			alpha[(int) str[i]] = i;
	}

	for(int i = 97 ; i <= 122 ; ++i)
		printf("%d ", alpha[i]);


	return 0;
}

