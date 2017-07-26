#include <iostream>
#include <cstdio>

using namespace std;

typedef struct tree
{
    char left;
    char right;
} tree;

int n;
tree arr[105];

void preorder(int t)
{
    if (t >= 'A')
    {
        printf("%c", t);
        preorder(arr[t].left);
        preorder(arr[t].right);
    }
}

void inorder(int t)
{
    if (t >= 'A')
    {
        inorder(arr[t].left);
        printf("%c", t);
        inorder(arr[t].right);
    }
}

void postorder(int t)
{
    if (t >= 'A')
    {
        postorder(arr[t].left);
        postorder(arr[t].right);
        printf("%c", t);
    }
}

int main()
{
    scanf("%d", &n);

    cin.ignore();

    for (int i = 0; i < n; ++i)
    {
        char a, b, c;

        scanf("%c %c %c", &a, &b, &c);

        arr[a].left = b;
        arr[a].right = c;

        cin.ignore();    
    }

    preorder('A');
    printf("\n");
    inorder('A');
    printf("\n");
    postorder('A');

    return 0;
}