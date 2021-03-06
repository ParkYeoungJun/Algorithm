/*
 * t.cpp
 *
 *  Created on: 2015. 12. 6.
 *      Author: Park
 */
#include<iostream>
#include<string.h>

using namespace std;

int size;
int size_h = 0;

int best;

typedef struct
{
    int value;
    int bound;
    int level;
    int* checked;
}node;

typedef struct
{
    node node_;
}queue;

void up_queue(queue* q)
{
    int s = size_h;
    while(s > 1)
    {
        if(q[s/2].node_.bound < q[s].node_.bound)
        {
            swap(q[s/2], q[s]);
            s/=2;
        }
        else
            break;
    }
}

void down_queue(queue* q)
{
    int s = 1, left, right, more;

    while(true)
    {
        left = s*2;
        right = s*2+1;

        if(right <= size_h)
        {
            more = (q[left].node_.bound > q[right].node_.bound) ? left:right;

            if(q[s].node_.bound < q[more].node_.bound)
            {
                swap(q[s], q[more]);
                s = more;
            }
            else
                break;
        }
        else if(left == size_h)
        {
            if(q[s].node_.bound < q[left].node_.bound)
                swap(q[s], q[left]);
            break;
        }
        else
            break;
    }
}

void pop(queue* q)
{
    q[1] = q[size_h--];
    down_queue(q);
}

void push(queue* q, node node)
{
    q[++size_h].node_ = node;
    up_queue(q);
}

node top(queue* q)
{
    return q[1].node_;
}

int value(int** arr, node node)
{
    int result = 0;

    for(int i = 0 ; i < node.level ; ++i)
    {
        for(int j = 0 ; j < size ; ++j)
        {
            if(node.checked[i] == j+1)
            {
                result += arr[i][j];
                break;
            }
        }
    }

    return result;
}

int bound(int** arr, node node)
{
    int result = node.value;

    int level = node.level;

    int* che;
    che = new int[size];

    memcpy(che, node.checked, size*sizeof(int));

    for(int i = level ; i < size ; ++i)
    {
        int in = 0;
        int* max;
        max = new int[2];
        max[0] = -1;

        for(int j = 0 ; j < size ; ++j)
        {

            bool whe = false;

            for(int k = 0 ; k < size ; ++k)
            {
                if(che[k] == 0)
                    break;
                else if(che[k] == j+1)
                {
                    whe = true;
                    break;
                }
            }

            if(whe == false)
            {
                 if(max[0] < arr[i][j])
                 {
                     max[0] = arr[i][j];
                     max[1] = j+1;
                 }
            }
        }

        for(int z = 0 ; z < size ; ++z)
        {
            if(che[z] == 0)
            {
                che[z] = max[1];
                break;
            }
        }

        result += max[0];
    }


    return result;
}

int main(void)
{
     std::ios::sync_with_stdio(false);

     cin >> size;

     int** arr;
     arr = new int*[size];

     for(int i = 0 ; i < size ; ++i)
     {
         arr[i] = new int[size];
     }

     for(int i = 0 ; i < size ; ++i)
         for(int j = 0 ; j < size ; ++j)
         {

             cin >> arr[i][j];
         }



     best = -1;

     node u,v;

     u.level = 0;
     u.value = 0;
     u.checked = new int[size];

     queue* que;
     que = new queue[size*size];

     for(int i = 0 ; i < size ; ++i)
     {
         node nod;

         nod.level = 1;
         nod.checked = new int[size];
         nod.checked[0] = i+1;
         nod.value = value(arr, nod);
         nod.bound = bound(arr, nod);

         if(best < nod.bound)
             best = nod.bound;

         push(que, nod);
     }

     int count = 0;

         int* to;
         to = new int[size];

         for(int j = 1 ; j < size ; ++j)
         {

         memcpy(to, que[1].node_.checked, size*sizeof(int));

         pop(que);

         for(int i = 0 ; i < size ; ++i)
         {
             node nod;

             bool whe = false;

             for(int k = 0 ; k < size ; ++k)
                 if(to[k] == 0)
                     break;
                 else if(to[k] == i+1)
                     whe = true;


             if(whe == false)
             {
                 nod.level = j+1;
                 nod.checked = new int[size];
                 memcpy(nod.checked, to, size*sizeof(int));
                 nod.checked[nod.level-1] = i+1;
                 nod.value = value(arr, nod);
                 nod.bound = bound(arr, nod);

                 if(best <= nod.bound)
                 {
                     best = nod.bound;
                     push(que, nod);
                 }
             }
            }
         }

         cout << que[1].node_.bound << endl;

         for(int i = 0 ; i < size ; ++i)
             cout << que[1].node_.checked[i] << " ";

         count++;
}
