#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>

using namespace std;

int main()
{
	string str;
	int minimum = 0;
	int input;

	getline(cin, str);
	input = atoi(str.c_str());

	minimum = str.size() * 9;

	for (int i = input - minimum; i < input ; ++i)
	{
		int temp = i;

		for (int j = i ; j != 0; )
		{
			temp += j % 10;

			j /= 10;
		}

		if (temp == input)
		{
			printf("%d", i);

			return 0;
		}
	}

	printf("0");


	return 0;
}