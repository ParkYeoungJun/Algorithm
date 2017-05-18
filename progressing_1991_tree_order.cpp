#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

typedef struct node
{
	node* left;
	node* right;

	char var;

	node(char c)
	{
		var = c;
	}

	node()
	{
	}

}node;

int main()
{
	int size;
	node array[30];

	scanf("%d", &size);

	for (int i = 0; i < size; ++i)
	{
		int temp, left, right;

		scanf("%c %c %c", &temp, &left, &right);

		array[temp - 'A'] = temp;

		if (left != '.')
		{
			array[temp - 'A'].left = new node(left);
		}

		
	}
}