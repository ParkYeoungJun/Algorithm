#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

std::vector<int> container;
std::vector<int>::iterator iter;

int main()
{
	for (int i = 0; i < 9; ++i)
	{
		int temp;

		scanf("%d", &temp);

		container.push_back(temp);
	}




	return 0;
}