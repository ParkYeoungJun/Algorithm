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
		cout << s << endl;
		cout << mheap[s/2].key << " " << mheap[s].key << endl;
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
	heap* mheap = new heap[5];

	push(mheap, 20, 1, 2);
	push(mheap, 10, 2, 3);
	push(mheap, 30, 1, 2);
	push(mheap, 1, 5, 5);

	cout << mheap[1].key << endl;

	for(int i = 0 ; i < 5 ; ++i)
		cout << mheap[i].key << " ";

	pop(mheap);

	cout << mheap[1].rotate[1] << endl;

	cout << size;
}
