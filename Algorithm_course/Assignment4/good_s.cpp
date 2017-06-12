/*
 * Good_s.cpp
 *
 *  Created on: 2015. 11. 18.
 *      Author: Park
 */

#include<iostream>
#include<string>

using namespace std;

bool pro;
int size;

void DFS(string str,int n)
{
	if(pro)
		return;
	str += n+'0';

	int length = str.length();
	int width = length/2;

	for(int i = 2; i <= width ; ++i)
	{
		string a = str.substr(length-i, i);
		string b = str.substr(length-i*2, i);

		if(a.compare(b) == 0)
		{
			str.substr(length-1) = "";
			return;
		}
	}

	if(length == size){
		cout << str;
		pro = true;
		return;
	}

	if(n == 1)
	{
		DFS(str, 2);
		DFS(str, 3);

		str.substr(length-1) = "";
	}else if(n == 2)
	{
		DFS(str, 1);
		DFS(str, 3);

		str.substr(length-1) = "";
	}else if(n == 3)
	{
		DFS(str, 1);
		DFS(str, 2);

		str.substr(length-1) = "";
	}

}

int main(void)
{
	 std::ios::sync_with_stdio(false);

	 cin >> size;

	 DFS("", 1);
}


