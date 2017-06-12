/*
 * Cliquet.cpp
 *
 *  Created on: 2015. 11. 22.
 *      Author: Park
 */

#include<iostream>
#include<string.h>

using namespace std;

int size;		// 입력 사이즈

int maxindex;		// 그  whe의 앞자리수
int maxi;			// 그 whe의 최대 count

int result;			// 지금 까지 나온 complete의 count

// 완전그래프 검사

bool complete(int** arr, int* whe)
{
	bool check = true;

	for(int i = size-1 ; i > 0 ; --i)
	{
			if(whe[i] != 0)
			{
				for(int k = 0 ; k < i ; ++k)
				{
					if(whe[k] != 0)
					{
						if(arr[i][k] != 1)
						{
							return false;
						}
					}
				}
			}
	}
	return true;
}

// 총 검사 function
void check(int** arr, int* whe, int* resultarr,int i, int count)
{

//	cout << "result : " << result << endl;

	if(maxi > result && complete(arr, whe))
	if(size == i)
	{
		if(whe[maxindex] == 0)
			++maxindex;

		maxi = size - maxindex;


		if(result < count)
		{
			result = count;

			int j = 0;

			memcpy(resultarr, whe, size*sizeof(int));
		}

//		cout << "maxi : " << maxi << endl;
//		cout << "count : " << count << endl;

//		for(int i = 0 ; i < size ; ++i)
//			cout << whe[i] << " ";
//		cout << endl;
	}
	else
	{
		whe[i] = i+1;
		check(arr, whe, resultarr, i+1, ++count);
		whe[i] = 0;
		check(arr, whe, resultarr, i+1, --count);
	}
}

int main(void)
{
	 std::ios::sync_with_stdio(false);

	 cin >> size;

	 int** arr;

	 arr = new int* [size];

	 for(int i = 0 ; i < size ; ++i)
	 {
		 for(int j = 1 ; j <= i+1 ; ++j)
			 arr[i] = new int[j];
	 }

	 for(int i = 0 ; i < size ; ++i)
	 {
		 for(int j = 0 ; j <= i ; ++j)
		 {
			 cin >> arr[i][j];
		 }
	 }

	 int* whe;
	 whe = new int[size];

	 int* resultarr;
	 resultarr = new int[size];

	 maxindex = 0;
	 result = -1;

	 check(arr, whe, resultarr, 0, 0);

	 cout << result << endl;

//	 for(int i = 0 ; i < result ; ++i)
//	 {
//		 cout << resultarr[i] << " ";
//	 }

	 for(int i = 0 ; i < size ; ++i)
	 {
		 if(resultarr[i] != 0)
			 cout << resultarr[i] << " ";
	 }
}
