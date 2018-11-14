#include <iostream>
#include <cstdio>

using namespace std;

typedef struct checkpoint
{
    int x, y;
} _CHECKPOINT;

int N, Q;
int segTree[400005];
int inTer[300005];
_CHECKPOINT checkPoint[100005];

inline int Max(int a, int b) { return a > b ? a : b; }

int getDist(int a, int b)
{
    int x1 = checkPoint[a].x, x2 = checkPoint[b].x;
    int y1 = checkPoint[a].y, y2 = checkPoint[b].y;
    int x = x1 - x2, y = y1 - y2;
    x < 0 ? x *= -1 : x;
    y < 0 ? y *= -1 : y;
    return x + y;
}

void build(int now, int s, int e)
{
    if (s == e)
    {
        if (s < N)
            segTree[now] = getDist(s, s + 1);
        else
            segTree[now] = 0;
        if (s < N - 1)
            inTer[now] = getDist(s, s + 1) + getDist(s + 1, s + 2) - getDist(s, s + 2);
        else
            inTer[now] = 0;
        return;
    }
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    build(lch, s, m);
    build(rch, m + 1, e);
    segTree[now] = segTree[lch] + segTree[rch];
    inTer[now] = Max(inTer[lch], inTer[rch]);
}

int queryDist(int now, int s, int e, int fs, int fe)
{
    if (e < fs || fe < s)
        return 0;
    if (fs <= s && e <= fe)
        return segTree[now];
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    int lid = queryDist(lch, s, m, fs, fe);
    int rid = queryDist(rch, m + 1, e, fs, fe);
    return lid + rid;
}
int queryInter(int now, int s, int e, int fs, int fe)
{
    if (e < fs || fe < s)
        return 0;
    if (fs <= s && e <= fe)
        return inTer[now];
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    int lid = queryInter(lch, s, m, fs, fe);
    int rid = queryInter(rch, m + 1, e, fs, fe);
    return Max(lid, rid);
}

void updateCheck(int now, int s, int e, int idx)
{
    if (s == e)
    {
        if (s > 0 && s < N)
            segTree[now] = getDist(s, s + 1);
        else
            segTree[now] = 0;
        return;
    }
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    if (idx <= m)
        updateCheck(lch, s, m, idx);
    else
        updateCheck(rch, m + 1, e, idx);
    segTree[now] = segTree[lch] + segTree[rch];
}

void updateInter(int now, int s, int e, int idx)
{
    if (s == e)
    {
        if (s > 0 && s < N - 1)
            inTer[now] = getDist(s, s + 1) + getDist(s + 1, s + 2) - getDist(s, s + 2);
        else
            inTer[now] = 0;
        return;
    }
    int lch = now * 2, rch = lch + 1, m = (s + e) / 2;
    if (idx <= m)
        updateInter(lch, s, m, idx);
    else
        updateInter(rch, m + 1, e, idx);
    inTer[now] = Max(inTer[lch], inTer[rch]);
}

int main()
{
    scanf("%d %d", &N, &Q);

    for (int i = 1; i <= N; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        checkPoint[i].x = x;
        checkPoint[i].y = y;
    }

    build(1, 1, N);

    char c;
    int x, y, iter;
    for (int i = 0; i < Q; ++i)
    {
        scanf(" %c", &c);

        if (c == 'Q')
        {
            scanf("%d %d", &x, &y);

            int total = queryDist(1, 1, N, x, y - 1);
            int inter = queryInter(1, 1, N, x, y - 2);
            printf("%d\n", total - inter);
        }
        else if (c == 'U')
        {
            scanf("%d %d %d", &iter, &x, &y);
            checkPoint[iter].x = x;
            checkPoint[iter].y = y;
            updateCheck(1, 1, N, iter - 1);
            updateCheck(1, 1, N, iter);
            updateInter(1, 1, N, iter - 2);
            updateInter(1, 1, N, iter - 1);
            updateInter(1, 1, N, iter);
        }
    }

    return 0;
}