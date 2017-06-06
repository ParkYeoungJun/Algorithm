#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int home[202][202];
int home_num[202];

int main()
{
	int n, m, num, temp;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &num);

		for (int j = 1; j <= num; ++j)
		{
			scanf("%d", &temp);

			home[i][j] = temp;

			home_num[temp]++;
		}
	}

	return 0;
}