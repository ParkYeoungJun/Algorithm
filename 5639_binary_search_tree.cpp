#include<iostream>
#include<cstdio>

using namespace std;

typedef struct
{
    int first;
    int second;
} t;

t tree[1000005];

void post(int x)
{
    if (tree[x].first != 0)
        post(tree[x].first);
    if (tree[x].second != 0)
        post(tree[x].second);

    printf("%d\n", x);
}

int main()
{

    int root, in;

    scanf("%d", &root);

    while (scanf("%d", &in) == 1)
    {
        int node = root;

        while (1)
        {
            if (node < in)
            { 
                if (tree[node].second != 0)
                {
                    node = tree[node].second;
                }
                else
                {
                    tree[node].second = in;
                    break;
                }
            }
            else
            {
                if (tree[node].first != 0)
                {
                    node = tree[node].first;
                }
                else
                {
                    tree[node].first = in;
                    break;
                }
            }
        }
    }

    post(root);
}