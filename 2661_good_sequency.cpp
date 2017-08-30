#include<cstdio>
#include<algorithm>

using namespace std;

int n, a[85];

void dfs(int cnt) 
{
	for (int i = 1; i <= cnt / 2; i++) 
    {
		if (equal(a + cnt - i, a + cnt, a + cnt - (i*2))) 
            return;
	}

	if (cnt == n) 
    {
		for (int i = 0; i < n; i++) 
            printf("%d", a[i]);
		
        exit(0);
	}

	for (int i = 1; i <= 3; i++) 
    {
		a[cnt] = i;
		dfs(cnt + 1);
	}
}

int main()
{
	scanf("%d", &n);

	dfs(0);

	return 0;
}