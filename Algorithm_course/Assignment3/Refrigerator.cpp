/*
 * Refrigerator.cpp
 *
 *  Created on: 2015. 11. 02.
 *      Author: Park
 */

#include<iostream>
#include<algorithm>

using namespace std;

typedef struct
{
	int max;	// max
	int min;	// min
}temperature;

bool compare(const temperature &A, const temperature &B)
{
	return A.max < B.max;
}

int main(void)
{
	 std::ios::sync_with_stdio(false);

	 int size; // icecream size

	 cin >> size;

	 temperature* tem;
	 tem = new temperature[size];

	 for(int i = 0 ; i < size ; ++i)
	 {
		 cin >> tem[i].min;
		 cin >> tem[i].max;
	 }

	 int temp = 0;
	 int count = 0;

	sort(tem,tem+size,compare);

	 // Logic

	temp = tem[0].max;

	 for(int i = 0 ; i < size ; ++i)
	 {
		 if(temp < tem[i].min)
		 {
			 ++count;
			 temp = tem[i].max;
		 }
	 }

	 cout << ++count;
}
