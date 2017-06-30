#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	int sub_1 = b-a, sub_2 = c-b;

	printf("%d", max(sub_1, sub_2) - 1);

	return 0;
}