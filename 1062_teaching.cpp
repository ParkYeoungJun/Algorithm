/*
 *	a n t i c
 */

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<set>
#include<vector>

using namespace std;

std::vector<string> vec;	//	남은 단어
std::vector<char> candi;	// 남은 알파벳
int visit[30];

int n, m, count, result;

void track(int from, int num)
{
	if (num == m)
	{	
		/*
		for (int i = 0; i < candi.size(); ++i)
			cout << visit[i];

		cout << endl;
		*/

		string str;
		int temp_count = count;

		for (int i = 0; i < candi.size(); ++i)
		{
			if (visit[i])
				str += candi[i];
		}

		bool flag = true;

		for (int i = 0 ; i < vec.size(); ++i)
		{
			flag = true;

			for (int j = 0; j < vec[i].size(); ++j)
			{
				if (str.find(vec[i].at(j)) == std::string::npos)
				{
					flag = false;
					break;
				}
			}

			if (flag)
				temp_count++;
		}

		result = max(result, temp_count);
		
		return;
	}

	for (int i = from; i < candi.size(); ++i)
	{
		if (!visit[i])
		{
			visit[i] = 1;
			track(i, num + 1);
			visit[i] = 0;
		}
	}
}

int main()
{
	string str;
	std::set<char> array;	// 남는 알파벳
	
	scanf("%d %d", &n, &m);

	if (m < 5)
	{
		printf("%d", 0);
	}
	else
	{
		m -= 5;

		cin.ignore();

		for (int i = 0; i < n; ++i)
		{
			getline(cin, str);

		//	cout << "str : " << str << endl;

			string temp = "";

			for (int j = 0; j < str.size(); ++j)
			{
				if (str.at(j) != 'a' && str.at(j) != 'n' &&
					str.at(j) != 't' && str.at(j) != 'i' && str.at(j) != 'c')
				{
					temp += str.at(j);

					array.insert(str.at(j));
				}
			}

			vec.push_back(temp);
		}

		for (set<char>::iterator iter = array.begin(); iter != array.end(); ++iter)
			candi.push_back((*iter));

		/*
		for (int i = 0; i < vec.size(); ++i)
		{
			if (vec.at(i).size() == 0)
			{
				count++;
			}
		}
		*/

		if (m > array.size())
		{
			printf("%d", n);

			return 0;
		}
		else
			track(0, 0);

		printf("%d", result);

	}

	return 0;
}