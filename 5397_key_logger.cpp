#include<iostream>
#include<stdio.h>
#include<string>
#include<list>

using namespace std;

int main()
{
	int size;
	std::list<char> array;
	std::list<char>::iterator iter, temp;
	string str;

	array.push_back(0);

	iter = array.begin();

	scanf("%d", &size);

	cin.ignore();

	for (int i = 0; i < size; ++i)
	{
		getline(cin, str);

		//cout << "str : " << str << endl;

		for (int j = 0; j < str.size(); ++j)
		{

			//cout << "str.at(" << j << ") : " << str.at(j) << endl;

			if (str.at(j) == '<')
			{
				if (iter != array.begin())
					--iter;
			}
			else if (str.at(j) == '>')
			{
				if (*iter != 0)
					++iter;
			}
			else if (str.at(j) == '-')
			{
				if (array.size() > 1 && iter != array.begin())
				{
					temp = iter;
					array.erase(--iter);
					iter = temp;
				}
			}
			else
			{
				array.insert(iter, str.at(j));
			}

			/*
			for (list<char>::iterator k = array.begin(); k != array.end(); ++k)
			{
				if (k == iter)
				{
					if (*k == 0)
						cout << " (null) ";
					else
						cout << "(" << *k << ")" << " ";
				}
				else
				{
					if (*k == 0)
						cout << " null ";
					else
						cout << *k << " ";
				}
			}

			cout << endl;
			*/
		}

		array.pop_back();

		for (list<char>::iterator k = array.begin(); k != array.end(); ++k)
		{
			printf("%c", *k);
		}

		printf("\n");

		array.clear();

		array.push_back(0);

		iter = array.begin();

	}

	return 0;
}