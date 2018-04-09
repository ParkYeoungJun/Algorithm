#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int ai[25];
int bj[25];

pair<int, int> avisit[25];
pair<int, int> bvisit[25];

pair<int, int> visit[1005];

queue<int> awaiting;
queue<int> bwaiting;

vector<pair<int, int> > ti;

vector<bool> done;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int t = 1, testcase, res = 0;

    scanf("%d", &testcase);

    while (testcase--)
    {
        ti.clear();
        res = 0;
        done.clear();
        memset(visit, 0, sizeof(visit));
        memset(avisit, 0, sizeof(avisit));
        memset(bvisit, 0, sizeof(bvisit));

        int n, m, k, a, b;
        scanf("%d %d %d %d %d", &n, &m, &k, &a, &b);

        for (int i = 1; i <= n; ++i)
            scanf("%d", &ai[i]);
        for (int i = 1; i <= m; ++i)
            scanf("%d", &bj[i]);
        for (int i = 1; i <= k; ++i)
        {
            int tmp;
            scanf("%d", &tmp);

            ti.push_back(make_pair(i, tmp));
        }

        // sort(ti.begin(), ti.end(), compare);

        int time = 0, to = 0;
        while (done.size() < k)
        {
            for (; to < ti.size(); ++to)
                if (ti[to].second == time)
                    awaiting.push(ti[to].first);
                else if (ti[to].second > time)
                    break;

            if (!awaiting.empty())
            {
                for (int i = 1; i <= n; ++i)
                {
                    if (avisit[i].second == 0)
                    {
                        int tmp = awaiting.front();
                        avisit[i] = make_pair(tmp, ai[i]);
                        awaiting.pop();

                        visit[tmp].first = i;
                    }

                    if (awaiting.empty())
                        break;
                }
            }

            time++;

            for (int i = 1; i <= n; ++i)
            {
                if (avisit[i].second > 0)
                {
                    avisit[i].second--;

                    if (avisit[i].second == 0)
                    {
                        bwaiting.push(avisit[i].first);
                    }
                }
            }

            if (!bwaiting.empty())
            {
                for (int i = 1; i <= m; ++i)
                {
                    if (bvisit[i].second == 0)
                    {
                        int tmp = bwaiting.front();
                        bvisit[i] = make_pair(tmp, bj[i]);
                        bwaiting.pop();

                        visit[tmp].second = i;
                    }

                    if (bwaiting.empty())
                        break;
                }
            }

            for (int i = 1; i <= m; ++i)
            {
                if (bvisit[i].second > 0)
                {
                    bvisit[i].second--;

                    if(bvisit[i].second == 0)
                        done.push_back(true);
                }
            }


            // cout << "time : " << time << endl;
            // for (int i = 1; i <= k; ++i)
            // {
            //     cout << "i : " << i << " " << visit[i].first << " " << visit[i].second << endl;
            // }
            // cout << endl;
        }

        for (int i = 1; i <= k; ++i)
        {
            if(visit[i].first == a && visit[i].second == b)
                res+=i;
        }
        if(res == 0)
            res = -1;

        printf("#%d %d\n", t++, res);
    }

    return 0;
}