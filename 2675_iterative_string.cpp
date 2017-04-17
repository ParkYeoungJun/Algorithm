#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<sstream>

using namespace std;

int main()
{
	int line, num = 0;
	string st;
	stringstream stream;
	
	scanf("%d", &line);

	cin.ignore();
	
	for (int i = 0; i < line; ++i)
	{
		string temp;

		st = "";

		getline(cin, st , '\n');

		stream.clear();

		stream.str(st);

		stream >> temp;

		num = atoi(temp.c_str());

		temp = "";

		stream >> temp;

		for (int j = 0 ; j < temp.length(); ++j)
		{
			for (int k = 0; k < num; ++k)
				printf("%c", temp[j]);
		}

		temp = "";

		printf("\n");

	}

	return 0;
}
