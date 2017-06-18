#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int main()
{
	int n, maxi;
	std::vector<int> arr;
	std::vector<int> temp;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		int temp;

		scanf("%d", &temp);

		arr.push_back(temp);
	}

	int* dp = new int[n + 2];

	temp.push_back(arr[0]);
	maxi = temp[0];

	for (int i = 1; i < arr.size(); ++i)
	{
		temp.push_back(max(arr[i], arr[i] + temp[i - 1]));
		maxi = max(maxi, temp[i]);
	}

	printf("%d", maxi);

	return 0;
}