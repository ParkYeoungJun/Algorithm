#include<iostream>
#include<stdio.h>
#include<list>

using namespace std;

int main()
{
	int n, temp;
	std::list<int> arr;

	scanf("%d", &n);

	for(int i = 1 ; i <= n ; ++i)
	{
		arr.push_back(i);
	}

	for (; arr.size() != 1 ;)
	{
		printf("%d ", arr.front());
		arr.pop_front();

		temp = arr.front();
		arr.pop_front();

		arr.push_back(temp);
	}

	printf("%d", arr.front());

	return 0;
}
