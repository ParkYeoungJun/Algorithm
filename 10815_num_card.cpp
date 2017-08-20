#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long a[500005];
long long b[500005];

bool search(long long left, long long right, long long searchNum)
{
    long long mid = (left + right) / 2;

    bool result = false;

    if (left > right)
        return false;
    else
    {
        if (a[mid] > searchNum)
        {
            result = search(left, mid - 1, searchNum);
        }
        else if (a[mid] < searchNum)
        {
            result = search(mid + 1, right, searchNum);
        }
        else
        {
            return true;
        }

        return result;
    }
}

int main()
{
    int n, m;

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    scanf("%d", &m);

    for (int i = 0; i < m; ++i)
        scanf("%d", &b[i]);

    sort(a, a + n);

    for (int i = 0; i < m; ++i)
    {
        if (search(0, n - 1, b[i]))
            printf("1\n");
        else
            printf("0\n");
    }

    return 0;
}