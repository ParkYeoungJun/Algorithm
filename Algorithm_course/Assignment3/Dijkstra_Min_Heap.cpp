#include<iostream>

using namespace std;

int size;

typedef struct
{
	int key;
	int rotate[2];
}heap;

void up_heap(heap* mheap)
{
	int s = size;
	while(s > 1)
	{
		if(mheap[s/2].key > mheap[s].key)
		{
			swap(mheap[s/2], mheap[s]);
			s /= 2;
		}
		else
			break;
	}
}

void down_heap(heap* mheap)
{
	int s = 1, left, right, smaller;

	while(true)
	{
		left = s*2;
		right = s*2+1;

		 if (right <= size)
		 {
			 smaller = (mheap[left].key < mheap[right].key)? left : right;

			 if (mheap[s].key > mheap[smaller].key)
			 {
				 swap(mheap[s], mheap[smaller]);
				 s = smaller;
			 }
			 else
			 {
				 break;
			 }
		 }
		 else if (left == size)
		 {
			 if (mheap[s].key > mheap[left].key)
				 swap(mheap[s], mheap[left]);
			 break;
		 }
		 else
		 {
			 break;
		 }
	}
}

void pop(heap* mheap)
{
	mheap[1] = mheap[size--];
	down_heap(mheap);
}

void push(heap* mheap, int key, int a, int b)
{
	mheap[++size].key = key;
	mheap[size].rotate[0] = a;
	mheap[size].rotate[1] = b;
	up_heap(mheap);
}

