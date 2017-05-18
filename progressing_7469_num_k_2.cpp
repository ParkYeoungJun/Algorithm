/*
 *   segment tree
 */

#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, m;
	vector<int> vec, vec_temp;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; ++i)
	{
		int temp;

		scanf("%d", &temp);

		vec.push_back(temp);
	}

	for (int i = 0; i < m; ++i)
	{
		int a, b, c;

		scanf("%d %d %d", &a, &b, &c);

		vec_temp.assign(vec.begin() + a - 1, vec.begin() + b);

		nth_element(vec_temp.begin(), vec_temp.begin() + c - 1,  vec_temp.end());

		printf("%d\n", vec_temp[c - 1]);

		vec_temp.clear();
	}

	return 0;
}