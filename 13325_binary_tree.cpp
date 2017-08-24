#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int k, a[1 << 21], r, i, t;

int main()
{
    scanf("%d", &k);

    for (i = 2; i < 1 << k + 1; i++)
    {
        scanf("%d", a + i);
    }

    while (i -= 2)
    {
        t = max(a[i], a[i + 1]);
        r += t;
        a[i / 2] += t;
    }

    printf("%d", r + t);

    return 0;
}