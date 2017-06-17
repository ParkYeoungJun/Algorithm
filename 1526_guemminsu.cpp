#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<sstream>

using namespace std;

int main()
{
	string str;
	int count, ha;

	getline(cin, str);

	while (true)
	{
		if (atoi(str.c_str()) == 4)
		{
			printf("4");

			return 0;
		}

		count = 0;

		for (int i = 0; i < str.size(); ++i)
		{
			if (str.at(i) == '4' || str.at(i) == '7')
				count++;
		}

		if (count == str.size())
		{
			cout << str;
		
			return 0;
		}

		int temp = atoi(str.c_str());

		std::stringstream out;

		out << --temp;

		str = out.str();
	}
}