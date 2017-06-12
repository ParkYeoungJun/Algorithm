// Baeck Joon 1016 Á¦°ö ¤¤¤¤ ¼ö

#include<iostream>
#include<stdio.h>
#include<windows.h>
#include<vector>
#include<iterator>

using namespace std;

int main()
{
	long long int min, max;
	int count = 0;
	long long int i, j;
	bool flag = true;

	vector<long long int> vec;

	scanf_s("%lld %lld", &min, &max);



	for (i = 2; i*i < max; ++i)
	{
		vec.push_back(i*i);
	}

	cout << vec.size << endl;



	for (i = min ; i <= max ; ++i)
	{
		for (j = 0, vector<long long int>::iterator iter = vector.begin() ; vec.at(j) <= i && vec.capacity-1 > j; ++j)
		{
			printf("%lld \n", j);

			if (i % vec.at(j) == 0)
			{
				flag = false;

				break;
			}
		}

		if (flag)
		{
			count++;
		}
		else
			flag = true;
	}

	printf("%d", count);

	Sleep(1000);

	return 0;
}

