#include<iostream>
#include<stdio.h>
#include<vector>
#include<math.h>

using namespace std;

int main()
{
	int n, m, mini;
	std::vector<int> vec;

	scanf("%d", &n);
	scanf("%d", &m);

	mini = sqrt(n);

	for (int i = mini; i*i <= m ; ++i)
	{
		if (i*i >= n && i*i <= m)
		{
			vec.push_back(i*i);
		}
	}

	int sum = 0;

	if (vec.size() != 0)
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			sum += vec.at(i);
		}

		printf("%d\n", sum);
		printf("%d", vec.at(0));
	}
	else
		printf("%d", -1);

	return 0;
}