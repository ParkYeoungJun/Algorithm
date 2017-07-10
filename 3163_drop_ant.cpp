#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

const int INF = 987654321;

int N, L, K;
vector<pair<int, int> > ant_s;
vector<pair<int, int> > ant;
vector<pair<int, int> > res;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	int A = a.second > 0 ? L - a.first : a.first;
	int B = b.second > 0 ? L - b.first : b.first;
	
	if (A == B)
		return abs(a.second)<abs(b.second);
	else
		return A<B;
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--) {

		scanf("%d%d%d", &N, &L, &K);

		ant_s = vector<pair<int, int> >(N);
		ant = vector<pair<int, int> >(N);
		res = vector<pair<int, int> >();

		for (int i = 0; i < N; ++i) {

			scanf("%d%d", &ant_s[i].first, &ant_s[i].second);

			ant[i].first = ant_s[i].first;
			ant[i].second = ant_s[i].second;

		}

		sort(ant_s.begin(), ant_s.end(), cmp);

		cout << endl;
		for (int i = 0; i < ant_s.size(); ++i)
			cout << "v : " << ant_s[i].first << " " << ant_s[i].second << endl;
		cout << endl;

		int left = 0;
		int right = N - 1;

		for (int i = 0; i < N; ++i) {

			int ans = 0;
			int dis = ant_s[i].second > 0 ? L - ant_s[i].first : ant_s[i].first;

			if (ant_s[i].second > 0) {
				ans = ant[right--].second;
			}
			else 
			{
				ans = ant[left++].second;
			}

			res.push_back(make_pair(dis, ans));

		}

		
		sort(res.begin(), res.end());

		printf("%d\n", res[K-1].second);

	}

	return 0;
}
