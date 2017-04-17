#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
	string str;
	int num[30] = { 0, };
	int max = -1, result = -1;
	bool same = false;

	getline(cin, str);

	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] >= 97)
			str[i] -= 32;

		num[str[i] - 65]++;
	}

	for (int i = 0; i < 26; ++i)
	{
		if (max < num[i])
		{
			max = num[i];

			result = i;

			same = false;
		}
		else if (max == num[i])
			same = true;
	}

	if (max == -1 || same)
		printf("?");
	else
		printf("%c", result + 65);

	return 0;
}