int main(void)
{
	std::ios::sync_with_stdio(false);

	int size_c;
	int size_r;

	cin >> size_c;
	cin >> size_r;

	int** bax;
	int** check;

	bax = new int*[size_c];
	check = new int*[size_c];

	for(int i = 0 ; i < size_c ; ++i)
	{
		bax[i] = new int[size_r];
		check[i] = new int[size_r];
	}

	for(int i = 0 ; i < size_c ; ++i)
		for(int j = 0 ; j < size_r ; ++j)
		{
			cin >> bax[i][j];
		}

	int* start;
	start = new int[2];

	cin >> start[0] >> start[1];
	--start[0];
	--start[1];

	int* finish;
	finish = new int[2];

	cin >> finish[0] >> finish[1];
	--finish[0];
	--finish[1];

	check[start[0]][start[1]] = 2;

	int* state;
	state = new int[2];
	state[0] = start[0];
	state[1] = start[1];

	heap* mheap = new heap[size_c*size_r+1];

	while(check[finish[0]][finish[1]] != 2)
	{
		if(state[0] > 0 && state[0] < size_c-1 && state[1] > 0 && state[1] < size_r-1)
		{
			if(check[state[0]+1][state[1]] == 0)
			{
				bax[state[0]+1][state[1]] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]+1][state[1]],state[0]+1,state[1]);
				check[state[0]+1][state[1]] = 1;
			}
			if(check[state[0]][state[1]+1] == 0)
			{
				bax[state[0]][state[1]+1] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]][state[1]+1],state[0],state[1]+1);
				check[state[0]][state[1]+1] = 1;
			}
			if(check[state[0]-1][state[1]] == 0)
			{
				bax[state[0]-1][state[1]] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]-1][state[1]],state[0]-1,state[1]);
				check[state[0]-1][state[1]] = 1;
			}
			if(check[state[0]][state[1]-1] == 0)
			{
				bax[state[0]][state[1]-1] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]][state[1]-1],state[0],state[1]-1);
				check[state[0]][state[1]-1] = 1;
			}
		}
		else if(state[0] > 0 && state[0] < size_c-1 && state[1] == 0)
		{
			if(check[state[0]+1][state[1]] == 0)
			{
				bax[state[0]+1][state[1]] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]+1][state[1]],state[0]+1,state[1]);
				check[state[0]+1][state[1]] = 1;
			}
			if(check[state[0]][state[1]+1] == 0)
			{
				bax[state[0]][state[1]+1] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]][state[1]+1],state[0],state[1]+1);
				check[state[0]][state[1]+1] = 1;
			}
			if(check[state[0]-1][state[1]] == 0)
			{
				bax[state[0]-1][state[1]] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]-1][state[1]],state[0]-1,state[1]);
				check[state[0]-1][state[1]] = 1;
			}
		}
		else if(state[0] > 0 && state[0] < size_c-1 && state[1] == size_r-1)
		{
			if(check[state[0]-1][state[1]] == 0)
			{
				bax[state[0]-1][state[1]] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]-1][state[1]],state[0]-1,state[1]);
				check[state[0]-1][state[1]] = 1;
			}
			if(check[state[0]][state[1]-1] == 0)
			{
				bax[state[0]][state[1]-1] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]][state[1]-1],state[0],state[1]-1);
				check[state[0]][state[1]-1] = 1;
			}
			if(check[state[0]+1][state[1]] == 0)
			{
				bax[state[0]+1][state[1]] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]+1][state[1]],state[0]+1,state[1]);
				check[state[0]+1][state[1]] = 1;
			}
		}
		else if(state[0] == 0 && state[1] > 0 && state[1] < size_r-1)
		{
			if(check[state[0]+1][state[1]] == 0)
			{
				bax[state[0]+1][state[1]] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]+1][state[1]],state[0]+1,state[1]);
				check[state[0]+1][state[1]] = 1;
			}
			if(check[state[0]][state[1]+1] == 0)
			{
				bax[state[0]][state[1]+1] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]][state[1]+1],state[0],state[1]+1);
				check[state[0]][state[1]+1] = 1;
			}
			if(check[state[0]][state[1]-1] == 0)
			{
				bax[state[0]][state[1]-1] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]][state[1]-1],state[0],state[1]-1);
				check[state[0]][state[1]-1] = 1;
			}
		}
		else if(state[0] == size_c-1 && state[1] > 0 && state[1] < size_r-1)
		{
			if(check[state[0]-1][state[1]] == 0)
			{
				bax[state[0]-1][state[1]] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]-1][state[1]],state[0]-1,state[1]);
				check[state[0]-1][state[1]] = 1;
			}
			if(check[state[0]][state[1]-1] == 0)
			{
				bax[state[0]][state[1]-1] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]][state[1]-1],state[0],state[1]-1);
				check[state[0]][state[1]-1] = 1;
			}
			if(check[state[0]][state[1]+1] == 0)
			{
				bax[state[0]][state[1]+1] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]][state[1]+1],state[0],state[1]+1);
				check[state[0]][state[1]+1] = 1;
			}
		}
		else if(state[0] == 0 && state[1] == 0)
		{
			if(check[state[0]+1][state[1]] == 0)
			{
				bax[state[0]+1][state[1]] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]+1][state[1]],state[0]+1,state[1]);
				check[state[0]+1][state[1]] = 1;
			}
			if(check[state[0]][state[1]+1] == 0)
			{
				bax[state[0]][state[1]+1] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]][state[1]+1],state[0],state[1]+1);
				check[state[0]][state[1]+1] = 1;
			}
		}
		else if(state[0] == 0 && state[1] == size_r-1)
		{
			if(check[state[0]][state[1]-1] == 0)
			{
				bax[state[0]][state[1]-1] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]][state[1]-1],state[0],state[1]-1);
				check[state[0]][state[1]-1] = 1;
			}
			if(check[state[0]+1][state[1]] == 0)
			{
				bax[state[0]+1][state[1]] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]+1][state[1]],state[0]+1,state[1]);
				check[state[0]+1][state[1]] = 1;
			}
		}
		else if(state[0] == size_c-1 && state[1] == 0)
		{
			if(check[state[0]][state[1]+1] == 0)
			{
				bax[state[0]][state[1]+1] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]][state[1]+1],state[0],state[1]+1);
				check[state[0]][state[1]+1] = 1;
			}
			if(check[state[0]-1][state[1]] == 0)
			{
				bax[state[0]-1][state[1]] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]-1][state[1]],state[0]-1,state[1]);
				check[state[0]-1][state[1]] = 1;
			}
		}
		else if(state[0] == size_c-1 && state[1] == size_r-1)
		{
			if(check[state[0]-1][state[1]] == 0)
			{
				bax[state[0]-1][state[1]] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]-1][state[1]],state[0]-1,state[1]);
				check[state[0]-1][state[1]] = 1;
			}
			if(check[state[0]][state[1]-1] == 0)
			{
				bax[state[0]][state[1]-1] += bax[state[0]][state[1]];
				push(mheap,bax[state[0]][state[1]-1],state[0],state[1]-1);
				check[state[0]][state[1]-1] = 1;
			}
		}

		state[0] = mheap[1].rotate[0];
		state[1] = mheap[1].rotate[1];

		check[state[0]][state[1]] = 2;

		pop(mheap);
	}

	cout << bax[finish[0]][finish[1]];
}
