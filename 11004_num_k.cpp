#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>

using namespace std;

int main()
{
	int n, k;
	vector<int> vec;

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i)
	{
		int temp;

		scanf("%d", &temp);

		vec.push_back(temp);
	}

	nth_element(vec.begin(), vec.begin() + k-1, vec.end());

	printf("%d", vec[k-1]);

	return 0;

}