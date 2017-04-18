#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<set>

using namespace std;

int main()
{
	int first = 100, size; //, to;
	string to = "";
	string made = "";
	std::set<int> container;
	std::set<int>::iterator iter;

	getline(cin, to);

	fflush(stdin);

	//scanf("%d", &to);

	scanf("%d", &size);

	for (int i = 1; i <= size; ++i)
	{
		int temp;

		scanf("%d", &temp);

		container.insert(temp);
	}

	for (int i = 0; i < to.length(); ++i)
	{
		int temp = to[i]-48;

		if ((iter = container.find(temp)) != container.end())
		{
			for (int j = 1; j <= 9; ++j)
			{
				if (container.find(temp + j) == container.end() && temp + j < 10)
				{
					cout << "temp : " << temp << " j : " << j << endl;

					made += (char)(j + 48);

					break;
				}
				else if (container.find(temp - j) == container.end() && temp - j > 0)
				{
					cout << "temp : " << temp << " j : " << j << endl;

					made += (char)(j + 48);

					break;
				}
			}
		}
	}

	cout << made;
	
	return 0;
}