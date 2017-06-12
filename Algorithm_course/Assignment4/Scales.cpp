/*
 * Scales.cpp
 *
 *  Created on: 2015. 11. 17.
 *      Author: Park
 */

#include<iostream>

using namespace std;

int outcome = 0;
int re = 0;

void bt(int* weight, int size ,int i,int to, int remain)
{
	int k;

	if(to > re || to+remain < re)
		return;
	else
	{
		if(i == size){
			if(to == re)
				++outcome;
		}
		else{
			bt(weight,size,i+1, to+weight[i+1], remain-weight[i+1]);
			bt(weight,size,i+1, to, remain-weight[i+1]);
		}
	}
}

int main(void)
{
	 std::ios::sync_with_stdio(false);

	 int size;

	 cin >> size;

	 int* weight;
	 weight = new int[size+1];

	 for(int i = 1 ; i <= size ; ++i)
	 {
		 cin >> weight[i];
		 re += weight[i];
	 }

	 if(re % 2 == 1)
		 cout << "impossible";
	 else
	 {
		 re /= 2;
		 bt(weight, size, 0, 0, re*2);
		 cout << outcome;
	 }
}
