#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(pair<int, int> &pair1, pair<int, int> &pair2)
{
	return pair1.first > pair2.first;
}

int main()
{
	int size;
	std::vector<pair<int, int> > vec;

	scanf("%d", &size);

	for (int i = 0; i < size; ++i)
	{
		int temp1, temp2;

		scanf("%d %d", &temp1, &temp2);

		vec.push_back(make_pair(temp1, temp2));
	}

	for (int i = 0; i < vec.size(); ++i)
	{
		int rank = 1;

		for (int j = 0; j < vec.size(); ++j)
		{
			if (vec.at(i).first < vec.at(j).first && vec.at(i).second < vec.at(j).second)
				rank++;
		}

		printf("%d ", rank);
	}

	return 0;


}