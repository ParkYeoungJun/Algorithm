#include<iostream>
#include<cstdio>
#include<queue>
#include<string.h>

using namespace std;

#define MAX_NUM 1005

queue <int> q;

int t[MAX_NUM];
int line[MAX_NUM][MAX_NUM];
int in_num[MAX_NUM];  
int dp[MAX_NUM]; 

int T;
int N, K, W;

int func() {

	while (!q.empty()) {
		int temp = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (line[temp][i] == 1 && in_num[i] != 0) { 

				in_num[i]--;

				if (in_num[i] == 0) {  
					for (int j = 1; j <= N; j++) {
						if (line[j][i] == 1) {
							if (dp[i] < dp[j] + t[i]) {
								dp[i] = dp[j] + t[i];
							}
						}
					}

					q.push(i);
				}
			}
		}
	}
}


int main()
{

	int start, end;

	scanf("%d", &T);

	while(T--){

		memset(t, 0, sizeof(t));
		memset(in_num, 0, sizeof(in_num));
		memset(dp, 0, sizeof(dp));
		memset(line, 0, sizeof(line));

		scanf("%d%d", &N, &K);
  
		for (int i = 1; i <= N; i++) {
			scanf("%d", &t[i]);
		}

		for (int i = 0; i<K; i++) {
			scanf("%d%d", &start, &end);
			if (line[start][end] == 1) continue;
			line[start][end] = 1;
			in_num[end] ++;
		}

		scanf("%d", &W);

		for (int i = 1; i <= N; i++) {
			if (in_num[i] == 0) {
				q.push(i);
			}
			dp[i] = t[i];
		}

		func();

		printf("%d\n", dp[W]);

	}

	return 0;

}