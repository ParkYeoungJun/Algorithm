#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int exam_size;
	int* person;
	int whole, sub;
	long long int result = 0;

	scanf("%d", &exam_size);

	person = new int[exam_size + 2];

	for (int i = 1; i <= exam_size; ++i)
		scanf("%d", &person[i]);

	scanf("%d %d", &whole, &sub);

	result += exam_size;

	for (int i = 1; i <= exam_size; ++i)
	{
		person[i] -= whole;

		if(person[i] > 0)
			if (person[i] % sub == 0)
				result += person[i] / sub;
			else
				result += person[i] / sub + 1;
	}

	printf("%lld", result);

	return 0;
}