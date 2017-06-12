/*
 * Jop.cpp
 *
 *  Created on: 2015. 11. 18.
 *      Author: Park
 */

#include<iostream>

using namespace std;

int size;

typedef struct
{
	int level[2];
	int profit;
	int bound;
}queue;

typedef struct
{
	bool checked;
	int bound;
	int key;
}array;

/*
void up_queue(queue* q)
{
	int s = size;
	while(s > 1)
	{
		if(q[s/2].key > q[s].key)	// 2
		{
			swap(q[s/2], q[s]);		// 2
			s /= 2;					// 2
		}
		else
			break;
	}
}

void down_queue(queue* q)
{
	int s = 1, left, right, smaller;

	while(true)
	{
		left = s*2;					// 2
		right = s*2+1;				// 2

		if(right <= size)
		{
			smaller = (q[left].key < q[right].key)? left:right;

			if(q[s].key > q[smaller].key)
			{
				swap(q[s], q[smaller]);
				s = smaller;
			}
			else
				break;
		}
		else if(left == size)
			{
				if(q[s].key > q[left].key)
					swap(q[s], q[left]);
				break;
			}
			else
				break;
	}
}

void pop(queue* q)
{
	q[1] = q[size--];
	down_queue(q);
}

void push(queue* q, int key)			// key
{
	q[++size].key = key;
	up_queue(q);
}
*/

void search(int high)
{

}

int main(void)
{
	 std::ios::sync_with_stdio(false);

	 cin >> size;

//	 int** arr;
//	 arr = new int*[size];
//
//	 for(int i = 0 ; i < size ; ++i)
//		 arr[i] = new int[size];
//
//	 for(int i = 0 ; i < size ; ++i)
//		 for(int j = 0 ; j < size ; ++j)
//			 cin >> arr[i][j];
//
//	 for(int i = 0 ; i < size ; ++i)
//	 {
//		 for(int j = 0 ; j < size ; ++j)
//			 cout << arr[i][j] << " ";
//		 cout << endl;
//	 }

	 array** arr;
	 arr = new array*[size];

	 for(int i = 0 ; i < size ; ++i)
	 {
		 arr[i] = new array[4];
	 }

	 for(int i = 0 ; i < size ; ++i)
		 for(int j = 0 ; j < 4 ; ++j)
		 {
			 arr[i][j].checked = false;
			 cin >> arr[i][j].key;
		 }

	 cout << size << endl;

	 for(int i = 0 ; i < size ; ++i)
	 {
		 for(int j = 0 ; j < 4 ; ++j)
			 cout << arr[i][j].key << " ";
		 cout << endl;
	 }


	 queue* que;
	 que = new queue[size];


}


